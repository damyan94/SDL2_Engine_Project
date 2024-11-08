#include "stdafx.h"

#include "Application/Application/Application.h"
#include "Application/Application/config/ApplicationConfig.h"

#include "system/sdl_utils/SDLLoader.h"

//TODO maybe wrap all this in a System.h and have a similar API to the engine
#include "system/managers/DrawManager.h"
#include "system/managers/AssetManager.h"
#include "system/managers/AudioManager.h"
#include "system/managers/TimerManager.h"
#include "system/managers/ImGuiManager.h"
#include "Application/Application/settings/Settings.h"
#include "Application/Game/Game.h"

#include <thread>

static constexpr int32_t c_MaxDelayBetweenFrames = 100;

////////////////////////////////////////////////////////////////////////////////
Application::Application()
	: m_ElapsedTimeMS(0)
	, m_TargetFPS(0)
	, m_TargetTimePerFrame(0)
{
}

////////////////////////////////////////////////////////////////////////////////
Application::~Application()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Application::Init(const ApplicationConfig& cfg)
{
	srand((uint32_t)time(nullptr));

	ReturnIf(!g_Settings->Read(), false);

	ReturnIf(!SDLLoader::Init(), false);
	ReturnIf(!m_InputEvent.Init(), false);

	ReturnIf(!TimerManager::Instance().Init(cfg.m_TimerManagerConfig), false);
	ReturnIf(!DrawManager::Instance().Init(cfg.m_DrawManagerConfig), false);
	ReturnIf(!AssetManager::Instance().Init(cfg.m_AssetManagerConfig), false);
	ReturnIf(!AudioManager::Instance().Init(cfg.m_AudioManagerConfig), false);
	ReturnIf(!ImGuiManager::Instance().Init(cfg.m_ImGuiManagerConfig), false);

	ReturnIf(!Game::Instance().Init(cfg.m_AppConfig), false);

	m_TargetFPS = g_Settings->GetTargetFPS();
	m_TargetTimePerFrame = 1000 / m_TargetFPS;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Application::Deinit()
{
	SDLLoader::Deinit();

	g_Settings->Write();
}

////////////////////////////////////////////////////////////////////////////////
void Application::HandleEvent()
{
	DrawManager::Instance().HandleEvent(m_InputEvent);

#ifdef USE_IMGUI
	g_ImGuiManager->HandleEvent(m_InputEvent);
#endif

	Game::Instance().HandleEvent(m_InputEvent);

	//TODO Move this to the settings menu or other appropriate place
	if (m_InputEvent.m_Key == EKeyboardKey::E &&
		m_InputEvent.m_Type == EEventType::KeyboardPress)
	{
		AssetManager::Instance().ChangeLanguage(ELanguage::EN);
		g_Settings->SetLanguage(ELanguage::EN);
	}
	else if (m_InputEvent.m_Key == EKeyboardKey::R &&
		m_InputEvent.m_Type == EEventType::KeyboardPress)
	{
		AssetManager::Instance().ChangeLanguage(ELanguage::BG);
		g_Settings->SetLanguage(ELanguage::BG);
	}
}

////////////////////////////////////////////////////////////////////////////////
void Application::Update()
{
	TimerManager::Instance().Update(m_ElapsedTimeMS);
	DrawManager::Instance().Update(m_ElapsedTimeMS);

	// Handle delays here so that we do not compromise our timers
	Game::Instance().Update(m_ElapsedTimeMS < c_MaxDelayBetweenFrames
		? m_ElapsedTimeMS
		: m_ElapsedTimeMS = m_TargetTimePerFrame);
}

////////////////////////////////////////////////////////////////////////////////
void Application::Draw() const
{
	DrawManager::Instance().ClearScreen();
	DrawManager::Instance().Draw();

#ifdef USE_IMGUI
	g_ImGuiManager->Draw();
#endif

	DrawManager::Instance().FinishFrame();
}


////////////////////////////////////////////////////////////////////////////////
void Application::RunApplication()
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

////////////////////////////////////////////////////////////////////////////////
void Application::Sleep()
{
	const int32_t sleepTime = m_TargetTimePerFrame - m_ElapsedTimeMS;

	if (sleepTime > 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		m_ElapsedTimeMS += sleepTime;
	}
}