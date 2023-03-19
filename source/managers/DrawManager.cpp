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
	m_Renderer->Deinit();
	m_Window->Deinit();
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
void DrawManager::DrawImage(ImageId id, const DrawParameters& p) const
{
	ReturnIf(!IsInsideWindow(p), void());

	SDL_Texture* texture = g_AssetManager->GetImageData(id).m_Texture;
	m_Renderer->RenderTexture(texture, p);
}

// =============================================================================
void DrawManager::DrawText(TextId id, const DrawParameters& p) const
{
	ReturnIf(!IsInsideWindow(p), void());

	SDL_Texture* texture = g_AssetManager->GetTextData(id).m_Texture;
	m_Renderer->RenderTexture(texture, p);
}

// =============================================================================
void DrawManager::DrawDynamicText(const String& string, const DrawParameters& p) const
{
	ReturnIf(!IsInsideWindow(p), void());

	//TODO major refactoring needed
	//m_Renderer->RenderTexture(texture, p);
}

// =============================================================================
bool DrawManager::IsInsideWindow(const DrawParameters& p) const
{
	const Rectangle dstRect{ p.m_Pos.x, p.m_Pos.y, p.m_Width, p.m_Height };
	const Rectangle& srcRect = p.m_FrameRect;

	bool isInsideWindow = (dstRect.x + dstRect.w > 0 && dstRect.y + dstRect.h > 0)
		&& (dstRect.x < m_Window->GetWindowRect().w && dstRect.y < m_Window->GetWindowRect().h);

	return isInsideWindow;
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