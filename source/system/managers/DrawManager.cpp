#include "stdafx.h"

#include "system/managers/DrawManager.h"
#include "system/managers/config/DrawManagerConfig.h"

#include "system/sdl_utils/drawing/DrawParameters.h"
#include "system/sdl_utils/drawing/Texture.h"
#include "system/sdl_utils/drawing/SDLDrawing.h"
#include "system/sdl_utils/containers/image_container/ImageData.h"
#include "system/sdl_utils/containers/text_container/TextData.h"

#include "system/components/drawing/Image.h"
#include "system/components/drawing/Text.h"
#include "system/components/drawing/DynamicText.h"

DrawManager* g_DrawManager = nullptr;

// =============================================================================
DrawManager::DrawManager()
	: m_DrawCalls(0)
{
}

// =============================================================================
DrawManager::~DrawManager()
{
	Deinit();
}

// =============================================================================
bool DrawManager::Init(const DrawManagerConfig& cfg)
{
	ReturnIf(!m_Window.Init(cfg.m_WindowConfig), false);
	ReturnIf(!m_Renderer.Init(m_Window.GetSDLWindow(), cfg.m_RendererConfig), false);

	Texture::SetRenderer(&m_Renderer);
	SDLDrawing::SetRenderer(&m_Renderer);

	return true;
}

// =============================================================================
void DrawManager::Deinit()
{
}

// =============================================================================
void DrawManager::HandleEvent(const InputEvent& e)
{
	m_Window.HandleEvent(e);
	//TODO Check if window is resized, then update position of all images that have fixed relative position (UI)
	// e.g. Button1.SetPositionFixed(Rectangle*? parent, EHowToPosition htp, Point pos);
	// enum class EHowToPosition { Center, Left, Right, Top, Bottom, TopLeft, ... etc. };
}

// =============================================================================
void DrawManager::Draw() const
{
	for (const auto& item : m_Images)
	{
		if (item && item->GetIsVisible())
		{
			DrawTexture(item->GetData()->m_Texture, item->GetDrawParameters());
		}
	}
	for (const auto& item : m_Texts)
	{
		if (item && item->GetIsVisible())
		{
			DrawTexture(item->GetData()->m_Texture, item->GetDrawParameters());
		}
	}
	for (const auto& item : m_DynamicTexts)
	{
		if (item && item->GetIsVisible())
		{
			DrawTexture(item->GetData()->m_Texture, item->GetDrawParameters());
		}
	}
}

// =============================================================================
void DrawManager::ClearScreen() const
{
	ReturnIf(m_Window.IsMinimized(), void());

	m_Renderer.ClearScreen();
	m_DrawCalls = 0;
}

// =============================================================================
void DrawManager::FinishFrame() const
{
	ReturnIf(m_Window.IsMinimized(), void());

	m_Renderer.FinishFrame();
}

// =============================================================================
bool DrawManager::IsInsideWindow(const DrawParameters& p) const
{
	const Rectangle& dstRect		= p.m_PosRect;
	const Rectangle& windowRect		= m_Window.GetWindowRect();

	return (dstRect.x + dstRect.w > 0 && dstRect.y + dstRect.h > 0)
		&& (dstRect.x < windowRect.w && dstRect.y < windowRect.h);
}

// =============================================================================
Window& DrawManager::GetWindow()
{
	return m_Window;
}

// =============================================================================
Renderer& DrawManager::GetRenderer()
{
	return m_Renderer;
}

// =============================================================================
void DrawManager::AddImage(Image* item)
{
	ReturnIf(!item, void());
	m_Images.emplace_back(item);
}

// =============================================================================
void DrawManager::RemoveImage(Image* item)
{
	auto it = std::find(m_Images.begin(), m_Images.end(), item);
	ReturnIf(it == m_Images.end(), void());
	m_Images.erase(it);
}

// =============================================================================
void DrawManager::AddText(Text* item)
{
	ReturnIf(!item, void());
	m_Texts.emplace_back(item);
}

// =============================================================================
void DrawManager::RemoveText(Text* item)
{
	auto it = std::find(m_Texts.begin(), m_Texts.end(), item);
	ReturnIf(it == m_Texts.end(), void());
	m_Texts.erase(it);
}

// =============================================================================
void DrawManager::AddDynamicText(DynamicText* item)
{
	ReturnIf(!item, void());
	m_DynamicTexts.emplace_back(item);
}

// =============================================================================
void DrawManager::RemoveDynamicText(DynamicText* item)
{
	auto it = std::find(m_DynamicTexts.begin(), m_DynamicTexts.end(), item);
	ReturnIf(it == m_DynamicTexts.end(), void());
	m_DynamicTexts.erase(it);
}

// =============================================================================
void DrawManager::DrawTexture(Texture* texture, const DrawParameters& p) const
{
	ReturnIf(m_Window.IsMinimized() || !IsInsideWindow(p), void());

	m_Renderer.RenderTexture(texture, p);
	m_DrawCalls++;
}