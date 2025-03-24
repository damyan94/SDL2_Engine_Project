#pragma once

enum class EImGuiStyle : int16_t;

struct ImGuiManagerConfig
{
	bool				Read();

	EImGuiStyle			ImGuiStyle;
};