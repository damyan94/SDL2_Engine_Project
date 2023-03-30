#ifndef SDL_UTILS_DRAWING_TEXTURE_H_
#define SDL_UTILS_DRAWING_TEXTURE_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "utils/drawing/Color.h"

// Forward declarations
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
class Renderer;

struct ImageTextureParameters
{
	const std::string	m_FileName;
	int32_t				m_Width			= 0;
	int32_t				m_Height		= 0;
};

struct TextTextureParameters
{
	const std::string	m_String;
	const TTF_Font*		m_Font			= nullptr;
	const Color			m_TextColor		= Colors::Black;
	const int32_t		m_WrapWidth		= 0;
	int32_t				m_Width			= 0;
	int32_t				m_Height		= 0;
};

namespace Texture
{
void SetRenderer(Renderer* renderer);

void CreateSurfaceFromFile(SDL_Surface*& outSurface, ImageTextureParameters& inOutParams);
void CreateSurfaceFromText(SDL_Surface*& outSurface, TextTextureParameters& inOutParams);

void CreateTextureFromSurface(SDL_Surface* surface, SDL_Texture*& outTexture);

void CreateTextureFromFile(SDL_Texture*& outTexture, ImageTextureParameters& inOutParams);
void CreateTextureFromText(SDL_Texture*& outTexture, TextTextureParameters& inOutParams);

void SetTextureBlendMode(SDL_Texture*& texture, const EBlendMode& blendMode);
void SetTextureAlphaMod(SDL_Texture* texture, int32_t alpha);

void DestroySurface(SDL_Surface*& outSurface);
void DestroyTexture(SDL_Texture*& outTexture);
}

#endif // !SDL_UTILS_DRAWING_TEXTURE_H_