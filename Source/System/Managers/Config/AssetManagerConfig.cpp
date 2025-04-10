#include "stdafx.h"

#include "System/Managers/Config/AssetManagerConfig.h"
#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool AssetManagerConfig::Read()
{
	ReturnIf(!ImageContainerConfig.Read(File(ConfigFilePaths::ImageConfig).GetLines()), false);
	ReturnIf(!StringContainerConfig.Read(File(ConfigFilePaths::StringConfig).GetLines()), false);
	ReturnIf(!FontContainerConfig.Read(File(ConfigFilePaths::FontConfig).GetLines()), false);
	ReturnIf(!TextContainerConfig.Read(File(ConfigFilePaths::TextConfig).GetLines()), false);
	ReturnIf(!SoundContainerConfig.Read(File(ConfigFilePaths::SoundConfig).GetLines()), false);
	ReturnIf(!MusicContainerConfig.Read(File(ConfigFilePaths::MusicConfig).GetLines()), false);

	return true;
}