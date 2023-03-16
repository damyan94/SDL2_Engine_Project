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
#include "sdl_utils/Window.h"
#include "sdl_utils/drawing/DrawObject.h"

//TODO Refactor
#include "managers/DrawManager.h"
#include "managers/ManagerHandler.h"

// =============================================================================
// IMG_Load
void Texture::CreateSurfaceFromFile(const std::string& fileName,
	SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight)
{
	outSurface = IMG_Load(fileName.c_str());
	AssertReturnIf(!outSurface, void(), "IMG_Load() failed: " + std::string(SDL_GetError()));

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
	AssertReturnIf(!outSurface, void(), "TTF_RenderText_Blended() failed: " +
		std::string(SDL_GetError()));

	outWidth = outSurface->w;
	outHeight = outSurface->h;
}

// =============================================================================
// SDL_CreateTextureFromSurface
void Texture::CreateTextureFromSurface(SDL_Surface* surface, SDL_Texture*& outTexture)
{
	outTexture = SDL_CreateTextureFromSurface(g_DrawManager->GetRenderer()->GetBaseObject(), surface);
	AssertReturnIf(!outTexture, void(), "SDL_CreateTextureFromSurface() failed: " +
		std::string(SDL_GetError()));
}

// =============================================================================
void Texture::CreateTextureFromFile(const std::string& fileName,
	SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromFile(fileName, surface, outWidth, outHeight);
	ReturnIf(!surface, void());

	CreateTextureFromSurface(surface, outTexture);
	ReturnIf(!outTexture, void());

	DestroySurface(surface);
}

// =============================================================================
void Texture::CreateTextureFromText(const String& text, const Color& color,
	TTF_Font* font, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight)
{
	SDL_Surface* surface = nullptr;
	CreateSurfaceFromText(text, color, font, surface, outWidth, outHeight);
	ReturnIf(!surface, void());

	CreateTextureFromSurface(surface, outTexture);
	ReturnIf(!outTexture, void());

	DestroySurface(surface);
}

// =============================================================================
// SDL_SetTextureBlendMode
void Texture::SetTextureBlendMode(SDL_Texture*& texture, const BlendMode& blendMode)
{
	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode)),
		void(), "SDL_SetTextureBlendMode() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
// SDL_SetTextureAlphaMod
void Texture::SetTextureAlphaMod(SDL_Texture* texture, int32_t alpha)
{
	if (alpha < ZERO_OPACITY)
	{
		alpha = ZERO_OPACITY;
	}

	if (alpha > FULL_OPACITY)
	{
		alpha = FULL_OPACITY;
	}

	AssertReturnIf(EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, (uint8_t)alpha),
		void(), "SDL_SetTextureAlphaMod() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
// SDL_RenderCopy
//TODO Move to renderer
void Texture::RenderTexture(SDL_Texture* texture, const Rectangle& srcRect,
	const Rectangle& dstRect, double angle, const Point& center, const FlipMode& flipMode)
{
	using namespace WindowConstants;
	static Window* gWindow = g_DrawManager->GetWindow();

	AssertReturnIf(!&srcRect || !&dstRect, void(),
		"Received invalid source or destination rectangle.");

	bool isInsideWindow = (dstRect.x + dstRect.w > 0 && dstRect.y + dstRect.h > 0)
		&& (dstRect.x < gWindow->GetWindowRect().w && dstRect.y < gWindow->GetWindowRect().h);
	ReturnIf(!isInsideWindow, void());

	const SDL_Rect src{ srcRect.x, srcRect.y, srcRect.w, srcRect.h };
	const SDL_Rect dst{ dstRect.x, dstRect.y, dstRect.w, dstRect.h };
	const SDL_Point cntr{ center.x, center.y };

	AssertReturnIf(EXIT_SUCCESS != SDL_RenderCopyEx(g_DrawManager->GetRenderer()->GetBaseObject(), texture,
		&src, &dst, angle, &cntr, (SDL_RendererFlip)flipMode),
		void(), "SDL_RenderCopyEx() failed: " + std::string(SDL_GetError()));
}

// =============================================================================
// SDL_FreeSurface
void Texture::DestroySurface(SDL_Surface*& outSurface)
{
	ReturnIf(!outSurface, void());

	SDL_FreeSurface(outSurface);
	outSurface = nullptr;
}

// =============================================================================
// SDL_DestroyTexture
void Texture::DestroyTexture(SDL_Texture*& outTexture)
{
	ReturnIf(!outTexture, void());

	SDL_DestroyTexture(outTexture);
	outTexture = nullptr;
}