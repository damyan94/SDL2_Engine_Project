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

#include "managers/DrawManager.h"
#include "managers/AssetManager.h"
#include "managers/AudioManager.h"
#include "managers/TimerManager.h"
#include "managers/ImGuiManager.h"
#include "engine/settings/Settings.h"

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
	SafeDelete(g_ImGuiManager);
	SafeDelete(g_TimerManager);
	SafeDelete(g_AudioManager);
	SafeDelete(g_AssetManager);
	SafeDelete(g_DrawManager);
}

// =============================================================================
bool Engine::Init(const EngineConfig& cfg)
{
	srand((uint32_t)time(nullptr));

	ReturnIf(!g_Settings->Read(), false);

	ReturnIf(!SDLLoader::Init(), false);
	ReturnIf(!m_InputEvent.Init(), false);

	g_DrawManager = new DrawManager;
	g_AssetManager = new AssetManager;
	g_AudioManager = new AudioManager;
	g_TimerManager = new TimerManager;
	g_ImGuiManager = new ImGuiManager;

	AssertReturnIf(!g_DrawManager, false, "Failed to allocate memory.");
	AssertReturnIf(!g_AssetManager, false, "Failed to allocate memory.");
	AssertReturnIf(!g_AudioManager, false, "Failed to allocate memory.");
	AssertReturnIf(!g_TimerManager, false, "Failed to allocate memory.");
	AssertReturnIf(!g_ImGuiManager, false, "Failed to allocate memory.");

	ReturnIf(!g_DrawManager->Init(cfg.m_DrawManagerConfig), false);
	ReturnIf(!g_AssetManager->Init(cfg.m_AssetManagerConfig), false);
	ReturnIf(!g_AudioManager->Init(cfg.m_AudioManagerConfig), false);
	ReturnIf(!g_TimerManager->Init(cfg.m_TimerManagerConfig), false);
	ReturnIf(!g_ImGuiManager->Init(cfg.m_ImGuiManagerConfig), false);

	ReturnIf(!m_App.Init(cfg.m_AppConfig), false);

	m_TargetFPS = g_Settings->GetTargetFPS();

	return true;
}

// =============================================================================
void Engine::Deinit()
{
	SDLLoader::Deinit();

	g_Settings->Write();
}

// =============================================================================
void Engine::HandleEvent()
{
	g_DrawManager->HandleEvent(m_InputEvent);
	g_ImGuiManager->HandleEvent(m_InputEvent);
	m_App.HandleEvent(m_InputEvent);

	if (m_InputEvent.m_Key == EKeyboardKey::E && m_InputEvent.m_Type == EEventType::KeyboardPress)
	{
		g_AssetManager->ChangeLanguage(ELanguage::EN);
	}
	else if (m_InputEvent.m_Key == EKeyboardKey::R && m_InputEvent.m_Type == EEventType::KeyboardPress)
	{
		g_AssetManager->ChangeLanguage(ELanguage::BG);
	}
}

// =============================================================================
void Engine::Update()
{
	g_TimerManager->Update(m_ElapsedTimeMS);
	m_App.Update(m_ElapsedTimeMS < 100
		? m_ElapsedTimeMS
		: m_ElapsedTimeMS = 1000 / m_TargetFPS);
}

// =============================================================================
void Engine::Draw() const
{
	g_DrawManager->ClearScreen();

	m_App.Draw();
	g_ImGuiManager->Draw();

	g_DrawManager->FinishFrame();
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