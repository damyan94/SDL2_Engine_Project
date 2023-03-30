#ifndef SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_
#define SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "utils/drawing/Color.h"

// Forward declarations

struct RendererConfig
{
	bool				Read(const ConfigStrings& readStrings);

	Color				m_DrawColor;
	int32_t				m_Flags;
};

#endif // !SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_