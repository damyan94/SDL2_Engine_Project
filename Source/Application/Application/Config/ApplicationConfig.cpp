#include "stdafx.h"

#include "Application/Application/Config/ApplicationConfig.h"
#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool ApplicationConfig::Read()
{
	//TODO move every config to a separate file, so i will have one file for strings,
	//another for fonts, other for images config and so on. I could even have them as csv files
	//to speed up reading (remove the call to configreaderutils::getInt() and so on).
	
	//TODO maybe this has to be fixed?
	ReturnIf(!DrawManagerConfig.Read(File(ConfigFilePaths::SystemConfig).GetFileContents()), false);

	ReturnIf(!AssetManagerConfig.Read(), false);
	ReturnIf(!AudioManagerConfig.Read(), false);
	ReturnIf(!TimerManagerConfig.Read(), false);
	ReturnIf(!ImGuiManagerConfig.Read(), false);

	ReturnIf(!AppConfig.Read(), false);

	return true;
}