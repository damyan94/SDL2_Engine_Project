#include "stdafx.h"

#include "system/managers/config/ImGuiManagerConfig.h"

#include "system/defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool ImGuiManagerConfig::Read()
{
	//TODO Read data from file and populate the config
	m_ImGuiStyle = EImGuiStyle::Dark;

	return true;
}