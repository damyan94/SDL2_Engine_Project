// Corresponding header
#include "engine/Engine.h"
#include "engine/config/EngineConfig.h"

// C/C++ system includes
#include <thread>

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"
#include "utils/time/Time.h"
#include "sdl_utils/SDLLoader.h"

// =============================================================================
Engine::Engine()
	: m_ElapsedTimeMS(0)
	, m_TargetFPS(0)
{
}

// =============================================================================
Engine::~Engine()
{
	Deinit();
}

// =============================================================================
bool Engine::Init(const EngineConfig& cfg)
{
	srand((uint32_t)time(nullptr));

	ReturnIf(!SDLLoader::Init(), false);

	ReturnIf(!m_ManagerHandler.Init(cfg.m_ManagerHandlerConfig), false);
	ReturnIf(!m_InputEvent.Init(), false);

	ReturnIf(!m_App.Init(cfg.m_AppConfig), false);

	m_TargetFPS = 50;

	return true;
}

// =============================================================================
void Engine::Deinit()
{
	SDLLoader::Deinit();
}

// =============================================================================
void Engine::HandleEvent()
{
	m_App.HandleEvent(m_InputEvent);
	m_ManagerHandler.HandleEvent(m_InputEvent);
}

// =============================================================================
void Engine::Update()
{
	m_App.Update(m_ElapsedTimeMS);
	m_ManagerHandler.Update(m_ElapsedTimeMS);
}

// =============================================================================
void Engine::Draw() const
{
	m_App.Draw();
	m_ManagerHandler.Draw();
}

// =============================================================================
void Engine::RunApplication()
{
	Time clock;

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