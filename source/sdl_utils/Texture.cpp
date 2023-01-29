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

// =============================================================================
// IMG_Load
void Texture::CreateSurfaceFromFile(const std::string& fileName,
	SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight)
{
	outSurface = IMG_Load(fileName.c_str());
	if (!outSurface)
	{
		std::cerr << "Error, IMG_Load() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}

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
	if (!outSurface)
	{
		std::cerr << "Error, TTF_RenderText_Blended() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}

	outWidth = outSurface->w;
	outHeight = outSurface->h;
}

// =============================================================================
// SDL_CreateTextureFromSurface
void Texture::CreateTextureFromSurface(SDL_Surface* surface,
	SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	outTexture = SDL_CreateTextureFromSurface(Renderer::GetInstance(), surface);
	if (!outTexture)
	{
		std::cerr << "Error, SDL_CreateTextureFromSurface() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}

	outWidth = surface->w;
	outHeight = surface->h;
}

// =============================================================================
void Texture::CreateTextureFromFile(const std::string& fileName,
	SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromFile(fileName, surface, outWidth, outHeight);
	if (!surface)
	{
		std::cerr << "Error, CreateSurfaceFromFile() failed." << std::endl;
		return;
	}

	CreateTextureFromSurface(surface, outTexture, outWidth, outHeight);
	if (!outTexture)
	{
		std::cerr << "Error, CreateTextureFromSurface() failed." << std::endl;
		return;
	}

	DestroySurface(surface);
}

// =============================================================================
void Texture::CreateTextureFromText(const String& text, const Color& color,
	TTF_Font* font, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromText(text, color, font, surface, outWidth, outHeight);
	if (!surface)
	{
		std::cerr << "Error, CreateSurfaceFromFile() failed."
			<< std::endl;
		return;
	}

	CreateTextureFromSurface(surface, outTexture, outWidth, outHeight);
	if (!outTexture)
	{
		std::cerr << "Error, CreateTextureFromSurface() failed."
			<< std::endl;
		return;
	}

	DestroySurface(surface);
}

// =============================================================================
// SDL_SetTextureBlendMode
void Texture::SetTextureBlendMode(SDL_Texture*& texture, const BlendMode& blendMode)
{
	if (EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode)))
	{
		std::cerr << "Error, SDL_SetTextureBlendMode() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}
}

// =============================================================================
// SDL_SetTextureAlphaMod
void Texture::SetTextureAlphaMod(SDL_Texture* texture, int32_t alpha)
{
	if (alpha < ZERO_OPACITY)
		alpha = ZERO_OPACITY;

	if (alpha > FULL_OPACITY)
		alpha = FULL_OPACITY;

	if (EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, (uint8_t)alpha))
	{
		std::cerr << "Error, SDL_SetTextureAlphaMod() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}
}

// =============================================================================
// SDL_RenderCopy
void Texture::RenderTexture(SDL_Texture* texture, const Rectangle& srcRect,
	const Rectangle& dstRect, double angle, const Point& center, const FlipMode& flipMode)
{
	using namespace WindowConstants;

	if (!&srcRect || !&dstRect)
	{
		std::cerr << "Error, Texture::RenderTexture() failed. Received invalid src or dst rectangle."
			<< std::endl;
		return;
	}

	bool isInsideWindow = (dstRect.x + dstRect.w > 0 && dstRect.y + dstRect.h > 0)
		&& (dstRect.x < WINDOW_WIDTH && dstRect.y < WINDOW_HEIGHT);
	if (!isInsideWindow)
	{
		return;
	}

	const SDL_Rect src{ srcRect.x, srcRect.y, srcRect.w, srcRect.h };
	const SDL_Rect dst{ dstRect.x, dstRect.y, dstRect.w, dstRect.h };
	const SDL_Point cntr{ center.x, center.y };

	if (EXIT_SUCCESS != SDL_RenderCopyEx(Renderer::GetInstance(), texture,
		&src, &dst, angle, &cntr, (SDL_RendererFlip) flipMode))
	{
		std::cerr << "Error, SDL_RenderCopy() failed. Reason: "
			<< SDL_GetError() << std::endl;
		return;
	}
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