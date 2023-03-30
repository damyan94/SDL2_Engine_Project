// Corresponding header
#include "managers/config/DrawManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes

// =============================================================================
bool DrawManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_WindowConfig.Read(readStrings), false);
	ReturnIf(!m_RendererConfig.Read(readStrings), false);

	return true;
}