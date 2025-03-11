#pragma once

#include "System/Components/Drawing/DrawObject.h"

struct TextData;

class Text
	: public DrawObject
{
public:
	Text();
	~Text();

	bool				Init(TextId id);
	void				Deinit();
	void				Draw() const;

private:
	TextId				m_TextId;
};