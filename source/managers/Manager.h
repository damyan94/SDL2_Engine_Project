#ifndef MANAGERS_MANAGER_H_
#define MANAGERS_MANAGER_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/SDLUtilsCommonIncludes.h"

#include "managers/ManagersDefines.h"

// Forward declarations

class Manager
{
public:
	Manager();
	virtual ~Manager();

	virtual bool		Init() = 0;
	virtual void		Deinit() = 0;
	virtual void		HandleEvent(const InputEvent& e) = 0;
	virtual void		Update(int32_t dt) = 0;

	//Manager*			Get(EManagerType type);

protected:

private:

};

#endif // !MANAGERS_MANAGER_H_