// Corresponding header
#include "sdl_utils/Texture.h"

// C/C++ system includes
#include <iostream>

// Third-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// Own includes
#include "defines/consts/GlobalConstants.h"

#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

#include "sdl_utils/Renderer.h"
#include "sdl_utils/drawing/DrawObject.h"

//TODO Refactor
#include "managers/DrawManager.h"

// =============================================================================
// IMG_Load
void Texture::CreateSurfaceFromFile(const std::string& fileName,
	SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight)
{
	outSurface = IMG_Load(fileName.c_str());
	AssertReturnIf(!outSurface);

	outWidth = outSurface->w;
	outHeight = outSurface->h;
}

// =============================================================================
// TTF_RenderText_Solid
void Texture::CreateSurfaceFromText(const String& text, const Color& color,
	TTF_Font* font,	SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight)
{
	outSurface = TTF_RenderText_Blended(font, text.c_str(),
		SDL_Color{ color.r, color.g, color.b, color.a });
	//outSurface = TTF_RenderUNICODE_Blended(font, reinterpret_cast<const uint16_t*>(text.c_str()),
	//	SDL_Color{ color.r, color.g, color.b, color.a });
	AssertReturnIf(!outSurface);

	outWidth = outSurface->w;
	outHeight = outSurface->h;
}

// =============================================================================
// SDL_CreateTextureFromSurface
void Texture::CreateTextureFromSurface(SDL_Surface* surface,
	SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	outTexture = SDL_CreateTextureFromSurface(DrawManager::Get()->GetRenderer()->GetInstance(), surface);
	AssertReturnIf(!outTexture);

	outWidth = surface->w;
	outHeight = surface->h;
}

// =============================================================================
void Texture::CreateTextureFromFile(const std::string& fileName,
	SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromFile(fileName, surface, outWidth, outHeight);
	AssertReturnIf(!surface);

	CreateTextureFromSurface(surface, outTexture, outWidth, outHeight);
	AssertReturnIf(!outTexture);

	DestroySurface(surface);
}

// =============================================================================
void Texture::CreateTextureFromText(const String& text, const Color& color,
	TTF_Font* font, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromText(text, color, font, surface, outWidth, outHeight);
	AssertReturnIf(!surface);

	CreateTextureFromSurface(surface, outTexture, outWidth, outHeight);
	AssertReturnIf(!outTexture);

	DestroySurface(surface);
}

// =============================================================================
// SDL_SetTextureBlendMode
void Texture::SetTextureBlendMode(SDL_Texture*& texture, const BlendMode& blendMode)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode)));
}

// =============================================================================
// SDL_SetTextureAlphaMod
void Texture::SetTextureAlphaMod(SDL_Texture* texture, int32_t alpha)
{
	if (alpha < ZERO_OPACITY)
		alpha = ZERO_OPACITY;

	if (alpha > FULL_OPACITY)
		alpha = FULL_OPACITY;

	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, (uint8_t)alpha));
}

// =============================================================================
// SDL_RenderCopy
void Texture::RenderTexture(SDL_Texture* texture, const Rectangle& srcRect,
	const Rectangle& dstRect, double angle, const Point& center, const FlipMode& flipMode)
{
	using namespace WindowConstants;

	AssertReturnIf(!&srcRect || !&dstRect);

	bool isInsideWindow = (dstRect.x + dstRect.w > 0 && dstRect.y + dstRect.h > 0)
		&& (dstRect.x < WINDOW_WIDTH && dstRect.y < WINDOW_HEIGHT);
	ReturnIf(!isInsideWindow);

	const SDL_Rect src{ srcRect.x, srcRect.y, srcRect.w, srcRect.h };
	const SDL_Rect dst{ dstRect.x, dstRect.y, dstRect.w, dstRect.h };
	const SDL_Point cntr{ center.x, center.y };

	AssertReturnIf(EXIT_SUCCESS != SDL_RenderCopyEx(DrawManager::Get()->GetRenderer()->GetInstance(), texture,
		&src, &dst, angle, &cntr, (SDL_RendererFlip)flipMode));
}

// =============================================================================
// SDL_FreeSurface
void Texture::DestroySurface(SDL_Surface*& outSurface)
{
	if (outSurface)
	{
		SDL_FreeSurface(outSurface);
		outSurface = nullptr;
	}
}

// =============================================================================
// SDL_DestroyTexture
void Texture::DestroyTexture(SDL_Texture*& outTexture)
{
	if (outTexture)
	{
		SDL_DestroyTexture(outTexture);
		outTexture = nullptr;
	}
}