#include "stdafx.h"

#include "application/game/Game.h"
#include "application/game/config/GameConfig.h"

#include "system/utils/containers/BinaryStruct.h"

#include <locale>
#include <codecvt>

DynamicText displayText;
template<typename WString>
std::string WideStringToUTF8Bytes(const WString& wideString)
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wideString);
}

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
	ReturnUnless(m_Camera.HasCameraChanged());

	const auto& cameraPos = m_Camera.GetPos();
}

// =============================================================================
const Camera& Game::GetCamera()
{
	return m_Camera;
}