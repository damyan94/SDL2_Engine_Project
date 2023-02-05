#ifndef SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_
#define SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_

// C/C++ system includes
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"

#include "sdl_utils/containers/AssetContainer.h"

// Forward declarations
struct Mix_Chunk;

//TODO Remove all the static
class SoundContainer
	: public AssetContainer
{
public:
	SoundContainer();
	~SoundContainer();

	bool				Init() final;
	void				Deinit() final;

	static bool			DoesAssetExist(SoundId id);

	static Mix_Chunk*	GetSoundById(SoundId id);

private:
	static std::unordered_map<SoundId, Mix_Chunk*> m_Sounds;
};

#endif // !SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_