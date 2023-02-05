#ifndef SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_
#define SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_

// C/C++ system includes
#include <unordered_map>

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"

#include "sdl_utils/containers/AssetContainer.h"

// Forward declarations
typedef struct _Mix_Music Mix_Music;

//TODO Remove all the static
class MusicContainer
	: public AssetContainer
{
public:
	MusicContainer();
	~MusicContainer();

	bool				Init() final;
	void				Deinit() final;

	static bool			DoesAssetExist(MusicId id);

	static Mix_Music*	GetMusicById(MusicId id);

private:
	static std::unordered_map<MusicId, Mix_Music*> m_Musics;
};

#endif // !SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_