#include "stdafx.h"

#include "app/game/GameObject.h"
#include "app/game/config/GameObjectConfig.h"

#include "app/components/Component.h"

// =============================================================================
GameObject::GameObject()
{
}

// =============================================================================
GameObject::~GameObject()
{
	Deinit();
}

// =============================================================================
bool GameObject::Init(const GameObjectConfig& cfg)
{
	return true;
}

// =============================================================================
void GameObject::Deinit()
{
	for (auto& component : m_Components)
	{
		SafeDelete(component);
	}

	m_Components.clear();
}

// =============================================================================
void GameObject::HandleEvent(const InputEvent& e)
{
}

// =============================================================================
void GameObject::Update(int32_t dt)
{
}

// =============================================================================
std::vector<Component*>& GameObject::GetAllComponents()
{
	return m_Components;
}