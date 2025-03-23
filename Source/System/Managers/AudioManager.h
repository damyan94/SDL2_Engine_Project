#pragma once

struct AudioManagerConfig;
struct AudioParameters;

class AudioManager
	: public INonCopyMoveable
{
private:
	AudioManager();
	~AudioManager();

public:
	static AudioManager& Instance();

	bool				Init(const AudioManagerConfig& cfg);
	void				Deinit();

	int32_t				PlaySound(const AudioParameters& data);
	void				PauseSound(int32_t channel, bool paused);
	void				PauseSounds(bool paused);
	void				StopSound(int32_t channel);
	void				StopSounds();

	void				PlayMusic(const AudioParameters& data);
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