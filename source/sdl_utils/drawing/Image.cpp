// Corresponding header
#include "sdl_utils/drawing/Image.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/ImageContainer.h"

// =============================================================================
int32_t Image::Init(int32_t imageId)
{
	_texture = ImageContainer::GetImageTextureById(imageId);
	if (!_texture)
	{
		std::cerr << "Error, ImageContainer::getImageTextureById() failed for id: "
			<< imageId << std::endl;
		return EXIT_FAILURE;
	}
	_frameRect = ImageContainer::GetImageTextureFrameById(imageId);

	_pos = Point::Zero;
	_width = _frameRect.w;
	_height = _frameRect.h;
	_standardWidth = _width;
	_standardHeight = _height;
	
	_rotationCenter = Point(_width / 2, _height / 2);
	
	_id = imageId;
	_type = ObjectType::IMAGE;
	
	_framesCount = ImageContainer::GetImageFramesCountById(imageId);

	return EXIT_SUCCESS;
}

// =============================================================================
void Image::Deinit()
{
	// This would destroy the texture inside the container
	//Texture::destroyTexture(texture);
}

// =============================================================================
void Image::Draw() const
{
	if (!_isVisible)
	{
		return;
	}

	Texture::SetTextureAlphaMod(ImageContainer::GetImageTextureById(_id), _opacity);
	if (_opacity <= 0)
	{
		return;
	}

	Rectangle rect{ _pos.x, _pos.y, _width, _height };
	Texture::RenderTexture(ImageContainer::GetImageTextureById(_id), _frameRect,
		rect, (double)_rotationAngle, _rotationCenter, _flipMode);
}

// =============================================================================
void Image::SetFrame(int32_t frame)
{
	if (frame <= 0 || frame > _framesCount)
	{
		std::cerr << "Error, received invalid frame index for image with id: "
			<< _id << std::endl;
		return;
	}

	_currFrame = frame;
	_frameRect.x = (_currFrame - 1) * _standardWidth;
}

// =============================================================================
void Image::SetPrevFrame()
{
	if (_currFrame > 1)
	{
		_currFrame--;
	}

	_frameRect.x = (_currFrame - 1) * _standardWidth;
}

// =============================================================================
void Image::SetNextFrame()
{
	if (_currFrame < _framesCount)
	{
		_currFrame++;
	}

	_frameRect.x = (_currFrame - 1) * _standardWidth;
}

// =============================================================================
int32_t Image::GetCurrFrame() const
{
	return _currFrame;
}

// =============================================================================
int32_t Image::GetFramesCount() const
{
	return _framesCount;
}