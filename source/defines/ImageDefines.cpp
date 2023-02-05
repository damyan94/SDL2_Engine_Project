// Corresponding header
#include "defines/ImageDefines.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
ImageData::ImageData()
	: m_FileName("")
	, m_Id(ImageId::Invalid)
	, m_Frames(0)
{
}

// =============================================================================
ImageData::~ImageData()
{
}

// =============================================================================
ImageData::ImageData(const char* fileName, ImageId id, uint32_t frames)
	: m_FileName(fileName)
	, m_Id(id)
	, m_Frames(frames)
{
}

// =============================================================================
//TODO Move all this to a .cfg file
const std::vector<ImageData> g_ImagesData =
{

};