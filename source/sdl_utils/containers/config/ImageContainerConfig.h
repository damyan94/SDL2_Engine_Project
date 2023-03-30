#ifndef SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

// Forward declarations

struct ImageConfig
{
	std::string			m_FileName;
	uint32_t			m_Frames				= 0;
};

struct ImageContainerConfig
{
	bool				Read(const ConfigStrings& readStrings);

	std::unordered_map<ImageId, ImageConfig> m_ImageContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_