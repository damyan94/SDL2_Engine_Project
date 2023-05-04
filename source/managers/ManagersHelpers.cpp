// Corresponding header
#include "managers/ManagersHelpers.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/DrawManager.h"
#include "ManagersHelpers.h"

namespace Helpers
{
// =============================================================================
const Rectangle& GetWindowRect()
{
	return g_DrawManager->GetWindow().GetWindowRect();
}

// =============================================================================
int32_t GetDrawCalls()
{
	return g_DrawManager->m_DrawCalls;
}
} // !namespace Helpers