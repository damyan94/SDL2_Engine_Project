// Corresponding header
#include "sdl_utils/containers/cfg/MusicContainerCfg.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
MusicCfg::MusicCfg()
	: m_FileName("")
	, m_Id(MusicId::Invalid)
{
}

// =============================================================================
MusicCfg::~MusicCfg()
{
}

// =============================================================================
MusicCfg::MusicCfg(const char* fileName, MusicId id)
	: m_FileName(fileName)
	, m_Id(id)
{
}

// =============================================================================
MusicContainerCfg::MusicContainerCfg()
{
}

// =============================================================================
MusicContainerCfg::~MusicContainerCfg()
{
}

// =============================================================================
//TODO To be called from the ConfigsManager
bool MusicContainerCfg::Read()
{
	//TODO Read data from file and populate the config
	m_MusicsCfgData =
	{

	};

	return true;
}

// =============================================================================
MusicCfgsContainer MusicContainerCfg::GetData() const
{
	return m_MusicsCfgData;
}