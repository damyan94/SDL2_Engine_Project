#pragma once

#include "System/SDLUtils/Audio/AudioParameters.h"

class AudioObject
{
public:
	AudioObject();
	~AudioObject();

	const AudioParameters& GetAudioParameters() const;
	void				Reset();

	void				Play();
	void				Pause(bool paused);
	void				Stop();
	bool				IsPlaying() const;

	// Getters
	int32_t				GetLoops() const;
	bool				GetLoopInfinitely() const;
	uint8_t				GetVolume() const;
	uint8_t				GetMaxVolume() const;
	EObjectType			GetObjectType() const;

	// Setters
	void				SetLoops(int32_t loops);
	void				SetLoopInfinitely(bool loopInfinitely);
	void				SetVolume(uint8_t volume);
	void				SetMaxVolume(uint8_t volume);
	void				SetObjectType(EObjectType type);

	// Others

protected:
	AudioParameters		m_AudioParameters;
};