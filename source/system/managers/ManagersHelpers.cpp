#include "stdafx.h"

#include "system/managers/ManagersHelpers.h"

#include "system/managers/DrawManager.h"

namespace Helpers
{
////////////////////////////////////////////////////////////////////////////////
const Rectangle& GetWindowRect()
{
	return DrawManager::Instance().GetWindow().GetWindowRect();
}

////////////////////////////////////////////////////////////////////////////////
int32_t GetDrawCalls()
{
	return DrawManager::Instance().m_DrawCalls;
}
} // !namespace Helpers