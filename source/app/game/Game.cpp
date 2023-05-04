// Corresponding header
#include "app/game/Game.h"
#include "app/game/config/GameConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "utils/string/String.h"
#include "app/game/config/GameObjectConfig.h"

#define W 6
#define H 6

enum class ETerrainTileType
	: int8_t
{
	Invalid = -1

	, Water
	, Grass
	, Dirt
	, TODO_4
	, TODO_5
	, Desert
	, Snow
	, TODO_8

	, Count
};

// =============================================================================
Game::Game()
{
}

// =============================================================================
Game::~Game()
{
}

// =============================================================================
bool Game::Init(const GameConfig& cfg)
{
	ReturnIf(!m_Camera.Init(), false);

	m_Tiles.resize(W * H);
	for(size_t i = 0; i < H; i++)
		for (size_t j = 0; j < W; j++)
		{
			auto& tile = m_Tiles[i * W + j];
			tile = new GameObject;
			GameObjectConfig c{ String("TERRAIN_TILES").m_Hash };
			tile->Init(c);
			tile->m_Image.SetCurrFrame(rand() % 8 + 1);
			tile->m_WorldPos = Point(j * 40, i * 40);
			tile->Update(0);
		}

	return true;
}

// =============================================================================
void Game::Deinit()
{
	m_Camera.Deinit();
}

// =============================================================================
void Game::HandleEvent(const InputEvent& e)
{
	m_Camera.HandleEvent(e);
}

// =============================================================================
void Game::Update(int32_t dt)
{
	m_Camera.Update(dt);
	ReturnIf(!m_Camera.HasCameraChanged(), void());

	for (auto& tile : m_Tiles)
	{
		tile->Update(dt);
	}
}

// =============================================================================
const Camera& Game::GetCamera()
{
	return m_Camera;
}