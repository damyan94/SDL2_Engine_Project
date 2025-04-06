#pragma once

struct RendererConfig
{
	bool				Read(const LinesOfText& readStrings);

	Color				DrawColor;
	int32_t				Flags;
};