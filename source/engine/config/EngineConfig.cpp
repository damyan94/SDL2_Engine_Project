// Corresponding header
#include "engine/config/EngineConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool EngineConfig::Read()
{
	ReturnIf(!m_ManagerHandlerConfig.Read(), false);
	ReturnIf(!m_AppConfig.Read(), false);

	return true;
}