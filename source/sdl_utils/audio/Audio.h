#ifndef SDL_UTILS_AUDIO_AUDIO_H_
#define SDL_UTILS_AUDIO_AUDIO_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"

// Forward declarations
struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;

namespace Audio
{
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