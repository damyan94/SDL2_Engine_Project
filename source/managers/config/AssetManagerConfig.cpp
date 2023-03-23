// Corresponding header
#include "managers/config/AssetManagerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"

// =============================================================================
bool AssetManagerConfig::Read()
{
	ReturnIf(!m_ImageContainerConfig.Read(), false);
	ReturnIf(!m_FontContainerConfig.Read(), false);
	ReturnIf(!m_TextContainerConfig.Read(), false);
	ReturnIf(!m_SoundContainerConfig.Read(), false);
	ReturnIf(!m_MusicContainerConfig.Read(), false);

	return true;
}