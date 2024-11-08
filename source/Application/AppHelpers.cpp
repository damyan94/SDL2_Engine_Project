#include "stdafx.h"

#include "Application/AppHelpers.h"

#include "Application/Game/Game.h"

namespace Helpers
{
////////////////////////////////////////////////////////////////////////////////
Point GetCameraPosition()
{
	return Game::Instance().GetCamera().GetPos();
}
} // !namespace Helpers