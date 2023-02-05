#ifndef MANAGERS_TIMERMANAGER_H_
#define MANAGERS_TIMERMANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/Manager.h"

// Forward declarations

class TimerManager
    : public Manager
{
public:
	~TimerManager();

	static TimerManager* Get();

	bool				Init() override;
	void				Deinit() override;
	void				HandleEvent(const InputEvent& e) override;
	void				Update(int32_t dt) override;

private:
	TimerManager();
	static TimerManager* m_TimerManager;
};

#endif // !MANAGERS_TIMERMANAGER_H_