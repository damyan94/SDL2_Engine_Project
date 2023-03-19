#ifndef SDL_UTILS_CONTAINERS_MUSIC_CONTAINER_MUSICCONTAINER_H_
#define SDL_UTILS_CONTAINERS_MUSIC_CONTAINER_MUSICCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"
#include "sdl_utils/CommonIncludes.h"
#include "sdl_utils/containers/music_container/MusicData.h"

// Forward declarations
typedef struct _Mix_Music Mix_Music;
struct MusicContainerConfig;

class MusicContainer
{
public:
	bool				DoesAssetExist(MusicId id) const;
	MusicData			GetMusicData(MusicId id) const;

protected:
	MusicContainer();
	~MusicContainer();

	bool				Init(const MusicContainerConfig& cfg);
	void				Deinit();

private:
	std::unordered_map<MusicId, MusicData> m_MusicContainer;
};

#endif // !SDL_UTILS_CONTAINERS_MUSIC_CONTAINER_MUSICCONTAINER_H_