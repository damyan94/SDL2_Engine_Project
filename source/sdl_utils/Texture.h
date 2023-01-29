#ifndef SDL_UTILS_TEXTURE_H_
#define SDL_UTILS_TEXTURE_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "sdl_utils/drawing/DrawObject.h"

// Forward declarations
struct Rectangle;
struct Color;
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

//TODO fix this here as well as in Text.h/cpp
typedef std::string String;

namespace Texture
{
	void CreateSurfaceFromFile(const std::string& fileName, SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight);
	void CreateSurfaceFromText(const String& text, const Color& color, TTF_Font* font, SDL_Surface*& outSurface, int32_t& outWidth, int32_t& outHeight);

	void CreateTextureFromSurface(SDL_Surface* surface, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight);

	void CreateTextureFromFile(const std::string& fileName, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight);
	void CreateTextureFromText(const String& text, const Color& color, TTF_Font* font, SDL_Texture*& outTexture, int32_t& outWidth, int32_t& outHeight);

	void SetTextureBlendMode(SDL_Texture*& texture, const BlendMode& blendMode);
	void SetTextureAlphaMod(SDL_Texture* texture, int32_t alpha);

	void RenderTexture(SDL_Texture* texture, const Rectangle& srcRect, const Rectangle& dstRect, double angle, const Point& center, const FlipMode& flipMode);

	void DestroySurface(SDL_Surface*& outSurface);
	void DestroyTexture(SDL_Texture*& outTexture);
}

#endif // !SDL_UTILS_TEXTURE_H_