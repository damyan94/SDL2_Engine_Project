#ifndef SDL_UTILS_RENDERER_H_
#define SDL_UTILS_RENDERER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/drawing/Color.h"

// Forward declarations
struct SDL_Renderer;
struct SDL_Window;

class Renderer
{
public:
	static SDL_Renderer* GetInstance();

	int32_t Init(SDL_Window* window, const Color& color);
	void Deinit();
	void Update();
	void Draw() const;

	static void SetDrawColor(const Color& color);
	static Color GetDefaultDrawColor();

private:
	static SDL_Renderer* _gRenderer;
	static Color _defaultDrawColor;
};

#endif // !SDL_UTILS_RENDERER_H_