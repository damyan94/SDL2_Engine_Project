#include "stdafx.h"

#include "application/AppHelpers.h"

#include "application/App.h"

namespace Helpers
{
// =============================================================================
Point GetCameraPosition()
{
	return g_App->GetCamera().GetPos();
}
} // !namespace Helpers