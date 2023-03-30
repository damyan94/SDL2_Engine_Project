#ifndef SDL_UTILS_UTILS_H_
#define SDL_UTILS_UTILS_H_

// C/C++ system includes
#include <cstdint>
#include <string>

// Third-party includes

// Own includes
#include "sdl_utils/Defines.h"

// Forward declarations

namespace Utils
{
ELanguage				GetLanguageIdFromString(const std::string& langString);
std::string				GetLanguageStringFromId(ELanguage id);
} // !namespace Utils

#endif // !SDL_UTILS_UTILS_H_