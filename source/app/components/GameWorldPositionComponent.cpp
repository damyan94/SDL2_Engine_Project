#include "stdafx.h"

#include "app/components/GameWorldPositionComponent.h"

// =============================================================================
const String GameWorldPositionComponent::m_Name("GameWorldPositionComponent");

// =============================================================================
GameWorldPositionComponent::GameWorldPositionComponent()
{
}

// =============================================================================
GameWorldPositionComponent::~GameWorldPositionComponent()
{
}

// =============================================================================
const String& GameWorldPositionComponent::GetName() const
{
	return m_Name;
}

// =============================================================================
Point GameWorldPositionComponent::GetPosition() const
{
	return m_Position;
}

// =============================================================================
void GameWorldPositionComponent::SetPosition(const Point& pos)
{
	m_Position = pos;
}

// =============================================================================
void GameWorldPositionComponent::SetPosition(int32_t x, int32_t y)
{
	m_Position = Point(x, y);
}