#pragma once

struct RendererConfig
{
	bool				Read(const ConfigStrings& readStrings);

	Color				m_DrawColor;
	int32_t				m_Flags;
};