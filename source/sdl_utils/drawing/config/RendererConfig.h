#ifndef SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_
#define SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/drawing/Color.h"

// Forward declarations

struct RendererConfig
{
	Color				m_Color;
	int32_t				m_Flags;
};

#endif // !SDL_UTILS_DRAWING_CONFIG_RENDERERCONFIG_H_