#include "stdafx.h"

#include "Application/Application/Application.h"

#include "System/SDLUtils/SDLLoader.h"
#include "System/Managers/DrawManager.h"
#include "System/Managers/AssetManager.h"
#include "System/Managers/AudioManager.h"
#include "System/Managers/TimerManager.h"
#include "System/Managers/ImGuiManager.h"

#include "Application/ConfigManager.h"
#include "Application/Application/Settings/Settings.h"
#include "Application/Game/Game.h"

//TODO create thread wrapper
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
bool Application::Init()
{
	srand((uint32_t)time(nullptr));
	Logger::Init();

	ReturnIf(!ConfigManager::Instance().Init(), false);
	const auto& cfg = ConfigManager::Instance().GetApplicationConfig();

	ReturnIf(!Settings::Instance().Read(), false);

	ReturnIf(!SDLLoader::Init(), false);
	ReturnIf(!m_InputEvent.Init(), false);

	ReturnIf(!TimerManager::Instance().Init(cfg.TimerManagerConfig), false);
	ReturnIf(!DrawManager::Instance().Init(cfg.DrawManagerConfig), false);
	ReturnIf(!AssetManager::Instance().Init(cfg.AssetManagerConfig), false);
	ReturnIf(!AudioManager::Instance().Init(cfg.AudioManagerConfig), false);
	ReturnIf(!ImGuiManager::Instance().Init(cfg.ImGuiManagerConfig), false);

	ReturnIf(!Game::Instance().Init(cfg.GameConfig), false);

	m_TargetFPS = Settings::Instance().GetTargetFPS();
	m_TargetTimePerFrame = 1000 / m_TargetFPS;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Application::Deinit()
{
	SDLLoader::Deinit();

	Settings::Instance().Write();
}

////////////////////////////////////////////////////////////////////////////////
void Application::HandleEvent()
{
	DrawManager::Instance().HandleEvent(m_InputEvent);

#ifdef USE_IMGUI
	g_ImGuiManager->HandleEvent(m_InputEvent);
#endif

	Game::Instance().HandleEvent(m_InputEvent);

	ReturnIf(m_InputEvent.m_Type != EEventType::KeyboardPress);

	//TODO Move this to the settings menu or other appropriate place
	if (m_InputEvent.m_Key == EKeyboardKey::E)
	{
		AssetManager::Instance().m_TextContainer.ChangeLanguage(ELanguage::EN);
		Settings::Instance().SetLanguage(ELanguage::EN);
	}
	else if (m_InputEvent.m_Key == EKeyboardKey::R)
	{
		AssetManager::Instance().m_TextContainer.ChangeLanguage(ELanguage::BG);
		Settings::Instance().SetLanguage(ELanguage::BG);
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
	Game::Instance().Draw();

#ifdef USE_IMGUI
	g_ImGuiManager->Draw();
#endif

	DrawManager::Instance().FinishFrame();
}


////////////////////////////////////////////////////////////////////////////////
void Application::RunApplication()
{
	Time clock;

	try
	{
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

			m_ElapsedTimeMS = (int32_t)clock.GetElapsedTimeUntilNow(EUnitOfTime::Millisecond);
			clock.SetToNow();
			Sleep();
		}
	}
	catch (QuitApplication) {}
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