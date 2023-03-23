// Corresponding header
#include "managers/config/DrawManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool DrawManagerConfig::Read()
{
	ReturnIf(!m_WindowConfig.Read(), false);
	ReturnIf(!m_RendererConfig.Read(), false);

	return true;
}