#pragma once

#include "System/SDLUtils/Containers/Data/FontData.h"

typedef struct _TTF_Font TTF_Font;
struct FontContainerConfig;

class FontContainer
{
public:
	bool				DoesAssetExist(FontId id) const;
	const FontData*		GetFontData(FontId id) const;

protected:
	FontContainer();
	~FontContainer();

	bool				Init(const FontContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<FontData> m_FontsContainer;
};