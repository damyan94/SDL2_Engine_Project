#ifndef COMPONENTS_AUDIO_MUSIC_H_
#define COMPONENTS_AUDIO_MUSIC_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"
#include "components/audio/AudioObject.h"

// Forward declarations

class Music
	: public AudioObject
{
public:
	Music();
	~Music();

	bool				Init(MusicId id);
	void				Deinit();

	void				Play();
	void				Pause(bool paused);
	void				Stop();
	bool				IsPlaying() const;

	void				SetVolume(uint8_t volume);

	uint8_t				GetVolume();

private:
	MusicId				m_MusicId;
};

#endif // !COMPONENTS_AUDIO_MUSIC_H_