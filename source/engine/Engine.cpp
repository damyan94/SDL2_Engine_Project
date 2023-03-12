// Corresponding header
#include "engine/Engine.h"

// C/C++ system includes
#include <thread>

// Third-party includes

// Own includes
#include "defines/consts/GlobalConstants.h"

#include "utils/UtilsCommonIncludes.h"

#include "sdl_utils/SDLUtilsCommonIncludes.h"

#include "managers/ManagersDefines.h"
#include "managers/ManagerHandler.h"

#include "engine/config/EngineConfig.h"

#include "app/App.h"

#include "sdl_utils/Window.h"
#include "sdl_utils/Renderer.h"

#define RUN_OPTIMIZED 0
#define MIN_TIME_BETWEEN_UPDATE 500

// =============================================================================
Engine::Engine()
	: m_ManagerHandler(nullptr)
	, m_App(nullptr)
	, m_DrawTimerId(0)
	, m_ElapsedTime(0)
	, m_CurrFPS(0)
{
}

// =============================================================================
Engine::~Engine()
{
	SafeDelete(m_App);
	SafeDelete(m_ManagerHandler);
}

// =============================================================================
bool Engine::Init(const EngineConfig& cfg)
{
	srand((uint32_t)time(nullptr));

	m_ManagerHandler = new ManagerHandler;
	m_App = new App;

	AssertReturnIf(!m_ManagerHandler, false, "Failed to allocate memory.");
	AssertReturnIf(!m_App, false, "Failed to allocate memory.");

	ReturnIf(!m_InputEvent.Init(), false);
	ReturnIf(!m_ManagerHandler->Init(cfg.m_ManagerHandlerConfig) , false);
	ReturnIf(!m_App->Init(), false);

	Timer::StartGlobalTimer();
	m_DrawTimerId = Timer::StartTimer(MIN_TIME_BETWEEN_UPDATE, ETimerType::Pulse);

	return true;
}

// =============================================================================
void Engine::Deinit()
{
	m_App->Deinit();
	m_ManagerHandler->Deinit();
	m_InputEvent.Deinit();
}

// =============================================================================
void Engine::HandleEvent()
{
	m_App->HandleEvent(m_InputEvent);
	m_ManagerHandler->HandleEvent(m_InputEvent);
}

// =============================================================================
void Engine::Update()
{
	m_App->Update(m_ElapsedTime);
	m_ManagerHandler->Update(m_ElapsedTime);
}

// =============================================================================
void Engine::Draw() const
{
	m_App->Draw();
	m_ManagerHandler->Draw();
}

// =============================================================================
void Engine::RunApplication()
{
	Time clock;

#if RUN_OPTIMIZED > 0
	bool drawConditionAchieved = false;
	bool drawTimerTicked = false;
#endif // !RUN_OPTIMIZED

	Update();
	Draw();

	bool running = true;
	while (running)
	{
		while (m_InputEvent.PollEvent())
		{
			if (m_InputEvent.m_Type == EEventType::Quit)
			{
				running = false;
			}

			HandleEvent();
		}

		Timer::UpdateTimers();
		Update();

#if RUN_OPTIMIZED == 0
		Draw();

#elif RUN_OPTIMIZED == 1
		drawConditionAchieved =
			m_InputEvent.m_Type == EEventType::MouseButtondown || m_InputEvent.m_Type == EEventType::MouseButtonUp ||
			m_InputEvent.m_Type == EEventType::KeyboardPress || m_InputEvent.m_Type == EEventType::KeyboardRelease;

		drawTimerTicked = Timer::IsActiveTimer(m_DrawTimerId) && !Timer::IsTimerPaused(m_DrawTimerId)
			&& Timer::IsTimerTicked(m_DrawTimerId);

		if (drawConditionAchieved || drawTimerTicked)
		{
			Draw();
		}

		drawConditionAchieved = false;
		m_InputEvent.m_Type = EEventType::Unknown;

#else
#error Error, invalid engine draw optimization.
#endif // !RUN_OPTIMIZED

		m_ElapsedTime = (int32_t)clock.GetElapsedTimeLastCall(EUnitOfTime::Milliseconds);
		Sleep(m_ElapsedTime);
		clock.ResetToNow();
	}
}

// =============================================================================
void Engine::Sleep(int32_t elapsedTime)
{
	int32_t totalFrameTime = elapsedTime;
	auto sleepTime = std::chrono::milliseconds(EngineConstants::TIME_PER_FRAME - elapsedTime);
	if (sleepTime.count() > 0)
	{
		std::this_thread::sleep_for(sleepTime);
		totalFrameTime += sleepTime.count();
	}

	if (totalFrameTime > 0)
	{
		m_CurrFPS = 1000 / totalFrameTime;
	}
}