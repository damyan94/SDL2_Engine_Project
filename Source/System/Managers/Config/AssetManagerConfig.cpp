#include "stdafx.h"

#include "System/Managers/Config/AssetManagerConfig.h"
#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool AssetManagerConfig::Read()
{
	ReturnIf(!ImageContainerConfig.Read(File(ConfigFilePaths::ImageConfig).GetFileContents()), false);
	ReturnIf(!StringContainerConfig.Read(File(ConfigFilePaths::StringConfig).GetFileContents()), false);
	ReturnIf(!FontContainerConfig.Read(File(ConfigFilePaths::FontConfig).GetFileContents()), false);
	ReturnIf(!TextContainerConfig.Read(File(ConfigFilePaths::TextConfig).GetFileContents()), false);
	ReturnIf(!SoundContainerConfig.Read(File(ConfigFilePaths::SoundConfig).GetFileContents()), false);
	ReturnIf(!MusicContainerConfig.Read(File(ConfigFilePaths::MusicConfig).GetFileContents()), false);

	return true;
}