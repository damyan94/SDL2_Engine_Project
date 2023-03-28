#ifndef COMPONENTS_AUDIO_SOUND_H_
#define COMPONENTS_AUDIO_SOUND_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"
#include "components/audio/AudioObject.h"

// Forward declarations

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
};

#endif // !COMPONENTS_AUDIO_SOUND_H_