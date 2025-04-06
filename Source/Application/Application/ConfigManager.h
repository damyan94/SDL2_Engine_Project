#pragma once

#include "System/Utils/Others/IConfig.h"

class ConfigManager
	: public INonCopyMoveable
{
private:
	ConfigManager();
	~ConfigManager();

public:
	static ConfigManager& Instance();

	bool ReadConfigs();

	IConfig* Get(std::type_index) const;

	template <typename T>
	const T& Get() const;

private:
	template <typename T>
	bool ReadConfig(const std::string& filename);

private:
	std::unordered_map<std::type_index, std::unique_ptr<IConfig>> m_Data;
};

////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline const T& ConfigManager::Get() const
{
	const std::type_index typeId = typeid(T);

	return *(dynamic_cast<T*>(Get(typeId)));
}

////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline bool ConfigManager::ReadConfig(const std::string& filename)
{
	m_Data[typeid(T)] = std::make_unique<T>();
	AssertReturnIf(!m_Data[typeid(T)]->Parse(File(filename).GetFileContents()), false);

	return true;
}