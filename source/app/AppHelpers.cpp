// Corresponding header
#include "app/AppHelpers.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "app/App.h"

namespace Helpers
{
// =============================================================================
Point GetCameraPosition()
{
	return g_App->GetCamera().GetPos();
}
} // !namespace Helpers