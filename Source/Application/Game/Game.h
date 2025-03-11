#pragma once

#include "Application/UI/Menus/MenuManager.h"
#include "Application/Game/GameManager.h"

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
	void				Draw() const;

public:
	const Camera&		GetCamera();

private:
	MenuManager			m_MenuManager;
	GameManager			m_GameManager;
};