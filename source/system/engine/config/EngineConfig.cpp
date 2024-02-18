#include "stdafx.h"

#include "system/engine/config/EngineConfig.h"
#include "system/defines/ConfigFilePaths.h"

// =============================================================================
bool EngineConfig::Read()
{
	ConfigStrings readStrings;

	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::SystemConfig, readStrings), false);
	ReturnIf(!m_DrawManagerConfig.Read(readStrings), false);

	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::AssetsConfig, readStrings), false);
	ReturnIf(!m_AssetManagerConfig.Read(readStrings), false);

	ReturnIf(!m_AudioManagerConfig.Read(), false);

	ReturnIf(!m_TimerManagerConfig.Read(), false);

	ReturnIf(!m_ImGuiManagerConfig.Read(), false);

	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::ObjectsConfig, readStrings), false);
	ReturnIf(!m_AppConfig.Read(readStrings), false);

	return true;
}