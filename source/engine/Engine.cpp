// Corresponding header
#include "engine/Engine.h"

// C/C++ system includes
#include <iostream>
#include <thread>

// Third-party includes
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/SDLUtilsCommonIncludes.h"

#include "managers/ManagersDefines.h"
#include "managers/IManager.h"
#include "managers/AssetManager.h"
#include "managers/DrawManager.h"
#include "managers/TimerManager.h"

#include "defines/consts/GlobalConstants.h"
#include "sdl_utils/SDLLoader.h"

#include "sdl_utils/Window.h"
#include "sdl_utils/Renderer.h"

#define RUN_OPTIMIZED 0
#define MIN_TIME_BETWEEN_UPDATE 500

// Our state
bool show_demo_window = true;
bool show_another_window = false;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

// =============================================================================
Engine::Engine()
	: m_DrawTimerId(0)
	, m_ElapsedTime(0)
	, m_CurrFPS(0)
{
}

// =============================================================================
Engine::~Engine()
{
	//TODO Uncomment when I have implemented an ImGUI class that can exit gracefully and safely
	//Deinit();
}

// =============================================================================
bool Engine::Init()
{
	srand((uint32_t)time(nullptr));

	// SDL init
	ReturnIf(EXIT_SUCCESS != SDLLoader::Init(), false);

	m_Managers.resize((size_t)EManagerType::Count);

	m_Managers[(size_t)EManagerType::AssetManager] = AssetManager::Get();
	ReturnIf(!m_Managers[(size_t)EManagerType::AssetManager]->Init() , false);

	m_Managers[(size_t)EManagerType::DrawManager] = DrawManager::Get();
	ReturnIf(!m_Managers[(size_t)EManagerType::DrawManager]->Init(), false);

	m_Managers[(size_t)EManagerType::TimerManager] = TimerManager::Get();
	ReturnIf(!m_Managers[(size_t)EManagerType::TimerManager]->Init(), false);
	
	// Base functionalities init
	ReturnIf(EXIT_SUCCESS != m_InputEvent.Init(), false);

	// App init
	ReturnIf(!m_App.Init(), false);

	Timer::StartGlobalTimer();
	m_DrawTimerId = Timer::StartTimer(MIN_TIME_BETWEEN_UPDATE, ETimerType::Pulse);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	const auto drawManager = DrawManager::Get();

	ImGui_ImplSDL2_InitForSDLRenderer(drawManager->GetWindow()->GetBaseObject(),
		drawManager->GetRenderer()->GetBaseObject());
	ImGui_ImplSDLRenderer_Init(drawManager->GetRenderer()->GetBaseObject());

	return true;
}

// =============================================================================
void Engine::Deinit()
{
	// Cleanup
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	m_App.Deinit();

	for (auto manager : m_Managers)
	{
		manager->Deinit();
	}

	m_InputEvent.Deinit();
	SDLLoader::Deinit();
}

// =============================================================================
void Engine::HandleEvent()
{
	m_App.HandleEvent(m_InputEvent);
	ImGui_ImplSDL2_ProcessEvent(m_InputEvent.GetInstance());

	//TODO Maybe not have this here
	for (auto manager : m_Managers)
	{
		manager->HandleEvent(m_InputEvent);
	}
}

// =============================================================================
void Engine::Update()
{
	m_App.Update(m_ElapsedTime);

	for (auto manager : m_Managers)
	{
		manager->Update(m_ElapsedTime);
	}
}

// =============================================================================
void Engine::Draw() const
{
	m_App.Draw();

	// Start the Dear ImGui frame
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	// Custom code goes here
	ImGui::Begin("Hello World!");

	ImGui::Text("Hello there!");
	ImGui::Button("Click me!");

	ImGui::End();

	// Rendering
	ImGui::Render();
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

	static_cast<DrawManager*>(m_Managers[(size_t)EManagerType::DrawManager])->Draw();
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
			if (m_InputEvent.type == EventType::QUIT)
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
			_event.type == EventType::MOUSE_BUTTONDOWN || _event.type == EventType::MOUSE_BUTTONUP ||
			_event.type == EventType::KEYBOARD_PRESS || _event.type == EventType::KEYBOARD_RELEASE;
#ifdef USE_USER_EVENTS
		drawConditionAchieved = drawConditionAchieved && _event.type >= EventType::USEREVENT;
#endif // !USE_USER_EVENTS

#elif RUN_OPTIMIZED == 2
		drawConditionAchieved = 
			_event.type == EventType::MOUSE_BUTTONDOWN || _event.type == EventType::MOUSE_BUTTONUP ||
			_event.type == EventType::KEYBOARD_PRESS || _event.type == EventType::KEYBOARD_RELEASE;

#else
#error Error, invalid engine draw optimization.
#endif // !RUN_OPTIMIZED

#if RUN_OPTIMIZED > 0
		drawTimerTicked = Timer::IsActiveTimer(_drawTimerId) && !Timer::IsTimerPaused(_drawTimerId)
			&& Timer::IsTimerTicked(_drawTimerId);

		if (drawConditionAchieved || drawTimerTicked)
		{
			Draw();
		}
		drawConditionAchieved = false;
		_event.type = EventType::UNKNOWN;

#endif

		m_ElapsedTime = (int32_t)clock.GetElapsedTime(EUnitOfTime::Milliseconds);
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