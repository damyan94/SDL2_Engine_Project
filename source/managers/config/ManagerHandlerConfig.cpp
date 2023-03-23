// Corresponding header
#include "managers/config/ManagerHandlerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool ManagerHandlerConfig::Read()
{
	ReturnIf(!m_DrawManagerConfig.Read(), false);
	ReturnIf(!m_AssetManagerConfig.Read(), false);
	ReturnIf(!m_AudioManagerConfig.Read(), false);
	ReturnIf(!m_TimerManagerConfig.Read(), false);
	ReturnIf(!m_ImGuiManagerConfig.Read(), false);

	return true;
}