// Corresponding header
#include "app/game/GameObject.h"
#include "app/game/config/GameObjectConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/others/CodeReadability.h"
#include "utils/input_output/Log.h"
#include "app/AppHelpers.h"

// =============================================================================
GameObject::GameObject()
{
}

// =============================================================================
GameObject::~GameObject()
{
}

// =============================================================================
bool GameObject::Init(const GameObjectConfig& cfg)
{
	m_Image.Init(cfg.m_ImageId);

	return true;
}

// =============================================================================
void GameObject::Deinit()
{
}

// =============================================================================
void GameObject::HandleEvent(const InputEvent& e)
{
}

// =============================================================================
void GameObject::Update(int32_t dt)
{
	const auto cameraPos = Helpers::GetCameraPosition();

	m_ScreenPos.x = m_WorldPos.x - cameraPos.x;
	m_ScreenPos.y = m_WorldPos.y - cameraPos.y;
	m_Image.SetPos(m_ScreenPos);
}

// =============================================================================
Point GameObject::GetWorldPos() const
{
	return m_WorldPos;
}

// =============================================================================
Point GameObject::GetScreenPos() const
{
	return m_ScreenPos;
}