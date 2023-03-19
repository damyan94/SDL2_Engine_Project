// Corresponding header
#include "managers/ImGuiManager.h"
#include "managers/config/ImGuiManagerConfig.h"

// C/C++ system includes

// Third-party includes
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_sdlrenderer.h"

// Own includes
#include "sdl_utils/drawing/Window.h"
#include "sdl_utils/drawing/Renderer.h"

#include "managers/DrawManager.h"

ImGuiManager* g_ImGuiManager = nullptr;

// Our state
//bool show_demo_window = true;
//bool show_another_window = false;
//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

// =============================================================================
ImGuiManager::ImGuiManager()
{
}

// =============================================================================
ImGuiManager::~ImGuiManager()
{
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

// =============================================================================
bool ImGuiManager::Init(const ImGuiManagerConfig& cfg)
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	switch (cfg.m_ImGuiStyle)
	{
	case EImGuiStyle::Dark:
		ImGui::StyleColorsDark();
		break;

	case EImGuiStyle::Classic:
		ImGui::StyleColorsClassic();
		break;

	case EImGuiStyle::Light:
		ImGui::StyleColorsLight();
		break;

	default:
		break;
	}

	// Setup Platform/Renderer backends
	auto sdlWindow = g_DrawManager->GetWindow()->GetSDLWindow();
	auto sdlRenderer = g_DrawManager->GetRenderer()->GetSDLRenderer();
	ImGui_ImplSDL2_InitForSDLRenderer(sdlWindow, sdlRenderer);
	ImGui_ImplSDLRenderer_Init(sdlRenderer);

	return true;
}

// =============================================================================
void ImGuiManager::Deinit()
{
	// Cleanup
}

// =============================================================================
void ImGuiManager::HandleEvent(const InputEvent& e)
{
	ImGui_ImplSDL2_ProcessEvent(e.GetBaseObject());
}

// =============================================================================
void ImGuiManager::Update(int32_t dt)
{
}

// =============================================================================
void ImGuiManager::Draw() const
{
	// Start the Dear ImGui frame
	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	// Custom code goes here
	DrawInternal();

	// Rendering
	ImGui::Render();
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
}

// =============================================================================
void ImGuiManager::DrawInternal() const
{
	ImGui::Begin("Hello World!");

	ImGui::Text("Hello there!");
	ImGui::Button("Click me!");

	ImGui::End();
}