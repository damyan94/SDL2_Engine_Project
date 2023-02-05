#ifndef DEFINES_MUSICDEFINES_H_
#define DEFINES_MUSICDEFINES_H_

// C/C++ system includes
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"

// Forward declarations

struct MusicData
{
	MusicData();
	~MusicData();

	MusicData(const char* fileName, MusicId id);

	const char*			m_FileName;
	MusicId				m_Id;
};

extern const std::vector<MusicData> m_MusicsData;

#define MUSICS_COUNT m_MusicsData.size();

#endif // !DEFINES_MUSICDEFINES_H_