#include "stdafx.h"

#include "System/Managers/DrawManager.h"
#include "System/Managers/Config/DrawManagerConfig.h"

#include "System/SDLUtils/Drawing/DrawParameters.h"
#include "System/SDLUtils/Drawing/Texture.h"
#include "System/SDLUtils/Drawing/SDLDrawing.h"

#include "System/Managers/AssetManager.h"

////////////////////////////////////////////////////////////////////////////////
DrawManager::DrawManager()
	: m_DrawCalls(0)
{
}

////////////////////////////////////////////////////////////////////////////////
DrawManager::~DrawManager()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
DrawManager& DrawManager::Instance()
{
	static DrawManager m_Instance;
	return m_Instance;
}

////////////////////////////////////////////////////////////////////////////////
bool DrawManager::Init(const DrawManagerConfig& cfg)
{
	ReturnIf(!m_Window.Init(cfg.m_WindowConfig), false);
	ReturnIf(!m_Renderer.Init(m_Window.GetSDLWindow(), cfg.m_RendererConfig), false);

	Texture::SetRenderer(&m_Renderer);
	SDLDrawing::SetRenderer(&m_Renderer);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::HandleEvent(const InputEvent& e)
{
	m_Window.HandleEvent(e);
	//TODO Check if window is resized, then update position of all images that have fixed relative position (UI)
	// e.g. Button1.SetPositionFixed(Rectangle*? parent, EHowToPosition htp, Point pos);
	// enum class EHowToPosition { Center, Left, Right, Top, Bottom, TopLeft, ... etc. };
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::Update(int32_t dt)
{
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::ClearScreen() const
{
	ReturnIf(m_Window.IsMinimized());

	m_Renderer.ClearScreen();
	m_DrawCalls = 0;
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::FinishFrame() const
{
	ReturnIf(m_Window.IsMinimized());

	m_Renderer.FinishFrame();
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::DrawTexture(const DrawParameters& p) const
{
	ReturnIf(m_Window.IsMinimized() || !IsInsideWindow(p));

	Texture* texture = GetTextureInternal(p);
	ReturnIf(!texture);

	m_Renderer.RenderTexture(*texture, p);
	m_DrawCalls++;
}

////////////////////////////////////////////////////////////////////////////////
bool DrawManager::IsInsideWindow(const DrawParameters& p) const
{
	const Rectangle& dstRect		= p.PosRect;
	const Rectangle& windowRect		= m_Window.GetWindowRect();

	return (dstRect.x + dstRect.w > 0 && dstRect.y + dstRect.h > 0)
		&& (dstRect.x < windowRect.w && dstRect.y < windowRect.h);
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::SetTextureOpacity(const DrawParameters& p) const
{
	Texture* texture = GetTextureInternal(p);
	ReturnIf(!texture);

	texture->SetTextureAlphaMod(p.Opacity);
}

////////////////////////////////////////////////////////////////////////////////
void DrawManager::SetTextureBlendMode(const DrawParameters& p) const
{
	Texture* texture = GetTextureInternal(p);
	ReturnIf(!texture);

	texture->SetTextureBlendMode(p.BlendMode);
}

////////////////////////////////////////////////////////////////////////////////
int32_t DrawManager::GetDrawCalls() const
{
	return m_DrawCalls;
}

////////////////////////////////////////////////////////////////////////////////
Window& DrawManager::GetWindow()
{
	return m_Window;
}

////////////////////////////////////////////////////////////////////////////////
Renderer& DrawManager::GetRenderer()
{
	return m_Renderer;
}

////////////////////////////////////////////////////////////////////////////////
Texture* DrawManager::GetTextureInternal(const DrawParameters& p) const
{
	switch (p.ObjectType)
	{
	case EObjectType::Image:
		return AssetManager::Instance().m_ImageContainer.GetData(p.ResourceId).Texture;

	case EObjectType::Text:
		return AssetManager::Instance().m_TextContainer.GetData(p.ResourceId).Texture;

	case EObjectType::DynamicText:
		return AssetManager::Instance().m_DynamicTextContainer.GetData(p.ResourceId).Texture;

	default:
		Assert::Assert("TODO");
		return nullptr;
	}
}