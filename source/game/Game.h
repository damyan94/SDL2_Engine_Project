#ifndef GAME_GAME_H_
#define GAME_GAME_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/FrequentIncludes.h"

// Forward declarations

class Game
{
public:
	int32_t Init();
	void Deinit();
	void HandleEvent(const InputEvent& e);
	void Update();
	void Draw() const;

private:

};

#endif // !GAME_GAME_H_