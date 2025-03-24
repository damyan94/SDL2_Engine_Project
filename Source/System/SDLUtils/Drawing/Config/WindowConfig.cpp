#include "stdafx.h"

#include "System/SDLUtils/Drawing/Config/WindowConfig.h"

static const std::string c_CategoryTypeString = "Window";

////////////////////////////////////////////////////////////////////////////////
bool WindowConfig::Read(const ConfigStrings& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Log::ConsoleWarning("Cannot find section \"%s\" in config file.", c_CategoryTypeString.c_str());
		return true;
	}

	Name = Utils::ReadString(readStrings[startLine], "Title");
	AssertReturnIf(Name.empty() && _CONFIG_ERROR_INFO(startLine), false);

	PosX = Utils::ReadInt(readStrings[startLine], "PosX"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(PosX < 0 && _CONFIG_ERROR_INFO(startLine), false);

	PosY = Utils::ReadInt(readStrings[startLine], "PosY"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(PosX < 0 && _CONFIG_ERROR_INFO(startLine), false);

	Width = Utils::ReadInt(readStrings[startLine], "Width");
	AssertReturnIf(Width < 0 && _CONFIG_ERROR_INFO(startLine), false);

	Height = Utils::ReadInt(readStrings[startLine], "Height");
	AssertReturnIf(Height < 0 && _CONFIG_ERROR_INFO(startLine), false);

	Flags = Utils::ReadInt(readStrings[startLine], "Flags"); //default 0x00000004 SDL_WINDOW_SHOWN
	AssertReturnIf(Flags < 0 && _CONFIG_ERROR_INFO(startLine), false);

	return true;
}