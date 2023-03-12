// Corresponding header
#include "managers/DrawManager.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/config/DrawManagerConfig.h"
#include "sdl_utils/Window.h"
#include "sdl_utils/Renderer.h"

DrawManager* g_DrawManager = nullptr;

// =============================================================================
DrawManager::DrawManager()
	: m_Window(nullptr)
	, m_Renderer(nullptr)
{
}

// =============================================================================
DrawManager::~DrawManager()
{
	SafeDelete(m_Renderer);
	SafeDelete(m_Window);
}

// =============================================================================
bool DrawManager::Init(const DrawManagerConfig& cfg)
{
	m_Window = new Window;
	AssertReturnIf(!m_Window, false, "Failed to allocate memory.");

	m_Renderer = new Renderer;
	AssertReturnIf(!m_Renderer, false, "Failed to allocate memory.");

	ReturnIf(!m_Window->Init(cfg.m_WindowConfig), false);
	ReturnIf(!m_Renderer->Init(m_Window->GetBaseObject(), cfg.m_RendererConfig), false);

	return true;
}

// =============================================================================
void DrawManager::Deinit()
{
	m_Renderer->Deinit();
	m_Window->Deinit();
}

// =============================================================================
void DrawManager::Update(int32_t dt)
{
	ReturnIf(m_Window->IsMinimized(), void());

	m_Renderer->Update();
}

// =============================================================================
void DrawManager::Draw() const
{
	ReturnIf(m_Window->IsMinimized(), void());

	m_Renderer->Draw();
}

// =============================================================================
Window* DrawManager::GetWindow() const
{
	return m_Window;
}

// =============================================================================
Renderer* DrawManager::GetRenderer() const
{
	return m_Renderer;
}