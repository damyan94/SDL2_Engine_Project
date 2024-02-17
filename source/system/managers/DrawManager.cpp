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

static constexpr int32_t ERASE_TIME = 10000;

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

	m_EraseTimer.Start(ERASE_TIME, ETimerType::Pulse);

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
void DrawManager::Update(int32_t dt)
{
	ReturnIf(m_EraseTimer.IsPaused());
	ReturnIf(!m_EraseTimer.IsTicked());

	RemoveEmptyItems();
}

// =============================================================================
void DrawManager::Draw() const
{
	for (const auto& item : m_Images)
	{
		if (item && item->IsVisible())
		{
			DrawTexture(item->GetData()->m_Texture, item->GetDrawParameters());
		}
	}

	for (const auto& item : m_Texts)
	{
		if (item && item->IsVisible())
		{
			DrawTexture(item->GetData()->m_Texture, item->GetDrawParameters());
		}
	}

	for (const auto& item : m_DynamicTexts)
	{
		if (item && item->IsVisible())
		{
			DrawTexture(item->GetData()->m_Texture, item->GetDrawParameters());
		}
	}
}

// =============================================================================
void DrawManager::ClearScreen() const
{
	ReturnIf(m_Window.IsMinimized());

	m_Renderer.ClearScreen();
	m_DrawCalls = 0;
}

// =============================================================================
void DrawManager::FinishFrame() const
{
	ReturnIf(m_Window.IsMinimized());

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
	ReturnIf(!item);
	m_Images.emplace_back(item);
}

// =============================================================================
void DrawManager::AddText(Text* item)
{
	ReturnIf(!item);
	m_Texts.emplace_back(item);
}

// =============================================================================
void DrawManager::AddDynamicText(DynamicText* item)
{
	ReturnIf(!item);
	m_DynamicTexts.emplace_back(item);
}

// =============================================================================
void DrawManager::DrawTexture(Texture* texture, const DrawParameters& p) const
{
	ReturnIf(m_Window.IsMinimized() || !IsInsideWindow(p));

	m_Renderer.RenderTexture(texture, p);
	m_DrawCalls++;
}

// =============================================================================
void DrawManager::RemoveEmptyItems()
{
	std::erase_if(m_Images, [](Image* item) {return !item; });
	std::erase_if(m_Texts, [](Text* item) {return !item; });
	std::erase_if(m_DynamicTexts, [](DynamicText* item) {return !item; });
}