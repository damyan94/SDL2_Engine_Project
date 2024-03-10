#include "stdafx.h"

#include "application/AppHelpers.h"

#include "application/App.h"

namespace Helpers
{
// =============================================================================
Point GetCameraPosition()
{
	return App::Instance().GetCamera().GetPos();
}
} // !namespace Helpers