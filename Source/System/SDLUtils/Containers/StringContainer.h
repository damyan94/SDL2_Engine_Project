#pragma once

struct StringContainerConfig;

struct StringData
{
	const std::string&	GetLocalizedString(ELanguage language) const;

	LanguageStringMap	LanguageStrings;
};

class StringContainer
{
	friend class AssetManager;

public:
	StringContainer();
	~StringContainer();

public:
	bool				DoesAssetExist(StringId id) const;
	const StringData&	GetStringData(StringId id) const;

protected:
	bool				Init(const StringContainerConfig& cfg);
	void				Deinit();

private:
	std::vector<StringData> m_StringsContainer;
};