// Corresponding header
#include "sdl_utils/drawing/Texture.h"

// C/C++ system includes

// Third-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// Own includes
#include "sdl_utils/drawing/Window.h"
#include "sdl_utils/drawing/Renderer.h"

//TODO Refactor
#include "managers/DrawManager.h"

// =============================================================================
void Texture::CreateSurfaceFromFile(SDL_Surface*& outSurface,
	ImageTextureParameters& inOutParams)
{
	outSurface = IMG_Load(inOutParams.m_FileName.c_str());

	AssertReturnIf(!outSurface, void(), "IMG_Load() failed: " + std::string(SDL_GetError()));

	inOutParams.m_Width			= outSurface->w;
	inOutParams.m_Height		= outSurface->h;
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
		inOutParams.m_String.c_str(), color, 0);

	AssertReturnIf(!outSurface, void(), "TTF_RenderText_Blended() failed: " +
		std::string(SDL_GetError()));

	inOutParams.m_Width			= outSurface->w;
	inOutParams.m_Height		= outSurface->h;
}

// =============================================================================
void Texture::CreateTextureFromSurface(SDL_Surface* surface, SDL_Texture*& outTexture)
{
	outTexture = SDL_CreateTextureFromSurface(g_DrawManager->GetRenderer()->GetSDLRenderer(), surface);

	AssertReturnIf(!outTexture, void(), "SDL_CreateTextureFromSurface() failed: " +
		std::string(SDL_GetError()));
}

// =============================================================================
void Texture::CreateTextureFromFile(SDL_Texture*& outTexture,
	ImageTextureParameters& inOutParams)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromFile(surface, inOutParams);
	ReturnIf(!surface, void());

	CreateTextureFromSurface(surface, outTexture);
	ReturnIf(!outTexture, void());

	DestroySurface(surface);
}

// =============================================================================
void Texture::CreateTextureFromText(SDL_Texture*& outTexture,
	TextTextureParameters& inOutParams)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromText(surface, inOutParams);
	ReturnIf(!surface, void());

	CreateTextureFromSurface(surface, outTexture);
	ReturnIf(!outTexture, void());

	DestroySurface(surface);
}

// =============================================================================
void Texture::SetTextureBlendMode(SDL_Texture*& texture, const EBlendMode& blendMode)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, SDL_BlendMode(blendMode)),
		void(), "SDL_SetTextureBlendMode() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
void Texture::SetTextureAlphaMod(SDL_Texture* texture, int32_t alpha)
{
	if (alpha < Constants::ZeroOpacity)
	{
		alpha = Constants::ZeroOpacity;
	}

	if (alpha > Constants::FullOpacity)
	{
		alpha = Constants::FullOpacity;
	}

	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, (uint8_t)alpha),
		void(), "SDL_SetTextureAlphaMod() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
void Texture::DestroySurface(SDL_Surface*& outSurface)
{
	ReturnIf(!outSurface, void());

	SDL_FreeSurface(outSurface);
	outSurface = nullptr;
}

// =============================================================================
void Texture::DestroyTexture(SDL_Texture*& outTexture)
{
	ReturnIf(!outTexture, void());

	SDL_DestroyTexture(outTexture);
	outTexture = nullptr;
}