#include "stdafx.h"

#include "System/Managers/Config/ImGuiManagerConfig.h"

#include "System/Defines/ConfigFilePaths.h"

////////////////////////////////////////////////////////////////////////////////
bool ImGuiManagerConfig::Read()
{
	//TODO Read data from file and populate the config
	m_ImGuiStyle = EImGuiStyle::Dark;

	return true;
}