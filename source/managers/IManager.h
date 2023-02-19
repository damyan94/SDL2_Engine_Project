#ifndef MANAGERS_MANAGERBASE_H_
#define MANAGERS_MANAGERBASE_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/SDLUtilsCommonIncludes.h"

#include "managers/ManagersDefines.h"

// Forward declarations

class IManager
{
public:
	IManager();
	virtual ~IManager();

	virtual bool		Init() = 0;
	virtual void		Deinit() = 0;
	virtual void		HandleEvent(const InputEvent& e) = 0;
	virtual void		Update(int32_t dt) = 0;

	//Manager*			Get(EManagerType type);

protected:

private:

};

#endif // !MANAGERS_MANAGERBASE_H_