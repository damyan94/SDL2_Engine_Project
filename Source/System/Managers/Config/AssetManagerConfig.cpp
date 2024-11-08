#include "stdafx.h"

#include "System/Managers/Config/AssetManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool AssetManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_ImageContainerConfig.Read(readStrings), false);
	ReturnIf(!m_FontContainerConfig.Read(readStrings), false);
	ReturnIf(!m_TextContainerConfig.Read(readStrings), false);
	ReturnIf(!m_SoundContainerConfig.Read(readStrings), false);
	ReturnIf(!m_MusicContainerConfig.Read(readStrings), false);

	return true;
}