#pragma once

#include "System/Components/Drawing/DrawObject.h"

class Text
	: public DrawObject
{
public:
	Text();
	~Text();

	bool				Init(TextId id);
	void				Deinit();

	void				SetPlaceholders(const std::vector<std::string>& values);

private:
};