#include "stdafx.h"

#include "Application/Application/ConfigManager.h"

#include "System/Defines/ConfigFilePaths.h"

#include "System/SDLUtils/Containers/Config/ImageContainerConfig.h"
#include "System/SDLUtils/Containers/Config/StringContainerConfig.h"
#include "System/SDLUtils/Containers/Config/FontContainerConfig.h"
#include "System/SDLUtils/Containers/Config/TextContainerConfig.h"
#include "System/SDLUtils/Containers/Config/SoundContainerConfig.h"
#include "System/SDLUtils/Containers/Config/MusicContainerConfig.h"

////////////////////////////////////////////////////////////////////////////////
ConfigManager::ConfigManager()
{
}

////////////////////////////////////////////////////////////////////////////////
ConfigManager::~ConfigManager()
{
}

////////////////////////////////////////////////////////////////////////////////
ConfigManager& ConfigManager::Instance()
{
	static ConfigManager instance;
	return instance;
}

////////////////////////////////////////////////////////////////////////////////
bool ConfigManager::ReadConfigs()
{
	m_Data.clear();

	ReturnIf(!ReadConfig<ImageContainerConfig>(ConfigFilePaths::ImageConfig), false);
	ReturnIf(!ReadConfig<StringContainerConfig>(ConfigFilePaths::StringConfig), false);
	ReturnIf(!ReadConfig<FontContainerConfig>(ConfigFilePaths::FontConfig), false);
	ReturnIf(!ReadConfig<TextContainerConfig>(ConfigFilePaths::TextConfig), false);
	ReturnIf(!ReadConfig<SoundContainerConfig>(ConfigFilePaths::SoundConfig), false);
	ReturnIf(!ReadConfig<MusicContainerConfig>(ConfigFilePaths::MusicConfig), false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
IConfig* ConfigManager::Get(std::type_index typeId) const
{
	const auto it = m_Data.find(typeId);
	AssertReturnIf(it == m_Data.end(), nullptr);

	return it->second.get();
}