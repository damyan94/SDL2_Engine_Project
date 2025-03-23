#include "stdafx.h"

#include "System/Managers/ManagersHelpers.h"

#include "System/Managers/DrawManager.h"

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
	return DrawManager::Instance().GetDrawCalls();
}
} // !namespace Helpers