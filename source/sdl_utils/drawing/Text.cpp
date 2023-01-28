// Corresponding header
#include "sdl_utils/drawing/Text.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/containers/FontContainer.h"

// =============================================================================
Text::~Text()
{
	Deinit();
}

// =============================================================================
int32_t Text::Init(const std::wstring& text, int32_t fontId, const Color& textColor)
{
	Texture::CreateTextureFromText(text, textColor,
		FontContainer::GetFontById(fontId), _texture, _width, _height);
	if (!_texture)
	{
		std::cerr << "Error, Texture::CreateTextureFromText() failed for id: "
			<< _id << std::endl;
		return EXIT_FAILURE;
	}

	_pos = Point::Zero;
	_frameRect.w = _width;
	_frameRect.h = _height;
	_standardWidth = _width;
	_standardHeight = _height;
	
	_rotationCenter = Point(_width / 2, _height / 2);
	
	_id = fontId;
	_type = ObjectType::TEXT;
	
	_text = text;
	_color = textColor;
	_fontSize = FontContainer::GetFontSizeById(fontId);

	return EXIT_SUCCESS;
}

// =============================================================================
void Text::Deinit()
{
	Texture::DestroyTexture(_texture);
}

// =============================================================================
void Text::Draw() const
{
	if (!_isVisible)
	{
		return;
	}

	Texture::SetTextureAlphaMod(_texture, _opacity);
	if (_opacity <= 0)
	{
		return;
	}

	Rectangle rect{ _pos.x, _pos.y, _width, _height };
	Texture::RenderTexture(_texture, _frameRect, rect, (double)_rotationAngle,
		_rotationCenter, _flipMode);
}

// =============================================================================
void Text::SetText(const std::wstring& newText)
{
	Texture::DestroyTexture(_texture);
	Texture::CreateTextureFromText(newText, _color,
		FontContainer::GetFontById(_id), _texture, _width, _height);
	if (!_texture)
	{
		std::cerr << "Error, Texture::CreateTextureFromText() failed for id: "
			<< _id << std::endl;
		return;
	}

	_frameRect.w = _width;
	_frameRect.h = _height;
	_standardWidth = _width;
	_standardHeight = _height;
	_text = newText;
}

// =============================================================================
void Text::SetColor(const Color& newColor)
{
	Texture::DestroyTexture(_texture);
	Texture::CreateTextureFromText(_text, newColor,
		FontContainer::GetFontById(_id), _texture, _width, _height);
	if (!_texture)
	{
		std::cerr << "Error, Texture::CreateTextureFromText() failed for id: "
			<< _id << std::endl;
		return;
	}

	_frameRect.w = _width;
	_frameRect.h = _height;
	_standardWidth = _width;
	_standardHeight = _height;
	_color = newColor;
}

// =============================================================================
std::wstring Text::GetText() const
{
	return _text;
}

// =============================================================================
Color Text::GetColor() const
{
	return _color;
}

// =============================================================================
int32_t Text::GetFontSize() const
{
	return _fontSize;
}