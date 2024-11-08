#include "stdafx.h"

#include "System/Managers/Config/DrawManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool DrawManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_WindowConfig.Read(readStrings), false);
	ReturnIf(!m_RendererConfig.Read(readStrings), false);

	return true;
}