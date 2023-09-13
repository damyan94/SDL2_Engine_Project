#ifndef COMPONENTS_AUDIO_SOUND_H_
#define COMPONENTS_AUDIO_SOUND_H_

#include "system/components/audio/AudioObject.h"

struct SoundData;

class Sound
	: public AudioObject
{
public:
	Sound();
	~Sound();

	bool				Init(SoundId id);
	void				Deinit();

	void				Play();
	void				Pause(bool paused);
	void				Stop();
	bool				IsPlaying() const;

	void				SetVolume(uint8_t volume);

	uint8_t				GetVolume();

private:
	SoundId				m_SoundId;
	int32_t				m_Channel;

	const SoundData*	m_Data;
};

#endif // !COMPONENTS_AUDIO_SOUND_H_