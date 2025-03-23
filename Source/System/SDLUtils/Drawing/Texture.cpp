#include "stdafx.h"

#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "System/SDLUtils/Drawing/Texture.h"

#include "System/SDLUtils/Drawing/Renderer.h"

static Renderer* s_Renderer = nullptr;

////////////////////////////////////////////////////////////////////////////////
Texture::Texture()
	: m_Texture(nullptr)
{
}

////////////////////////////////////////////////////////////////////////////////
Texture::~Texture()
{
	DestroyTexture();
}

////////////////////////////////////////////////////////////////////////////////
void Texture::SetRenderer(Renderer* renderer)
{
	s_Renderer = renderer;
}

////////////////////////////////////////////////////////////////////////////////
SDL_Texture* Texture::Get()
{
	return m_Texture;
}

////////////////////////////////////////////////////////////////////////////////
void Texture::CreateTextureFromFile(ImageTextureParameters& inOutParams)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromFile(surface, inOutParams);
	ReturnIf(!surface);

	CreateTextureFromSurface(surface);
	ReturnIf(!m_Texture);

	DestroySurface(surface);
}

////////////////////////////////////////////////////////////////////////////////
void Texture::CreateTextureFromText(TextTextureParameters& inOutParams)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromText(surface, inOutParams);
	ReturnIf(!surface);

	CreateTextureFromSurface(surface);
	ReturnIf(!m_Texture);

	DestroySurface(surface);
}

////////////////////////////////////////////////////////////////////////////////
void Texture::SetTextureBlendMode(const EBlendMode& blendMode)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureBlendMode(m_Texture, SDL_BlendMode(blendMode))
		&& SDL_GetError());
}

////////////////////////////////////////////////////////////////////////////////
void Texture::SetTextureAlphaMod(int32_t alpha)
{
	if (alpha < Constants::ZeroOpacity)
	{
		alpha = Constants::ZeroOpacity;
	}

	if (alpha > Constants::FullOpacity)
	{
		alpha = Constants::FullOpacity;
	}

	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureAlphaMod(m_Texture, (uint8_t)alpha)
		&& SDL_GetError());
}

////////////////////////////////////////////////////////////////////////////////
void Texture::DestroyTexture()
{
	ReturnIf(!m_Texture);

	SDL_DestroyTexture(m_Texture);
	m_Texture = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
void Texture::CreateSurfaceFromFile(SDL_Surface*& outSurface,
	ImageTextureParameters& inOutParams)
{
	outSurface = IMG_Load(inOutParams.FileName.c_str());

	AssertReturnIf(!outSurface && SDL_GetError());

	inOutParams.Width = outSurface->w;
	inOutParams.Height = outSurface->h;
}

////////////////////////////////////////////////////////////////////////////////
void Texture::CreateSurfaceFromText(SDL_Surface*& outSurface,
	TextTextureParameters& inOutParams)
{
	SDL_Color color{
		inOutParams.TextColor.r,
		inOutParams.TextColor.g,
		inOutParams.TextColor.b,
		inOutParams.TextColor.a };

	outSurface = TTF_RenderUTF8_Blended_Wrapped(const_cast<TTF_Font*>(inOutParams.Font),
		inOutParams.String.c_str(), color, inOutParams.WrapWidth);

	AssertReturnIf(!outSurface && SDL_GetError());

	inOutParams.Width = outSurface->w;
	inOutParams.Height = outSurface->h;
}

////////////////////////////////////////////////////////////////////////////////
void Texture::CreateTextureFromSurface(SDL_Surface* surface)
{
	m_Texture = SDL_CreateTextureFromSurface(s_Renderer->GetSDLRenderer(), surface);

	AssertReturnIf(!m_Texture && SDL_GetError());
}

////////////////////////////////////////////////////////////////////////////////
void Texture::DestroySurface(SDL_Surface*& outSurface)
{
	ReturnIf(!outSurface);

	SDL_FreeSurface(outSurface);
	outSurface = nullptr;
}