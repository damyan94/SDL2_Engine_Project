#ifndef SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_
#define SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_

// C/C++ system includes
#include <cstdint>
#include <string>
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"

// Forward declarations

struct ImageConfig
{
	std::string			m_FileName;
	uint32_t			m_Frames;
};

struct ImageContainerConfig
{
	bool				Read();

	std::unordered_map<ImageId, ImageConfig> m_ImageContainerConfig;
};

#endif // !SDL_UTILS_CONTAINERS_CONFIG_IMAGECONTAINERCONFIG_H_