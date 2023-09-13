#include "stdafx.h"

#include "app/AppHelpers.h"

#include "app/App.h"

namespace Helpers
{
// =============================================================================
Point GetCameraPosition()
{
	return g_App->GetCamera().GetPos();
}
} // !namespace Helpers