#ifndef DEFINES_IMAGEDEFINES_H_
#define DEFINES_IMAGEDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"

// Forward declarations

struct ImageCfg
{
	ImageCfg();
	ImageCfg(const char* fileName, ImageId id, uint32_t frames);

	~ImageCfg();

	const char*			m_FileName;
	ImageId				m_Id;
	uint32_t			m_Frames;
};

typedef std::vector<ImageCfg> ImageCfgsContainer;

class ImageContainerCfg
{
public:
	ImageContainerCfg();
	~ImageContainerCfg();

	bool				Read();
	ImageCfgsContainer	GetData() const;

private:
	ImageCfgsContainer	m_ImagesCfgData;
};

#endif // !DEFINES_IMAGEDEFINES_H_