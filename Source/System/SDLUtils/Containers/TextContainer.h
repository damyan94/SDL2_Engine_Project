#pragma once

#include "System/SDLUtils/Containers/Data/TextData.h"

struct TextContainerConfig;

class TextContainer
{
public:
	bool				DoesAssetExist(TextId id) const;
	const TextData*		GetTextData(TextId id) const;

	bool				UpdateText(TextId id, FontId fontId, const Color& color, int32_t wrapWidth);
	bool				UpdateAllTexts();

	void				ChangeLanguage(ELanguage newLanguage);

protected:
	TextContainer();
	~TextContainer();

	bool				Init(const TextContainerConfig& cfg);
	void				Deinit();

private:
	ELanguage			m_CurrLanguage;

	std::vector<TextData> m_TextsContainer;
};