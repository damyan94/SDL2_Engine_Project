// Corresponding header
#include "managers/DrawManager.h"
#include "managers/config/DrawManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/drawing/DrawParameters.h"
#include "sdl_utils/drawing/Window.h"
#include "sdl_utils/drawing/Renderer.h"
#include "managers/AssetManager.h"

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
	Deinit();
	SafeDelete(m_Renderer);
	SafeDelete(m_Window);
}

// =============================================================================
bool DrawManager::Init(const DrawManagerConfig& cfg)
{
	m_Window = new Window;
	m_Renderer = new Renderer;

	AssertReturnIf(!m_Window, false, "Failed to allocate memory.");
	AssertReturnIf(!m_Renderer, false, "Failed to allocate memory.");

	ReturnIf(!m_Window->Init(cfg.m_WindowConfig), false);
	ReturnIf(!m_Renderer->Init(m_Window->GetSDLWindow(), cfg.m_RendererConfig), false);

	return true;
}

// =============================================================================
void DrawManager::Deinit()
{
}

// =============================================================================
void DrawManager::HandleEvent(const InputEvent& e)
{
	m_Window->HandleEvent(e);
}

// =============================================================================
void DrawManager::ClearScreen() const
{
	ReturnIf(m_Window->IsMinimized(), void());

	m_Renderer->ClearScreen();
}

// =============================================================================
void DrawManager::FinishFrame() const
{
	ReturnIf(m_Window->IsMinimized(), void());

	m_Renderer->FinishFrame();
}

// =============================================================================
void DrawManager::DrawTexture(SDL_Texture* texture, const DrawParameters& p) const
{
	ReturnIf(m_Window->IsMinimized() || !IsInsideWindow(p), void());

	m_Renderer->RenderTexture(texture, p);
}

// =============================================================================
void DrawManager::DrawImage(ImageId id, const DrawParameters& p) const
{
	ReturnIf(m_Window->IsMinimized() || !IsInsideWindow(p), void());

	SDL_Texture* texture = g_AssetManager->GetImageData(id).m_Texture;
	m_Renderer->RenderTexture(texture, p);
}

// =============================================================================
void DrawManager::DrawText(TextId id, const DrawParameters& p) const
{
	ReturnIf(m_Window->IsMinimized() || !IsInsideWindow(p), void());

	SDL_Texture* texture = g_AssetManager->GetTextData(id).m_Texture;
	m_Renderer->RenderTexture(texture, p);
}

// =============================================================================
bool DrawManager::IsInsideWindow(const DrawParameters& p) const
{
	const Rectangle& dstRect		= p.m_PosRect;
	const Rectangle& windowRect		= m_Window->GetWindowRect();

	return (dstRect.x + dstRect.w > 0 && dstRect.y + dstRect.h > 0)
		&& (dstRect.x < windowRect.w && dstRect.y < windowRect.h);
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