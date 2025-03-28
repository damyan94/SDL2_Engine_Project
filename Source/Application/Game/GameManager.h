#pragma once

#include "Application/Game/Camera.h"

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
	void				Draw() const;

	const Camera&		GetCamera();

private:
	Camera				m_Camera;
};