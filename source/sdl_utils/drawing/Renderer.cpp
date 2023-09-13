#include "stdafx.h"

#include <SDL_render.h>
#include <SDL_hints.h>

#include "sdl_utils/drawing/Renderer.h"
#include "sdl_utils/drawing/config/RendererConfig.h"

#include "sdl_utils/drawing/DrawParameters.h"
#include "sdl_utils/drawing/Texture.h"

// =============================================================================
Renderer::Renderer()
	: m_DefaultDrawColor(Colors::Black)
	, m_Renderer(nullptr)
{
}

// =============================================================================
Renderer::~Renderer()
{
	Deinit();
}

// =============================================================================
bool Renderer::Init(SDL_Window* window, const RendererConfig& cfg)
{
	AssertReturnIf(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0"), false,
		"SDL_SetHint() failed: " + std::string(SDL_GetError()));

	AssertReturnIf(!SDL_SetHint(SDL_HINT_RENDER_BATCHING, "1"), false,
		"SDL_SetHint() failed: " + std::string(SDL_GetError()));

	m_Renderer = SDL_CreateRenderer(window, -1, cfg.m_Flags);
	AssertReturnIf(!m_Renderer, false, "SDL_CreateRenderer() failed: " + std::string(SDL_GetError()));

	AssertReturnIf(EXIT_SUCCESS != SDL_SetRenderDrawBlendMode(m_Renderer, SDL_BlendMode::SDL_BLENDMODE_BLEND),
		false, "SDL_SetRenderDrawBlendMode() failed: " + std::string(SDL_GetError()));

	SetDrawColor(cfg.m_DrawColor);
	m_DefaultDrawColor = cfg.m_DrawColor;

	return true;
}

// =============================================================================
void Renderer::Deinit()
{
	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

// =============================================================================
void Renderer::ClearScreen() const
{
	AssertReturnIf(EXIT_SUCCESS != SDL_RenderClear(m_Renderer), void(),
		"SDL_RenderClear() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
void Renderer::FinishFrame() const
{
	SDL_RenderPresent(m_Renderer);
}

// =============================================================================
void Renderer::RenderTexture(Texture* texture, const DrawParameters& p) const
{
	ReturnIf(p.m_Opacity <= 0 || !p.m_IsVisible, void());

	const SDL_Rect src{ p.m_FrameRect.x, p.m_FrameRect.y, p.m_FrameRect.w, p.m_FrameRect.h };
	const SDL_Rect dst{ p.m_PosRect.x, p.m_PosRect.y, p.m_PosRect.w, p.m_PosRect.h };
	const SDL_Point cntr{ p.m_RotationCenter.x, p.m_RotationCenter.y };

	texture->SetTextureAlphaMod(p.m_Opacity);

	AssertReturnIf(EXIT_SUCCESS != SDL_RenderCopyEx(
		m_Renderer,
		texture->Get(),
		&src,
		&dst,
		p.m_RotationAngle,
		&cntr,
		(SDL_RendererFlip)p.m_FlipMode),
		void(), "SDL_RenderCopyEx() failed: " + std::string(SDL_GetError()));

	texture->SetTextureAlphaMod(Constants::FullOpacity);
}

// =============================================================================
void Renderer::SetDrawColor(const Color& color)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetRenderDrawColor(
		m_Renderer,
		color.r,
		color.g,
		color.b,
		color.a),
		void(), "SDL_SetRenderDrawColor() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
const Color& Renderer::GetDefaultDrawColor()
{
	return m_DefaultDrawColor;
}

// =============================================================================
SDL_Renderer* Renderer::GetSDLRenderer() const
{
	return m_Renderer;
}