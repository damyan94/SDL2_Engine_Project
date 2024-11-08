#pragma once

#include "application/ui/menus/MenuManager.h"
#include "application/game/GameManager.h"

struct GameConfig;
class Camera;

class Game
	: public INonCopyMoveable
{
private:
	Game();
	~Game();

public:
	static Game& Instance();

	bool				Init(const GameConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

public:
	const Camera&		GetCamera();

private:
	MenuManager			m_MenuManager;
	GameManager			m_Game;
};