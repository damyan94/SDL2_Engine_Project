#include "stdafx.h"

#include "System/Managers/Config/DrawManagerConfig.h"

////////////////////////////////////////////////////////////////////////////////
bool DrawManagerConfig::Read(const LinesOfText& readStrings)
{
	ReturnIf(!WindowConfig.Read(readStrings), false);
	ReturnIf(!RendererConfig.Read(readStrings), false);

	return true;
}