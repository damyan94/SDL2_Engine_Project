// Corresponding header
#include "managers/config/ImGuiManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/ReadWriteFile.h"
#include "utils/input_output/ConfigReaderUtils.h"
#include "defines/ConfigFilePaths.h"
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "managers/Defines.h"

// =============================================================================
bool ImGuiManagerConfig::Read()
{
	//TODO Read data from file and populate the config
	m_ImGuiStyle = EImGuiStyle::Dark;

	return true;
}