// Corresponding header
#include "sdl_utils/drawing/config/RendererConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "utils/input_output/ConfigReaderUtils.h"

static const std::string c_CategoryTypeString = "renderer";

// =============================================================================
bool RendererConfig::Read(const ConfigStrings& readStrings)
{
	int32_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	auto color	= Utils::ReadIntArray(readStrings[startLine], "color", 4);
	AssertReturnIf(color.size() != 4, false, _CONFIG_ERROR_INFO(startLine));

	m_DrawColor	= Color(color[0], color[1], color[2], color[3]);		//default Colors::VeryLightGrey

	m_Flags		= Utils::ReadInt(readStrings[startLine], "flags");		//default 0x00000002 SDL_RENDERER_ACCELERATED;
	AssertReturnIf(m_Flags < 0, false, _CONFIG_ERROR_INFO(startLine));

	return true;
}