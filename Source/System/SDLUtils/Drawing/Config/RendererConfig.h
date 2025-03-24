#pragma once

struct RendererConfig
{
	bool				Read(const ConfigStrings& readStrings);

	Color				DrawColor;
	int32_t				Flags;
};