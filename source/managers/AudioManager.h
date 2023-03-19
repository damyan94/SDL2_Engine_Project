#ifndef MANAGERS_AUDIOMANAGER_H_
#define MANAGERS_AUDIOMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"

#include "defines/id/SoundId.h"
#include "defines/id/MusicId.h"

// Forward declarations
struct AudioManagerConfig;

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	AudioManager(const AudioManager& other) = delete;
	AudioManager(AudioManager&& other) = delete;

	AudioManager& operator=(const AudioManager& other) = delete;
	AudioManager& operator=(AudioManager&& other) = delete;

	bool				Init(const AudioManagerConfig& cfg);
	void				Deinit();

	int32_t				PlaySound(SoundId id, int32_t loops = 0);
	void				PauseSound(int32_t channel, bool paused);
	void				PauseSounds(bool paused);
	void				StopSound(int32_t channel);
	void				StopSounds();

	void				PlayMusic(MusicId id, int32_t loops);
	void				PauseMusic(bool paused);
	void				StopMusic();

	void				SetSoundVolume(int32_t channel, uint8_t volume);
	void				SetSoundsVolume(uint8_t volume);
	void				SetMusicVolume(uint8_t volume);

	uint8_t				GetSoundVolume(int32_t channel);
	uint8_t				GetMusicVolume();

	bool				IsSoundPlaying(int32_t channel);
	bool				IsSoundPaused(int32_t channel);
	bool				IsMusicPlaying();
	bool				IsMusicPaused();
};

extern AudioManager* g_AudioManager;

#endif // !MANAGERS_AUDIOMANAGER_H_