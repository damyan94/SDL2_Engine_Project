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
#include "defines/consts/GlobalConstants.h"
#include "utils/time/Timer.h"
#include "sdl_utils/SDLLoader.h"

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
int32_t Engine::Init()
{
	srand((uint32_t)time(nullptr));

	// SDL init
	AssertReturnIf(EXIT_SUCCESS != SDLLoader::Init(), EXIT_FAILURE);
	
	// Base functionalities init
	AssertReturnIf(EXIT_SUCCESS != m_Window.Init(), EXIT_FAILURE);
	AssertReturnIf(EXIT_SUCCESS != m_Renderer.Init(m_Window.GetInstance(), Colors::VeryLightGrey), EXIT_FAILURE);
	AssertReturnIf(EXIT_SUCCESS != m_InputEvent.Init(), EXIT_FAILURE);

	// Containers init
	AssertReturnIf(EXIT_SUCCESS != m_ImageContainer.Init(), EXIT_FAILURE);
	AssertReturnIf(EXIT_SUCCESS != m_FontContainer.Init(), EXIT_FAILURE);
	AssertReturnIf(EXIT_SUCCESS != m_SoundContainer.Init(), EXIT_FAILURE);
	AssertReturnIf(EXIT_SUCCESS != m_MusicContainer.Init(), EXIT_FAILURE);

	// App init
	AssertReturnIf(EXIT_SUCCESS != m_App.Init(), EXIT_FAILURE);

	Timer::StartGlobalTimer();
	m_DrawTimerId = Timer::StartTimer(MIN_TIME_BETWEEN_UPDATE, TimerType::Pulse);

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
	ImGui_ImplSDL2_InitForSDLRenderer(m_Window.GetInstance(), m_Renderer.GetInstance());
	ImGui_ImplSDLRenderer_Init(m_Renderer.GetInstance());

	return EXIT_SUCCESS;
}

// =============================================================================
void Engine::Deinit()
{
	// Cleanup
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	m_App.Deinit();

	m_MusicContainer.Deinit();
	m_SoundContainer.Deinit();
	m_FontContainer.Deinit();
	m_ImageContainer.Deinit();

	m_InputEvent.Deinit();
	m_Renderer.Deinit();
	m_Window.Deinit();
	SDLLoader::Deinit();
}

// =============================================================================
void Engine::HandleEvent()
{
	m_App.HandleEvent(m_InputEvent);
	ImGui_ImplSDL2_ProcessEvent(m_InputEvent.GetInstance());
}

// =============================================================================
void Engine::Update()
{
	m_App.Update(m_ElapsedTime);
	m_Renderer.Update();
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

	m_Renderer.Draw();
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

		m_ElapsedTime = (int32_t)clock.GetElapsedTime(UnitOfTime::Milliseconds);
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