// Corresponding header
#include "sdl_utils/drawing/config/WindowConfig.h"

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
bool WindowConfig::Read()
{
	ConfigStrings readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::SystemConfig, readStrings), false);
	AssertReturnIf(readStrings.size() != 8, false,
		"Config file corrupted, too many or too few lines: " + ConfigFilePaths::SystemConfig);

	//TODO same as renderer
	m_Name = Utils::ReadString(readStrings[0], "window_title");
	AssertReturnIf(m_Name.empty(), false, _CONFIG_ERROR_INFO(0));

	m_PosX = Utils::ReadInt(readStrings[1], "window_pos_x");	//default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0, false, _CONFIG_ERROR_INFO(1));

	m_PosY = Utils::ReadInt(readStrings[2], "window_pos_y");	//default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0, false, _CONFIG_ERROR_INFO(2));

	m_Width = Utils::ReadInt(readStrings[3], "window_width");
	AssertReturnIf(m_Width < 0, false, _CONFIG_ERROR_INFO(3));

	m_Height = Utils::ReadInt(readStrings[4], "height");
	AssertReturnIf(m_Height < 0, false, _CONFIG_ERROR_INFO(4));

	m_Flags = Utils::ReadInt(readStrings[5], "window_flags"); //default 0x00000004 SDL_WINDOW_SHOWN
	AssertReturnIf(m_Flags < 0, false, _CONFIG_ERROR_INFO(5));

	return true;
}