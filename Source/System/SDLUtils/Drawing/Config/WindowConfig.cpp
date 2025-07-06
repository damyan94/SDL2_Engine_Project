#include "stdafx.h"

#include "System/SDLUtils/Drawing/Config/WindowConfig.h"

static const std::string c_CategoryTypeString = "Window";

////////////////////////////////////////////////////////////////////////////////
bool WindowConfig::Read(const StringVector& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Logger::LogWarning(Format("Cannot find section \"{0}\" in config file.", c_CategoryTypeString.c_str()));
		return true;
	}

	Name = Utils::ReadString(readStrings[startLine], "Title");
	AssertReturnIf(Name.empty(), false);

	PosX = Utils::ReadInt(readStrings[startLine], "PosX"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(PosX < 0, false);

	PosY = Utils::ReadInt(readStrings[startLine], "PosY"); //default 0x1FFF0000u SDL_WINDOWPOS_UNDEFINED
	AssertReturnIf(PosX < 0, false);

	Width = Utils::ReadInt(readStrings[startLine], "Width");
	AssertReturnIf(Width < 0, false);

	Height = Utils::ReadInt(readStrings[startLine], "Height");
	AssertReturnIf(Height < 0, false);

	Flags = Utils::ReadInt(readStrings[startLine], "Flags"); //default 0x00000004 SDL_WINDOW_SHOWN
	AssertReturnIf(Flags < 0, false);

	return true;
}