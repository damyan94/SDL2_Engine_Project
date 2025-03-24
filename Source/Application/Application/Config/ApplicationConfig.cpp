#include "stdafx.h"

#include "Application/Application/Config/ApplicationConfig.h"
#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool ApplicationConfig::Read()
{
	ConfigStrings readStrings;

	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::SystemConfig, readStrings), false);
	ReturnIf(!DrawManagerConfig.Read(readStrings), false);

	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::AssetsConfig, readStrings), false);
	ReturnIf(!AssetManagerConfig.Read(readStrings), false);
	ReturnIf(!AudioManagerConfig.Read(), false);
	ReturnIf(!TimerManagerConfig.Read(), false);
	ReturnIf(!ImGuiManagerConfig.Read(), false);

	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::ObjectsConfig, readStrings), false);
	ReturnIf(!AppConfig.Read(readStrings), false);

	return true;
}