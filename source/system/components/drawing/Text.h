#ifndef COMPONENTS_DRAWING_TEXT_H_
#define COMPONENTS_DRAWING_TEXT_H_

#include "system/components/drawing/DrawObject.h"

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
	TextId				m_Id;
	const TextData*		m_Data;
};

#endif // !COMPONENTS_DRAWING_TEXT_H_