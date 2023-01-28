#ifndef DEFINES_SOUNDDEFINES_H_
#define DEFINES_SOUNDDEFINES_H_

// C/C++ system includes
#include <cstdint>
#include <vector>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"

// Forward declarations

struct SoundInfo
{
	const char* fileName = "INVALID FILE NAME";
	int32_t id = -1;
};

extern const std::vector<SoundInfo> soundsInfo;

#define SOUNDS_COUNT soundsInfo.size();

#endif // !DEFINES_SOUNDDEFINES_H_