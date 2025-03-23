#pragma once

#include "System/Components/Audio/AudioObject.h"

class Sound
	: public AudioObject
{
public:
	Sound();
	~Sound();

	bool				Init(SoundId id);
	void				Deinit();

private:
	int32_t				m_Channel;
};