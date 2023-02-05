#ifndef DEFINES_SOUNDDEFINES_H_
#define DEFINES_SOUNDDEFINES_H_

// C/C++ system includes
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"

// Forward declarations

struct SoundData
{
	SoundData();
	~SoundData();

	SoundData(const char* fileName, SoundId id);

	const char*			m_FileName;
	SoundId				m_Id;
};

extern const std::vector<SoundData> m_SoundsData;

#define SOUNDS_COUNT m_SoundsData.size();

#endif // !DEFINES_SOUNDDEFINES_H_