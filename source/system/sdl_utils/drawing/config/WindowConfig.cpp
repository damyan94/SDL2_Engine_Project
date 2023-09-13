#include "stdafx.h"

#include "system/sdl_utils/drawing/config/WindowConfig.h"

static const std::string c_CategoryTypeString = "window";

// =============================================================================
bool WindowConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	m_Name		= Utils::ReadString(readStrings[startLine], "title");
	AssertReturnIf(m_Name.empty(), false, _CONFIG_ERROR_INFO(startLine));

	m_PosX		= Utils::ReadInt(readStrings[startLine], "pos_x");	//default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0, false, _CONFIG_ERROR_INFO(startLine));

	m_PosY		= Utils::ReadInt(readStrings[startLine], "pos_y");	//default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0, false, _CONFIG_ERROR_INFO(startLine));

	m_Width		= Utils::ReadInt(readStrings[startLine], "width");
	AssertReturnIf(m_Width < 0, false, _CONFIG_ERROR_INFO(startLine));

	m_Height	= Utils::ReadInt(readStrings[startLine], "height");
	AssertReturnIf(m_Height < 0, false, _CONFIG_ERROR_INFO(startLine));

	m_Flags		= Utils::ReadInt(readStrings[startLine], "flags");	//default 0x00000004 SDL_WINDOW_SHOWN
	AssertReturnIf(m_Flags < 0, false, _CONFIG_ERROR_INFO(startLine));

	return true;
}