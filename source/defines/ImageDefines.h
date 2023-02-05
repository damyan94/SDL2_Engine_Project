#ifndef DEFINES_IMAGEDEFINES_H_
#define DEFINES_IMAGEDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"

// Forward declarations

struct ImageData
{
	ImageData();
	~ImageData();

	ImageData(const char* fileName, ImageId id, uint32_t frames);

	const char*			m_FileName;
	ImageId				m_Id;
	uint32_t			m_Frames;
};

extern const std::vector<ImageData> g_ImagesData;

#define IMAGES_COUNT g_ImagesData.size();

#endif // !DEFINES_IMAGEDEFINES_H_