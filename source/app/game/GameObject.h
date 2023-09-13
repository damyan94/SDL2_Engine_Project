#ifndef APP_GAME_GAMEOBJECT_H_
#define APP_GAME_GAMEOBJECT_H_

#include "app/Defines.h"
#include "sdl_utils/input/InputEvent.h"

#include "components/drawing/Image.h"
#include "components/drawing/Text.h"
#include "components/drawing/DynamicText.h"
#include "components/audio/Sound.h"

struct GameObjectConfig;

class GameObject
{
public:
	GameObject();
	~GameObject();

	bool				Init(const GameObjectConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

	Point				GetWorldPos() const;
	Point				GetScreenPos() const;

public:
	Point				m_WorldPos;
	Point				m_ScreenPos;
	Image				m_Image;
};

#endif // !APP_GAME_GAMEOBJECT_H_