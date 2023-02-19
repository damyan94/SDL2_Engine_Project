// Corresponding header
#include "sdl_utils/containers/cfg/ImageContainerCfg.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
ImageCfg::ImageCfg()
	: m_FileName("")
	, m_Id(ImageId::Invalid)
	, m_Frames(0)
{
}

// =============================================================================
ImageCfg::ImageCfg(const char* fileName, ImageId id, uint32_t frames)
	: m_FileName(fileName)
	, m_Id(id)
	, m_Frames(frames)
{
}

// =============================================================================
ImageCfg::~ImageCfg()
{
}

// =============================================================================
ImageContainerCfg::ImageContainerCfg()
{
}

ImageContainerCfg::~ImageContainerCfg()
{
}

// =============================================================================
//TODO To be called from the ConfigsManager
bool ImageContainerCfg::Read()
{
	//TODO Read data from file and populate the config
	m_ImagesCfgData =
	{

	};

	return true;
}

// =============================================================================
ImageCfgsContainer ImageContainerCfg::GetData() const
{
	return m_ImagesCfgData;
}