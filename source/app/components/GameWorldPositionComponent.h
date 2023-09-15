#ifndef APP_COMPONENTS_GAMEWORLDPOSITIONCOMPONENT_H_
#define APP_COMPONENTS_GAMEWORLDPOSITIONCOMPONENT_H_

#include "app/components/Component.h"

class GameWorldPositionComponent
	: public Component
{
public:
	static const String m_Name;

public:
	GameWorldPositionComponent();
	~GameWorldPositionComponent();

	const String& GetName() const final;

	Point GetPosition() const;

	void SetPosition(const Point& pos);
	void SetPosition(int32_t x, int32_t y);

private:
	Point m_Position;
};

#endif // !APP_COMPONENTS_GAMEWORLDPOSITIONCOMPONENT_H_