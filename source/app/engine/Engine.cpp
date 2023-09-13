#include "stdafx.h"

#include "app/engine/Engine.h"
#include "app/engine/config/EngineConfig.h"

#include "system/sdl_utils/SDLLoader.h"

#include "system/managers/DrawManager.h"
#include "system/managers/AssetManager.h"
#include "system/managers/AudioManager.h"
#include "system/managers/TimerManager.h"
#include "system/managers/ImGuiManager.h"
#include "app/engine/settings/Settings.h"

static constexpr int32_t c_MaxDelayBetweenFrames = 100;

// =============================================================================
Engine::Engine()
	: m_ElapsedTimeMS(0)
	, m_TargetFPS(0)
	, m_TargetTimePerFrame(0)
{
}

// =============================================================================
Engine::~Engine()
{
	Deinit();

#ifdef USE_IMGUI
	SafeDelete(g_ImGuiManager);
#endif

	SafeDelete(g_App);
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

#define ALLOCATE_AND_INIT(_Type)\
g_##_Type = new _Type;\
AssertReturnIf(!g_##_Type, false, "Failed to allocate memory.");\
ReturnIf(!g_##_Type->Init(cfg.m_##_Type##Config), false)

	ALLOCATE_AND_INIT(DrawManager);
	ALLOCATE_AND_INIT(AssetManager);
	ALLOCATE_AND_INIT(AudioManager);
	ALLOCATE_AND_INIT(TimerManager);

#ifdef USE_IMGUI
	ALLOCATE_AND_INIT(ImGuiManager);
#endif

	ALLOCATE_AND_INIT(App);

	m_TargetFPS = g_Settings->GetTargetFPS();
	m_TargetTimePerFrame = 1000 / m_TargetFPS;

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

#ifdef USE_IMGUI
	g_ImGuiManager->HandleEvent(m_InputEvent);
#endif

	g_App->HandleEvent(m_InputEvent);

	//TODO Move this to the settings menu or other appropriate place
	if (m_InputEvent.m_Key == EKeyboardKey::E &&
		m_InputEvent.m_Type == EEventType::KeyboardPress)
	{
		g_AssetManager->ChangeLanguage(ELanguage::EN);
		g_Settings->SetLanguage(ELanguage::EN);
	}
	else if (m_InputEvent.m_Key == EKeyboardKey::R &&
		m_InputEvent.m_Type == EEventType::KeyboardPress)
	{
		g_AssetManager->ChangeLanguage(ELanguage::BG);
		g_Settings->SetLanguage(ELanguage::BG);
	}
}

// =============================================================================
void Engine::Update()
{
	g_TimerManager->Update(m_ElapsedTimeMS);

	// Handle delays here so that we do not compromise our timers
	g_App->Update(m_ElapsedTimeMS < c_MaxDelayBetweenFrames
		? m_ElapsedTimeMS
		: m_ElapsedTimeMS = m_TargetTimePerFrame);
}

// =============================================================================
void Engine::Draw() const
{
	g_DrawManager->ClearScreen();
	g_DrawManager->Draw();

#ifdef USE_IMGUI
	g_ImGuiManager->Draw();
#endif

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
	const int32_t sleepTime = m_TargetTimePerFrame - m_ElapsedTimeMS;

	if (sleepTime > 0)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
		m_ElapsedTimeMS += sleepTime;
	}
}