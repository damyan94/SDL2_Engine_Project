#ifndef SDL_UTILS_DRAWING_TEXTURE_H_
#define SDL_UTILS_DRAWING_TEXTURE_H_

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

//TODO maybe have this as base class and have ImageTexture and TextTexture that extend it
class Texture
{
public:
	Texture();
	~Texture();

	static void SetRenderer(Renderer* renderer);
	SDL_Texture* Get();

	void CreateTextureFromFile(ImageTextureParameters& inOutParams);
	void CreateTextureFromText(TextTextureParameters& inOutParams);

	void SetTextureBlendMode(const EBlendMode& blendMode);
	void SetTextureAlphaMod(int32_t alpha);

	void DestroyTexture();

private:
	void CreateSurfaceFromFile(SDL_Surface*& outSurface, ImageTextureParameters& inOutParams);
	void CreateSurfaceFromText(SDL_Surface*& outSurface, TextTextureParameters& inOutParams);

	void CreateTextureFromSurface(SDL_Surface* surface);

	void DestroySurface(SDL_Surface*& outSurface);

private:
	SDL_Texture* m_Texture;
};

#endif // !SDL_UTILS_DRAWING_TEXTURE_H_