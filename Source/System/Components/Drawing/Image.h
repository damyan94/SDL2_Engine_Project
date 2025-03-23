#pragma once

#include "System/Components/Drawing/DrawObject.h"

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
	int32_t				GetFramesCount() const;

private:
	int32_t				m_CurrFrame;
	int32_t				m_FramesCount;
};