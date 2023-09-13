#include "stdafx.h"

#include "managers/ManagersHelpers.h"

#include "managers/DrawManager.h"

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