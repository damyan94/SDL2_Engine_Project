#ifndef DEFINES_IMAGEDEFINES_H_
#define DEFINES_IMAGEDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"

// Forward declarations

struct ImageInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
	int32_t frames = 1;
};

extern const std::vector<ImageInfo> imagesInfo;

#define IMAGES_COUNT imagesInfo.size();

#endif // !DEFINES_IMAGEDEFINES_H_