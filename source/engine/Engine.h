#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "managers/ManagersDefines.h"

#include "sdl_utils/input/InputEvent.h"

#include "app/App.h"

// Forward declarations
class Manager;

class Engine
{
public:
	Engine();
	~Engine();

	bool				Init();
	void				Deinit();
	void				HandleEvent();
	void				Update();
	void				Draw() const;

	void				RunApplication();

private:
	void				Sleep(int32_t elapsedTime);

private:
	std::vector<Manager*> m_Managers;

	InputEvent			m_InputEvent;

	App					m_App;

	TimerId				m_DrawTimerId;
	int32_t				m_ElapsedTime;
	int32_t				m_CurrFPS;
};

#endif // !ENGINE_ENGINE_H_