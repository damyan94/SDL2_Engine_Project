#include "stdafx.h"

#include "managers/config/DrawManagerConfig.h"

// =============================================================================
bool DrawManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_WindowConfig.Read(readStrings), false);
	ReturnIf(!m_RendererConfig.Read(readStrings), false);

	return true;
}