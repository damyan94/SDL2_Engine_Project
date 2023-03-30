#ifndef UTILS_AUDIO_AUDIOPARAMETERS_H_
#define UTILS_AUDIO_AUDIOPARAMETERS_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"

// Forward declarations

struct AudioParameters
{
	AudioParameters();
	~AudioParameters();

	void				Reset();

	int32_t				m_Loops;
	bool				m_LoopInfinitely;

	uint8_t				m_Volume;
	uint8_t				m_MaxVolume;

	EObjectType			m_ObjectType;
};

#endif // !UTILS_AUDIO_AUDIOPARAMETERS_H_