#ifndef APPLICATION_GAME_GAMEMANAGER_H_
#define APPLICATION_GAME_GAMEMANAGER_H_

#include "application/game/Camera.h"

struct GameManagerConfig;

class GameManager
{
public:
	GameManager();
	~GameManager();

	GameManager(const GameManager& other) = delete;
	GameManager(GameManager&& other) = delete;

	GameManager& operator=(const GameManager& other) = delete;
	GameManager& operator=(GameManager&& other) = delete;

	bool				Init(const GameManagerConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

	const Camera&		GetCamera();

private:
	Camera				m_Camera;
};

#endif // !APPLICATION_GAME_GAMEMANAGER_H_