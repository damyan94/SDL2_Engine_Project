#ifndef APP_GAME_IGAME_H_
#define APP_GAME_IGAME_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations
class Camera;

class IApp
{
public:
	IApp() = default;
	virtual ~IApp() = default;

	virtual Camera& GetCamera() = 0;
};

#endif // !APP_GAME_IGAME_H_