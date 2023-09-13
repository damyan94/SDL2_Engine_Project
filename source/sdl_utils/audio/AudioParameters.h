#ifndef SDL_UTILS_AUDIO_AUDIOPARAMETERS_H_
#define SDL_UTILS_AUDIO_AUDIOPARAMETERS_H_

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

#endif // !SDL_UTILS_AUDIO_AUDIOPARAMETERS_H_