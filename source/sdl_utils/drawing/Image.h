#ifndef SDL_UTILS_DRAWING_IMAGE_H_
#define SDL_UTILS_DRAWING_IMAGE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"
#include "utils/drawing/Color.h"
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"
#include "sdl_utils/drawing/DrawObject.h"

// Forward declarations

class Image : public DrawObject
{
public:
	int32_t Init(int32_t imageId);
	void Deinit();
	void Draw() const;

	void SetFrame(int32_t frame);
	void SetPrevFrame();
	void SetNextFrame();

	int32_t GetCurrFrame() const;
	int32_t GetFramesCount() const;

private:
	int32_t _framesCount = 1;
	int32_t _currFrame = 1;
};

#endif // !SDL_UTILS_DRAWING_IMAGE_H_