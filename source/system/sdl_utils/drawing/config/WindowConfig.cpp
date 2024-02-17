#include "stdafx.h"

#include "system/sdl_utils/drawing/config/WindowConfig.h"

static const std::string c_CategoryTypeString = "Window";

// =============================================================================
bool WindowConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	m_Name		= Utils::ReadString(readStrings[startLine], "Title");
	AssertReturnIf(m_Name.empty() && _CONFIG_ERROR_INFO(startLine), false);

	m_PosX		= Utils::ReadInt(readStrings[startLine], "PosX");	//default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0 && _CONFIG_ERROR_INFO(startLine), false);

	m_PosY		= Utils::ReadInt(readStrings[startLine], "PosY");	//default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(m_PosX < 0 && _CONFIG_ERROR_INFO(startLine), false);

	m_Width		= Utils::ReadInt(readStrings[startLine], "Width");
	AssertReturnIf(m_Width < 0 && _CONFIG_ERROR_INFO(startLine), false);

	m_Height	= Utils::ReadInt(readStrings[startLine], "Height");
	AssertReturnIf(m_Height < 0 && _CONFIG_ERROR_INFO(startLine), false);

	m_Flags		= Utils::ReadInt(readStrings[startLine], "Flags");	//default 0x00000004 SDL_WINDOW_SHOWN
	AssertReturnIf(m_Flags < 0 && _CONFIG_ERROR_INFO(startLine), false);

	return true;
}