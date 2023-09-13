#ifndef SDL_UTILS_AUDIO_AUDIO_H_
#define SDL_UTILS_AUDIO_AUDIO_H_

struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;

namespace Audio
{
bool				CreateSoundFromFile(Mix_Chunk*& outSound, const std::string& fileName);
bool				CreateMusicFromFile(Mix_Music*& outMusic, const std::string& fileName);

void				DestroySound(Mix_Chunk*& outSound);
void				DestroyMusic(Mix_Music*& outMusic);

int32_t				PlaySound(Mix_Chunk* chunk, int32_t loops = 0);
void				TogglePauseSound(int32_t channel);
void				TogglePauseSounds();
void				StopSound(int32_t channel);
void				StopSounds();

void				PlayMusic(Mix_Music* music, int32_t loops);
void				TogglePauseMusic();
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

#endif // !SDL_UTILS_AUDIO_AUDIO_H_