#include "stdafx.h"

#include "system/sdl_utils/drawing/config/RendererConfig.h"

static const std::string c_CategoryTypeString = "renderer";

// =============================================================================
bool RendererConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	auto color	= Utils::ReadIntArray(readStrings[startLine], "color", 4);
	AssertReturnIf(color.size() != 4 && _CONFIG_ERROR_INFO(startLine), false);

	m_DrawColor	= Color(color[0], color[1], color[2], color[3]);		//default Colors::VeryLightGrey

	m_Flags		= Utils::ReadInt(readStrings[startLine], "flags");		//default 0x00000002 SDL_RENDERER_ACCELERATED;
	AssertReturnIf(m_Flags < 0 && _CONFIG_ERROR_INFO(startLine), false);

	return true;
}