#ifndef COMPONENTS_DRAWING_IMAGE_H_
#define COMPONENTS_DRAWING_IMAGE_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"
#include "components/drawing/DrawObject.h"

// Forward declarations
struct ImageData;

class Image
	: public DrawObject
{
public:
	Image();
	~Image();

	bool				Init(ImageId id);
	void				Deinit();
	void				Draw() const;

	void				SetCurrFrame(int32_t frame);
	void				SetPrevFrame();
	void				SetNextFrame();

	int32_t				GetCurrFrame() const;
	int32_t				GetFramesCount() const;

private:
	ImageId				m_Id;
	int32_t				m_CurrFrame;
	int32_t				m_FramesCount;

	const ImageData*	m_Data;
};

#endif // !COMPONENTS_DRAWING_IMAGE_H_