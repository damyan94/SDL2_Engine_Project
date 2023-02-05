#ifndef SDL_UTILS_CONTAINERS_ASSETCONTAINER_H_
#define SDL_UTILS_CONTAINERS_ASSETCONTAINER_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/UtilsCommonIncludes.h"
#include "sdl_utils/SDLUtilsDefines.h"

// Forward declarations

class AssetContainer
{
public:
	AssetContainer();
	virtual ~AssetContainer();

	virtual bool		Init() = 0;
	virtual void		Deinit() = 0;

	//virtual bool		DoesAssetExist(int32_t id) = 0;

protected:

private:

};

#endif // !SDL_UTILS_CONTAINERS_ASSETCONTAINER_H_