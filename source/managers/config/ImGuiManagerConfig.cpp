#include "stdafx.h"

#include "managers/config/ImGuiManagerConfig.h"

#include "defines/ConfigFilePaths.h"

// =============================================================================
bool ImGuiManagerConfig::Read()
{
	//TODO Read data from file and populate the config
	m_ImGuiStyle = EImGuiStyle::Dark;

	return true;
}