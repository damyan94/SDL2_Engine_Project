#pragma once

struct RendererConfig
{
	bool				Read(const StringVector& readStrings);

	Color				DrawColor;
	int32_t				Flags;
};