#pragma once

struct StringContainerConfig;

class StringContainer
{
	friend class AssetManager;

public:
	StringContainer();
	~StringContainer();

public:
	bool				DoesAssetExist(StringId id) const;
	const std::string&	GetLocalizedString(ELanguage language, StringId id) const;

protected:
	bool				Init(const StringContainerConfig& cfg);
	void				Deinit();

private:
	std::unordered_map<ELanguage, StringVector> m_StringsContainer;
};