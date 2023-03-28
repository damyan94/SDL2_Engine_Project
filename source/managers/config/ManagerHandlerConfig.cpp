// Corresponding header
#include "managers/config/ManagerHandlerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool ManagerHandlerConfig::Read(const ConfigStrings& readStrings)
{
	ReturnIf(!m_DrawManagerConfig.Read(), false);
	ReturnIf(!m_AssetManagerConfig.Read(readStrings), false);
	ReturnIf(!m_AudioManagerConfig.Read(), false);
	ReturnIf(!m_TimerManagerConfig.Read(), false);
	ReturnIf(!m_ImGuiManagerConfig.Read(), false);

	return true;
}