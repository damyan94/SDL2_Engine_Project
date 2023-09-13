#ifndef APP_GAME_IGAME_H_
#define APP_GAME_IGAME_H_

class Camera;

class IApp
{
public:
	IApp() = default;
	virtual ~IApp() = default;

	virtual Camera& GetCamera() = 0;
};

#endif // !APP_GAME_IGAME_H_