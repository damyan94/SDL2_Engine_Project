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
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::Window, readStrings), false);
	AssertReturnIf(readStrings.size() != 6, false,
		"Config file corrupted, too many or too few lines: " + ConfigFilePaths::Window);

	m_Name = Utils::ReadString(readStrings[0], "title");
	AssertReturnIf(m_Name.empty(), false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Window, 0));

	m_PosX = Utils::ReadInt(readStrings[1], "pos_x"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0, false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Window, 1));

	m_PosY = Utils::ReadInt(readStrings[2], "pos_y"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0, false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Window, 2));

	m_Width = Utils::ReadInt(readStrings[3], "width");
	AssertReturnIf(m_Width < 0, false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Window, 3));

	m_Height = Utils::ReadInt(readStrings[4], "height");
	AssertReturnIf(m_Height < 0, false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Window, 4));

	m_Flags = Utils::ReadInt(readStrings[5], "flags"); //default 0x00000004 SDL_WINDOW_SHOWN
	AssertReturnIf(m_Flags < 0, false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Window, 5));

	return true;
}