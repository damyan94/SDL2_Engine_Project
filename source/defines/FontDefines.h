#ifndef DEFINES_FONTDEFINES_H_
#define DEFINES_FONTDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/FontId.h"

// Forward declarations

struct FontInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
	int32_t size = 12;
};

extern const std::vector<FontInfo> fontsInfo;

#define FONTS_COUNT fontsInfo.size();

#endif // !DEFINES_FONTDEFINES_H_