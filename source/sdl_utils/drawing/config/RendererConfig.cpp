// Corresponding header
#include "sdl_utils/drawing/config/RendererConfig.h"

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
bool RendererConfig::Read()
{
	std::vector<std::string> readStrings;
	ReturnIf(!ReadWriteFile::ReadFromFile(ConfigFilePaths::Renderer, readStrings), false);
	AssertReturnIf(readStrings.size() != 2, false,
		"Config file corrupted: " + ConfigFilePaths::Renderer);

	auto color = Utils::ReadIntArray(readStrings[0], "color", 4);
	AssertReturnIf(color.size() != 4, false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Renderer, 0));

	m_DrawColor = Color(color[0], color[1], color[2], color[3]);//default Colors::VeryLightGrey

	m_Flags = Utils::ReadInt(readStrings[1], "flags"); //default 0x00000002 SDL_RENDERER_ACCELERATED;
	AssertReturnIf(m_Flags < 0, false,
		_CONFIG_ERROR_INFO(ConfigFilePaths::Renderer, 1));

	return true;
}