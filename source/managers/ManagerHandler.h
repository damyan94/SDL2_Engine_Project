#ifndef MANAGERS_MANAGERHANDLER_H_
#define MANAGERS_MANAGERHANDLER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
class InputEvent;
struct ManagerHandlerConfig;

class ManagerHandler
{
public:
	ManagerHandler();
	~ManagerHandler();

	bool				Init(const ManagerHandlerConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;
};

#endif // !MANAGERS_MANAGERHANDLER_H_