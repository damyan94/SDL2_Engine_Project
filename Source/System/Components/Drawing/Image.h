#pragma once

#include "System/Components/Drawing/DrawObject.h"
#include "System/SDLUtils/Containers/Data/ImageData.h"

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
	ImageId				m_ImageId;
	int32_t				m_CurrFrame;
	int32_t				m_FramesCount = 0;
};