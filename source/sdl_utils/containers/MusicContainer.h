#ifndef SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_
#define SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
typedef struct _Mix_Music Mix_Music;
class MusicContainerCfg;

class MusicContainer
{
public:
	MusicContainer();
	~MusicContainer();

	bool				Init(const MusicContainerCfg& cfg);
	void				Deinit();

	bool				DoesAssetExist(MusicId id);

	Mix_Music*			GetMusicById(MusicId id);

private:
	struct MusicUnit
	{
		MusicUnit();
		MusicUnit(Mix_Music* sound);

		~MusicUnit();

		Mix_Music*		m_Music;
	};

	std::unordered_map<MusicId, MusicUnit> m_MusicContainer;
};

#endif // !SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_