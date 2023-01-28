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
int32_t Engine::Init()
{
	srand((uint32_t)time(nullptr));

	// SDL init
	if (EXIT_SUCCESS != SDLLoader::Init())
	{
		std::cerr << "Error, SDLLoader::Init() failed." << std::endl;
		return EXIT_FAILURE;
	}
	
	// Base functionalities init
	if (EXIT_SUCCESS != _window.Init())
	{
		std::cerr << "Error, _window.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}
	
	if (EXIT_SUCCESS != _renderer.Init(_window.GetInstance(), Colors::VERY_LIGHT_GREY
		/*EngineConstants::RENDERER_DRAW_COLOR*/))
	{
		std::cerr << "Error, _renderer.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _event.Init())
	{
		std::cerr << "Error, _event.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	// Containers init
	if (EXIT_SUCCESS != _imageContainer.Init())
	{
		std::cerr << "Error, _imageContainer.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _fontContainer.Init())
	{
		std::cerr << "Error, _fontContainer.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _soundContainer.Init())
	{
		std::cerr << "Error, _soundContainer.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _musicContainer.Init())
	{
		std::cerr << "Error, _musicContainer.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	// Game init
	if (EXIT_SUCCESS != _game.Init())
	{
		std::cerr << "Error, _game.Init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	Timer::StartGlobalTimer();
	_drawTimerId = Timer::StartTimer(MIN_TIME_BETWEEN_UPDATE, TimerType::Pulse);

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
	ImGui_ImplSDL2_InitForSDLRenderer(_window.GetInstance(), _renderer.GetInstance());
	ImGui_ImplSDLRenderer_Init(_renderer.GetInstance());

	return EXIT_SUCCESS;
}

// =============================================================================
void Engine::Deinit()
{
	// Cleanup
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	_game.Deinit();

	_musicContainer.Deinit();
	_soundContainer.Deinit();
	_fontContainer.Deinit();
	_imageContainer.Deinit();

	_event.Deinit();
	_renderer.Deinit();
	_window.Deinit();
	SDLLoader::Deinit();
}

// =============================================================================
void Engine::HandleEvent()
{
	_game.HandleEvent(_event);
	ImGui_ImplSDL2_ProcessEvent(_event.GetInstance());
}

// =============================================================================
void Engine::Update()
{
	_game.Update();
	_renderer.Update();
}

// =============================================================================
void Engine::Draw() const
{
	_game.Draw();

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

	_renderer.Draw();
}

// =============================================================================
void Engine::RunApplication()
{
	Time clock;
	bool drawConditionAchieved = false;
	bool drawTimerTicked = false;

	Update();
	Draw();

	while (true)
	{
		while (_event.PollEvent())
		{
			if (_event.type == EventType::QUIT)
			{
				return;
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

		Sleep(clock.GetElapsedTime(UnitsOfTime::Milliseconds));
	}
}

// =============================================================================
void Engine::Sleep(int64_t elapsedTime)
{
	int64_t totalFrameTime = elapsedTime;
	auto sleepTime = std::chrono::milliseconds(EngineConstants::TIME_PER_FRAME - elapsedTime);
	if (sleepTime.count() > 0)
	{
		std::this_thread::sleep_for(sleepTime);
		totalFrameTime += sleepTime.count();
	}

	if (totalFrameTime > 0)
	{
		_currFPS = 1000 / totalFrameTime;
	}
}