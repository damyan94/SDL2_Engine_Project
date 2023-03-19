#ifndef COMPONENTS_AUDIO_AUDIOOBJECT_H_
#define COMPONENTS_AUDIO_AUDIOOBJECT_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"
#include "utils/audio/AudioParameters.h"

// Forward declarations

class AudioObject
{
public:
	AudioObject();
	~AudioObject();

	void				Reset();

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

#endif // !COMPONENTS_AUDIO_AUDIOOBJECT_H_