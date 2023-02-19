// Corresponding header
#include "sdl_utils/containers/cfg/SoundContainerCfg.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
SoundCfg::SoundCfg()
	: m_FileName("")
	, m_Id(SoundId::Invalid)
{
}

// =============================================================================
SoundCfg::SoundCfg(const char* fileName, SoundId id)
	: m_FileName(fileName)
	, m_Id(id)
{
}

// =============================================================================
SoundCfg::~SoundCfg()
{
}

// =============================================================================
SoundContainerCfg::SoundContainerCfg()
{
}

// =============================================================================
SoundContainerCfg::~SoundContainerCfg()
{
}

// =============================================================================
//TODO To be called from the ConfigsManager
bool SoundContainerCfg::Read()
{
	//TODO Read data from file and populate the config
	m_SoundsCfgData =
	{

	};

	return true;
}

// =============================================================================
SoundCfgsContainer SoundContainerCfg::GetData() const
{
	return m_SoundsCfgData;
}