// Corresponding header
#include "app/config/AppConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool AppConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_MenuManagerConfig.Read(readStrings), false);
	ReturnIf(!m_GameConfig.Read(readStrings), false);

	return true;
}