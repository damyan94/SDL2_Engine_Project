#ifndef APP_GAME_GAME_H_
#define APP_GAME_GAME_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "app/Defines.h"
#include "utils/geometry/Point.h"
#include "sdl_utils/input/InputEvent.h"

#include "app/game/Camera.h"
#include "app/game/GameObject.h"

// Forward declarations
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