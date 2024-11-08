#pragma once

#include "system/sdl_utils/containers/music_container/MusicData.h"

typedef struct _Mix_Music Mix_Music;
struct MusicContainerConfig;

class MusicContainer
{
public:
	bool				DoesAssetExist(MusicId id) const;
	const MusicData*	GetMusicData(MusicId id) const;

protected:
	MusicContainer();
	~MusicContainer();

	bool				Init(const MusicContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<MusicData> m_MusicContainer;
};