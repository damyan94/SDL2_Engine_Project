#pragma once

#include "System/Components/Audio/AudioObject.h"

struct MusicData;

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

	const MusicData*	m_Data;
};