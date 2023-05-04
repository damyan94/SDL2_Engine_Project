// Corresponding header
#include "app/ui/menus/config/MenuManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool MenuManagerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_StartMenuConfig.Read(readStrings), false);

	return true;
}