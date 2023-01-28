#ifndef DEFINES_MUSICDEFINES_H_
#define DEFINES_MUSICDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"

// Forward declarations

struct MusicInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
};

extern const std::vector<MusicInfo> musicsInfo;

#define MUSICS_COUNT musicsInfo.size();

#endif // !DEFINES_MUSICDEFINES_H_