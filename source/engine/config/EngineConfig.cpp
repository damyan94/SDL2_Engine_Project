// Corresponding header
#include "engine/config/EngineConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/ReadWriteFile.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "defines/ConfigFilePaths.h"
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"

// =============================================================================
bool EngineConfig::Read()
{
	ConfigStrings readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::MainConfig, readStrings), false);

	ReturnIf(!m_ManagerHandlerConfig.Read(readStrings), false);
	ReturnIf(!m_AppConfig.Read(), false);

	return true;
}