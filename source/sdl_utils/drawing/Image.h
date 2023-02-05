#ifndef SDL_UTILS_DRAWING_IMAGE_H_
#define SDL_UTILS_DRAWING_IMAGE_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "defines/id/ImageId.h"

#include "utils/UtilsCommonIncludes.h"

#include "sdl_utils/drawing/DrawObject.h"

// Forward declarations

class Image : public DrawObject
{
public:
	Image();
	~Image();

	bool				Init(ImageId id);
	void				Deinit();
	void				Draw() const;

	void				SetFrame(int32_t frame);
	void				SetPrevFrame();
	void				SetNextFrame();

	int32_t				GetCurrFrame() const;
	int32_t				GetFramesCount() const;

private:
	ImageId				m_ImageId;
	int32_t				m_FramesCount;
	int32_t				m_CurrFrame;
};

#endif // !SDL_UTILS_DRAWING_IMAGE_H_