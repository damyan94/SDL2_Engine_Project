// Corresponding header
#include "engine/Engine.h"

// C/C++ system includes
#include <thread>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/SDLUtilsCommonIncludes.h"
#include "managers/ManagersDefines.h"
#include "engine/config/EngineConfig.h"
#include "app/App.h"

// =============================================================================
Engine::Engine()
	: m_App(nullptr)
	, m_ElapsedTimeMS(0)
	, m_TargetFPS(0)
{
}

// =============================================================================
Engine::~Engine()
{
	SafeDelete(m_App);
}

// =============================================================================
bool Engine::Init(const EngineConfig& cfg)
{
	srand((uint32_t)time(nullptr));

	ReturnIf(!m_ManagerHandler.Init(cfg.m_ManagerHandlerConfig), false);
	ReturnIf(!m_InputEvent.Init(), false);

	m_App = new App;
	AssertReturnIf(!m_App, false, "Failed to allocate memory.");
	ReturnIf(!m_App->Init(), false);

	m_TargetFPS = 50;

	return true;
}

// =============================================================================
void Engine::Deinit()
{
	m_App->Deinit();
	m_InputEvent.Deinit();
	m_ManagerHandler.Deinit();
}

// =============================================================================
void Engine::HandleEvent()
{
	m_App->HandleEvent(m_InputEvent);
	m_ManagerHandler.HandleEvent(m_InputEvent);
}

// =============================================================================
void Engine::Update()
{
	m_App->Update(m_ElapsedTimeMS);
	m_ManagerHandler.Update(m_ElapsedTimeMS);
}

// =============================================================================
void Engine::Draw() const
{
	m_App->Draw();
	m_ManagerHandler.Draw();
}

// =============================================================================
void Engine::RunApplication()
{
	Time clock;

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

		Update();
		Draw();

		m_ElapsedTimeMS = (int32_t)clock.GetElapsedTimeTillNow(EUnitOfTime::Milliseconds);
		clock.SetToNow();
		Sleep();
	}
}

// =============================================================================
void Engine::Sleep()
{
	const int32_t timePerFrame = 1000 / m_TargetFPS;
	const int32_t sleepTime = timePerFrame - m_ElapsedTimeMS;

	if (sleepTime > 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		m_ElapsedTimeMS += sleepTime;
	}
}