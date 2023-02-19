#ifndef MANAGERS_TIMERMANAGER_H_
#define MANAGERS_TIMERMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/IManager.h"

// Forward declarations

class TimerManager
    : public IManager
{
private:
	TimerManager();

public:
	~TimerManager() final;

	static TimerManager* Get();

	bool				Init() final;
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

private:
	static TimerManager* m_Instance;
};

#endif // !MANAGERS_TIMERMANAGER_H_