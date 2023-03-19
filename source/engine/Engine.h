#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/CommonIncludes.h"
#include "sdl_utils/input/InputEvent.h"
#include "managers/ManagerHandler.h"

// Forward declarations
struct EngineConfig;
class App;

class Engine
{
public:
	Engine();
	~Engine();

	bool				Init(const EngineConfig& cfg);
	void				Deinit();

	void				RunApplication();

private:
	void				HandleEvent();
	void				Update();
	void				Draw() const;

	void				Sleep();

private:
	InputEvent			m_InputEvent;
	ManagerHandler		m_ManagerHandler;

	App*				m_App;

	int32_t				m_ElapsedTimeMS;
	int32_t				m_TargetFPS;
};

#endif // !ENGINE_ENGINE_H_