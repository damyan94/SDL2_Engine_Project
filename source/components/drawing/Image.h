#ifndef COMPONENTS_DRAWING_IMAGE_H_
#define COMPONENTS_DRAWING_IMAGE_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"
#include "components/drawing/DrawObject.h"
#include "sdl_utils/containers/image_container/ImageData.h"

// Forward declarations

class Image
	: public DrawObject
{
public:
	Image();
	~Image();

	bool				Init(ImageId id);
	void				Deinit();

	void				SetCurrFrame(int32_t frame);
	void				SetPrevFrame();
	void				SetNextFrame();

	int32_t				GetCurrFrame() const;
	
	const ImageData*	GetData() const;

private:
	ImageId				m_Id;
	int32_t				m_CurrFrame;

	const ImageData*	m_Data;
};

#endif // !COMPONENTS_DRAWING_IMAGE_H_