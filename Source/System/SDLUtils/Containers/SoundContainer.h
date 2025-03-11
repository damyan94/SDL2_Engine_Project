#pragma once

#include "System/SDLUtils/Containers/Data/SoundData.h"

struct Mix_Chunk;
struct SoundContainerConfig;

class SoundContainer
{
public:
	bool				DoesAssetExist(SoundId id) const;
	const SoundData&	GetSoundData(SoundId id) const;

protected:
	SoundContainer();
	~SoundContainer();

	bool				Init(const SoundContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<SoundData> m_SoundContainer;
};