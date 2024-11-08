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

	const TextData*		GetData() const;

private:
	const TextData*		m_Data;
};