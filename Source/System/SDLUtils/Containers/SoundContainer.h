#pragma once

struct Mix_Chunk;
struct SoundContainerConfig;

struct SoundData
{
	Mix_Chunk*			m_Sound		= nullptr;
	uint8_t				m_Volume	= 0;
};

class SoundContainer
{
	friend class AssetManager;

public:
	SoundContainer();
	~SoundContainer();

	bool				DoesAssetExist(SoundId id) const;
	const SoundData&	GetData(SoundId id) const;

protected:
	bool				Init(const SoundContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<SoundData> m_SoundContainer;
};