// Corresponding header
#include "defines/MusicDefines.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
MusicData::MusicData()
	: m_FileName("")
	, m_Id(MusicId::Invalid)
{
}

// =============================================================================
MusicData::~MusicData()
{
}

// =============================================================================
MusicData::MusicData(const char* fileName, MusicId id)
	: m_FileName(fileName)
	, m_Id(id)
{
}

// =============================================================================
const std::vector<MusicData> m_MusicsData =
{

};