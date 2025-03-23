#pragma once

typedef struct _Mix_Music Mix_Music;
struct MusicContainerConfig;

struct MusicData
{
	Mix_Music*			m_Music		= nullptr;
	uint8_t				m_Volume	= 0;
};

class MusicContainer
{
	friend class AssetManager;

public:
	MusicContainer();
	~MusicContainer();

	bool				DoesAssetExist(MusicId id) const;
	const MusicData&	GetData(MusicId id) const;

protected:
	bool				Init(const MusicContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<MusicData> m_MusicContainer;
};