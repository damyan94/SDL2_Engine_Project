#ifndef SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_
#define SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_

// C/C++ system includes
#include <cstdint>
#include <unordered_map>

// Third-party includes

// Own includes

// Forward declarations
struct Mix_Chunk;

class SoundContainer
{
public:
	~SoundContainer();

	int32_t Init();
	void Deinit();

	static Mix_Chunk* GetSoundById(int32_t id);

private:
	static std::unordered_map<int32_t, Mix_Chunk*> _sounds;
};

#endif // !SDL_UTILS_CONTAINERS_SOUNDCONTAINER_H_