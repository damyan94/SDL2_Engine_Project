#ifndef APP_APP_H_
#define APP_APP_H_

#include "application/ui/menus/MenuManager.h"
#include "application/game/Game.h"

struct AppConfig;
class Camera;

class App
	: public INonCopyMoveable
{
private:
	App();
	~App();

public:
	static App& Instance();

	bool				Init(const AppConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

public:
	const Camera&		GetCamera();

private:
	MenuManager			m_MenuManager;
	Game				m_Game;
};

#endif // !APP_APP_H_