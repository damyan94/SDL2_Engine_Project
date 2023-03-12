#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/input/InputEvent.h"

// Forward declarations
struct EngineConfig;
class ManagerHandler;
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

	void				Sleep(int32_t elapsedTime);

private:
	InputEvent			m_InputEvent;

	ManagerHandler*		m_ManagerHandler;
	App*				m_App;

	TimerId				m_DrawTimerId;
	int32_t				m_ElapsedTime;
	int32_t				m_CurrFPS;
};

#endif // !ENGINE_ENGINE_H_