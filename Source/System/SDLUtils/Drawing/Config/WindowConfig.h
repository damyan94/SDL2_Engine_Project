#pragma once

struct WindowConfig
{
	bool				Read(const LinesOfText& readStrings);

	std::string			Name;
	int32_t				PosX;
	int32_t				PosY;
	int32_t				Width;
	int32_t				Height;
	int32_t				Flags;
};