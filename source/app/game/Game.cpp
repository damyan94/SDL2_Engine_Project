#include "stdafx.h"

#include "app/game/Game.h"
#include "app/game/config/GameConfig.h"

#include "app/game/config/GameObjectConfig.h"

#include "app/components/GameWorldPositionComponent.h"
#include "app/components/ImageComponent.h"

#define W 60
#define H 60

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
			GameObjectConfig c{ String("TERRAIN_TILES").m_Hash };

			auto& tileObject = m_Tiles[i * W + j];
			tileObject = new GameObject;

			tileObject->AddComponent<GameWorldPositionComponent>();
			tileObject->AddComponent<ImageComponent>();

			auto position = tileObject->GetComponent<GameWorldPositionComponent>();
			auto image = tileObject->GetComponent<ImageComponent>();

			image->Init(c.m_ImageId);
			image->SetCurrFrame(rand() % 8 + 1);
			image->SetPos(j * 40, i * 40);
			position->SetPosition(j * 40, i * 40);

			tileObject->Update(0);
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

	const auto& cameraPos = m_Camera.GetPos();

	for (auto tileObject : m_Tiles)
	{
		/*for (auto component : tileObject->GetAllComponents())
		{
			component->Update(dt);
		}*/
		//TODO performance bottle neck, must optimize how we get specific components
		auto worldPos = tileObject->GetComponent<GameWorldPositionComponent>();
		ContinueUnless(worldPos);

		auto image = tileObject->GetComponent<ImageComponent>();
		ContinueUnless(image);

		image->SetPos(worldPos->GetPosition().x - cameraPos.x, worldPos->GetPosition().y - cameraPos.y);
	}
}

// =============================================================================
const Camera& Game::GetCamera()
{
	return m_Camera;
}