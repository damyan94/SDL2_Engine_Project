#include "stdafx.h"

#include "System/Managers/Config/AssetManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool AssetManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!ImageContainerConfig.Read(readStrings), false);
	ReturnIf(!StringContainerConfig.Read(readStrings), false);
	ReturnIf(!FontContainerConfig.Read(readStrings), false);
	ReturnIf(!TextContainerConfig.Read(readStrings), false);
	ReturnIf(!SoundContainerConfig.Read(readStrings), false);
	ReturnIf(!MusicContainerConfig.Read(readStrings), false);

	return true;
}