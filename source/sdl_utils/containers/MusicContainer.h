#ifndef SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_
#define SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "defines/id/MusicId.h"
#include "utils/UtilsCommonIncludes.h"

// Forward declarations
typedef struct _Mix_Music Mix_Music;
struct MusicContainerConfig;

class MusicContainer
{
public:
	MusicContainer();
	~MusicContainer();

	bool				Init(const MusicContainerConfig& cfg);
	void				Deinit();

	bool				DoesAssetExist(MusicId id);

	Mix_Music*			GetMusicById(MusicId id);

private:
	struct MusicData
	{
		MusicData();
		MusicData(Mix_Music* sound);

		~MusicData();

		Mix_Music*		m_Music;
	};

	std::unordered_map<MusicId, MusicData> m_MusicContainer;
};

#endif // !SDL_UTILS_CONTAINERS_MUSICCONTAINER_H_