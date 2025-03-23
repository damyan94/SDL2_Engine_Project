#pragma once

typedef struct _TTF_Font TTF_Font;
struct FontContainerConfig;

struct FontData
{
	TTF_Font*			Font		= nullptr;
	uint8_t				Size		= 0;
	EFontWrapAlign		WrapAlign	= EFontWrapAlign::Invalid;
};

class FontContainer
{
	friend class AssetManager;

public:
	FontContainer();
	~FontContainer();

	bool				DoesAssetExist(FontId id) const;
	const FontData&		GetData(FontId id) const;

protected:
	bool				Init(const FontContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<FontData> m_FontsContainer;
};