#pragma once

class Texture;
class FontContainer;

struct DynamicTextData
{
	Texture*			Texture		= nullptr;
	Rectangle			FrameRect	= Rectangle::Undefined;
	std::string			String;
	FontId				FontId		= 0;
	Color				TextColor	= Colors::Black;
	int32_t				WrapWidth	= 0;
};

// Unlike other containers, this one does not receive a configuration, since all these texts
// are created at runtime and could be anything. Also, these texts are created and destroyed
// dynamically, so the container elements are reused
class DynamicTextContainer
{
	friend class AssetManager;

public:
	DynamicTextContainer();
	~DynamicTextContainer();

	bool				DoesAssetExist(DynamicTextId id) const;
	const DynamicTextData& GetData(DynamicTextId id) const;

	TextId				CreateDynamicText(const std::string& text, FontId fontId, Color textColor, int32_t wrapWidth);
	bool				DestroyDynamicText(TextId id);

	void				SetDynamicText(TextId id, const std::string& text);
	void				SetDynamicTextColor(TextId id, const Color& color);

protected:
	bool				Init(const FontContainer& fontContainer);
	void				Deinit();

private:
	const FontContainer* p_FontContainer;

	std::vector<DynamicTextData> m_DynamicTextsContainer;
};