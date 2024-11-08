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

	void				SetCurrFrame(int32_t frame);
	void				SetPrevFrame();
	void				SetNextFrame();

	int32_t				GetCurrFrame() const;
	
	const ImageData*	GetData() const;

private:
	int32_t				m_CurrFrame;

	const ImageData*	m_Data;
};