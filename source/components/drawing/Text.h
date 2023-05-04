#ifndef COMPONENTS_DRAWING_TEXT_H_
#define COMPONENTS_DRAWING_TEXT_H_

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/CommonIncludes.h"
#include "components/drawing/DrawObject.h"

// Forward declarations
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