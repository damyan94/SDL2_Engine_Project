// Corresponding header
#include "managers/config/TimerManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool TimerManagerConfig::Read()
{
	ReturnIf(!m_TimerContainerConfig.Read(), false);

	return true;
}