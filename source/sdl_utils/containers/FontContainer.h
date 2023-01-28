#ifndef SDL_UTILS_CONTAINERS_FONTCONTAINER_H_
#define SDL_UTILS_CONTAINERS_FONTCONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/drawing/Color.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
typedef struct _TTF_Font TTF_Font;

class FontContainer
{
public:
	~FontContainer();

	int32_t Init();
	void Deinit();

	static TTF_Font* GetFontById(int32_t id);
	static int32_t GetFontSizeById(int32_t id);

private:
	struct FontUnit
	{
		TTF_Font* font = nullptr;
		int32_t size = 12;
	};

	static std::unordered_map<int32_t, FontUnit> _fonts;
};

#endif // !SDL_UTILS_CONTAINERS_FONTCONTAINER_H_