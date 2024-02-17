#ifndef SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDCONTAINER_H_
#define SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDCONTAINER_H_

#include "system/sdl_utils/containers/sound_container/SoundData.h"

struct Mix_Chunk;
struct SoundContainerConfig;

class SoundContainer
{
public:
	bool				DoesAssetExist(SoundId id) const;
	const SoundData*	GetSoundData(SoundId id) const;

protected:
	SoundContainer();
	~SoundContainer();

	bool				Init(const SoundContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<SoundData> m_SoundContainer;
};

#endif // !SDL_UTILS_CONTAINERS_SOUND_CONTAINER_SOUNDCONTAINER_H_