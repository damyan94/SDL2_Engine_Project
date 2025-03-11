#include "stdafx.h"

#include <SDL_render.h>
#include <SDL_hints.h>

#include "System/SDLUtils/Drawing/Renderer.h"
#include "System/SDLUtils/Drawing/Config/RendererConfig.h"

#include "System/SDLUtils/Drawing/DrawParameters.h"
#include "System/SDLUtils/Drawing/Texture.h"

////////////////////////////////////////////////////////////////////////////////
Renderer::Renderer()
	: m_DefaultDrawColor(Colors::Black)
	, m_Renderer(nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
Renderer::~Renderer()
{
	Deinit();
}

////////////////////////////////////////////////////////////////////////////////
bool Renderer::Init(SDL_Window* window, const RendererConfig& cfg)
{
	AssertReturnIf(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0") && SDL_GetError(), false);
	AssertReturnIf(!SDL_SetHint(SDL_HINT_RENDER_BATCHING, "1") && SDL_GetError(), false);

	m_Renderer = SDL_CreateRenderer(window, -1, cfg.m_Flags);
	AssertReturnIf(!m_Renderer && SDL_GetError(), false);

	AssertReturnIf(EXIT_SUCCESS != SDL_SetRenderDrawBlendMode(m_Renderer, SDL_BlendMode::SDL_BLENDMODE_BLEND)
		&& SDL_GetError(), false);

	SetDrawColor(cfg.m_DrawColor);
	m_DefaultDrawColor = cfg.m_DrawColor;

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void Renderer::Deinit()
{
	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////
void Renderer::ClearScreen() const
{
	AssertReturnIf(EXIT_SUCCESS != SDL_RenderClear(m_Renderer) && SDL_GetError());
}

////////////////////////////////////////////////////////////////////////////////
void Renderer::FinishFrame() const
{
	SDL_RenderPresent(m_Renderer);
}

////////////////////////////////////////////////////////////////////////////////
void Renderer::RenderTexture(Texture& texture, const DrawParameters& p) const
{
	ReturnIf(p.m_Opacity <= 0 || !p.m_IsVisible);

	const SDL_Rect src{ p.m_FrameRect.x, p.m_FrameRect.y, p.m_FrameRect.w, p.m_FrameRect.h };
	const SDL_Rect dst{ p.m_PosRect.x, p.m_PosRect.y, p.m_PosRect.w, p.m_PosRect.h };
	const SDL_Point cntr{ p.m_RotationCenter.x, p.m_RotationCenter.y };

	texture.SetTextureAlphaMod(p.m_Opacity);

	AssertReturnIf(EXIT_SUCCESS != SDL_RenderCopyEx(
		m_Renderer,
		texture.Get(),
		&src,
		&dst,
		p.m_RotationAngle,
		&cntr,
		(SDL_RendererFlip)p.m_FlipMode) && SDL_GetError());

	texture.SetTextureAlphaMod(Constants::FullOpacity);
}

////////////////////////////////////////////////////////////////////////////////
void Renderer::SetDrawColor(const Color& color)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetRenderDrawColor(
		m_Renderer,
		color.r,
		color.g,
		color.b,
		color.a) && SDL_GetError());
}

////////////////////////////////////////////////////////////////////////////////
const Color& Renderer::GetDefaultDrawColor()
{
	return m_DefaultDrawColor;
}

////////////////////////////////////////////////////////////////////////////////
SDL_Renderer* Renderer::GetSDLRenderer() const
{
	return m_Renderer;
}