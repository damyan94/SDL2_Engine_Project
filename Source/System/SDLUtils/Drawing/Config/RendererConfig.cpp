#include "stdafx.h"

#include "System/SDLUtils/Drawing/Config/RendererConfig.h"

static const std::string c_CategoryTypeString = "Renderer";

////////////////////////////////////////////////////////////////////////////////
bool RendererConfig::Read(const LinesOfText& readStrings)
{
	size_t startLine = Utils::ReadInt(readStrings[0], c_CategoryTypeString);
	if (startLine >= readStrings.size())
	{
		Logger::LogWarning(Format("Cannot find section \"{0}\" in config file.", c_CategoryTypeString.c_str()));
		return true;
	}

	auto color = Utils::ReadIntArray(readStrings[startLine], "Color", 4);
	AssertReturnIf(color.size() != 4, false);

	DrawColor = Color(color[0], color[1], color[2], color[3]); //default Colors::VeryLightGrey

	Flags = Utils::ReadInt(readStrings[startLine], "Flags"); //default 0x00000002 SDL_RENDERER_ACCELERATED;
	AssertReturnIf(Flags < 0, false);

	return true;
}