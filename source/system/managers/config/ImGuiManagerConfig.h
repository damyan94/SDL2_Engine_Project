#pragma once

enum class EImGuiStyle : int16_t;

struct ImGuiManagerConfig
{
	bool				Read();

	EImGuiStyle			m_ImGuiStyle;
};