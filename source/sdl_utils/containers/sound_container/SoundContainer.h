#ifndef SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDCONTAINER_H_
#define SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/CommonIncludes.h"
#include "sdl_utils/containers/sound_container/SoundData.h"

// Forward declarations
struct Mix_Chunk;
struct SoundContainerConfig;

class SoundContainer
{
public:
	bool				DoesAssetExist(SoundId id) const;
	SoundData			GetSoundData(SoundId id) const;

protected:
	SoundContainer();
	~SoundContainer();

	bool				Init(const SoundContainerConfig& cfg);
	void				Deinit();

private:
	std::unordered_map<SoundId, SoundData> m_SoundContainer;
};

#endif // !SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDCONTAINER_H_