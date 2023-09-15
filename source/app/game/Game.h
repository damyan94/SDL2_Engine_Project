#ifndef APP_GAME_GAME_H_
#define APP_GAME_GAME_H_

#include "app/game/Camera.h"
#include "app/game/GameObject.h"

struct GameConfig;

class Game
{
public:
	Game();
	~Game();

	Game(const Game& other) = delete;
	Game(Game&& other) = delete;

	Game& operator=(const Game& other) = delete;
	Game& operator=(Game&& other) = delete;

	bool				Init(const GameConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

	const Camera&		GetCamera();

private:
	Camera				m_Camera;
	//Terrain				m_Terrain;
	std::vector<GameObject*> m_Tiles;
};

#endif // !APP_GAME_GAME_H_