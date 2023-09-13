#include "stdafx.h"

#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "sdl_utils/drawing/Texture.h"

#include "sdl_utils/drawing/Renderer.h"

static Renderer* s_Renderer = nullptr;

// =============================================================================
Texture::Texture()
	: m_Texture(nullptr)
{
}

// =============================================================================
Texture::~Texture()
{
	DestroyTexture();
}

// =============================================================================
void Texture::SetRenderer(Renderer* renderer)
{
	s_Renderer = renderer;
}

// =============================================================================
SDL_Texture* Texture::Get()
{
	return m_Texture;
}

// =============================================================================
void Texture::CreateTextureFromFile(ImageTextureParameters& inOutParams)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromFile(surface, inOutParams);
	ReturnIf(!surface, void());

	CreateTextureFromSurface(surface);
	ReturnIf(!m_Texture, void());

	DestroySurface(surface);
}

// =============================================================================
void Texture::CreateTextureFromText(TextTextureParameters& inOutParams)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromText(surface, inOutParams);
	ReturnIf(!surface, void());

	CreateTextureFromSurface(surface);
	ReturnIf(!m_Texture, void());

	DestroySurface(surface);
}

// =============================================================================
void Texture::SetTextureBlendMode(const EBlendMode& blendMode)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureBlendMode(m_Texture, SDL_BlendMode(blendMode)),
		void(), "SDL_SetTextureBlendMode() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
void Texture::DestroyTexture()
{
	ReturnIf(!m_Texture, void());

	SDL_DestroyTexture(m_Texture);
	m_Texture = nullptr;
}

// =============================================================================
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

	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureAlphaMod(m_Texture, (uint8_t)alpha),
		void(), "SDL_SetTextureAlphaMod() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
void Texture::CreateSurfaceFromFile(SDL_Surface*& outSurface,
	ImageTextureParameters& inOutParams)
{
	outSurface = IMG_Load(inOutParams.m_FileName.c_str());

	AssertReturnIf(!outSurface, void(), "IMG_Load() failed: " + std::string(SDL_GetError()));

	inOutParams.m_Width = outSurface->w;
	inOutParams.m_Height = outSurface->h;
}

// =============================================================================
void Texture::CreateSurfaceFromText(SDL_Surface*& outSurface,
	TextTextureParameters& inOutParams)
{
	SDL_Color color{
		inOutParams.m_TextColor.r,
		inOutParams.m_TextColor.g,
		inOutParams.m_TextColor.b,
		inOutParams.m_TextColor.a };

	outSurface = TTF_RenderUTF8_Blended_Wrapped(const_cast<TTF_Font*>(inOutParams.m_Font),
		inOutParams.m_String.c_str(), color, inOutParams.m_WrapWidth);

	AssertReturnIf(!outSurface, void(), "TTF_RenderText_Blended() failed: " +
		std::string(SDL_GetError()));

	inOutParams.m_Width = outSurface->w;
	inOutParams.m_Height = outSurface->h;
}

// =============================================================================
void Texture::CreateTextureFromSurface(SDL_Surface* surface)
{
	m_Texture = SDL_CreateTextureFromSurface(s_Renderer->GetSDLRenderer(), surface);

	AssertReturnIf(!m_Texture, void(), "SDL_CreateTextureFromSurface() failed: " +
		std::string(SDL_GetError()));
}

// =============================================================================
void Texture::DestroySurface(SDL_Surface*& outSurface)
{
	ReturnIf(!outSurface, void());

	SDL_FreeSurface(outSurface);
	outSurface = nullptr;
}