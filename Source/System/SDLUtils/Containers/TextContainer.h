#pragma once

class Texture;

class FontContainer;
class StringContainer;

struct TextContainerConfig;

struct TextData
{
	Texture*			Texture		= nullptr;
	Rectangle			FrameRect	= Rectangle::Undefined;
	StringId			StringId	= 0;
	FontId				FontId		= 0;
	Color				TextColor	= Colors::Black;
	int32_t				WrapWidth	= 0;
};

class TextContainer
{
	friend class AssetManager;

public:
	TextContainer();
	~TextContainer();

	bool				DoesAssetExist(TextId id) const;
	const TextData&		GetData(TextId id) const;

	bool				UpdateText(TextId id, FontId fontId, const Color& color, int32_t wrapWidth);
	bool				UpdateText(TextId id, FontId fontId, const Color& color, int32_t wrapWidth, const std::vector<std::string>& values);
	bool				UpdateAllTexts();

	void				ChangeLanguage(ELanguage newLanguage);

protected:
	bool				Init(const TextContainerConfig& cfg, const StringContainer& stringContainer, const FontContainer& fontContainer);
	void				Deinit();

private:
	const StringContainer*		p_StringContainer;
	const FontContainer*		p_FontContainer;

	const TextContainerConfig*	m_TextContainerConfig;
	ELanguage					m_CurrLanguage;

	std::vector<TextData>		m_TextsContainer;
};