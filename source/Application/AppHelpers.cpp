#include "stdafx.h"

#include "Application/AppHelpers.h"

#include "Application/game/Game.h"

namespace Helpers
{
////////////////////////////////////////////////////////////////////////////////
Point GetCameraPosition()
{
	return Game::Instance().GetCamera().GetPos();
}
} // !namespace Helpers