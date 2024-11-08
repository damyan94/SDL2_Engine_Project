#pragma once

class Texture;

struct ImageData
{
	ImageData();
	ImageData(Texture* texture, Rectangle frameRect, int32_t framesCount);
	~ImageData();

	Texture*			m_Texture;
	Rectangle			m_FrameRect				= Rectangle::Undefined;
	int32_t				m_FramesCount			= 0;
};