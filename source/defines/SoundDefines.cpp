// Corresponding header
#include "defines/SoundDefines.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
SoundData::SoundData()
	: m_FileName("")
	, m_Id(SoundId::Invalid)
{
}

// =============================================================================
SoundData::~SoundData()
{
}

// =============================================================================
SoundData::SoundData(const char* fileName, SoundId id)
	: m_FileName(fileName)
	, m_Id(id)
{
}

// =============================================================================
const std::vector<SoundData> m_SoundsData =
{

};