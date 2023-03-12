#ifndef SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_
#define SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/SoundId.h"
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
struct Mix_Chunk;
struct SoundContainerConfig;

class SoundContainer
{
public:
	SoundContainer();
	~SoundContainer();

	bool				Init(const SoundContainerConfig& cfg);
	void				Deinit();

	bool				DoesAssetExist(SoundId id);

	Mix_Chunk*			GetSoundById(SoundId id);

private:
	struct SoundUnit
	{
		SoundUnit();
		SoundUnit(Mix_Chunk* sound);

		~SoundUnit();

		Mix_Chunk*		m_Sound;
	};

	std::unordered_map<SoundId, SoundUnit> m_SoundContainer;
};

#endif // !SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_