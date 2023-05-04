#ifndef COMPONENTS_UI_COMPONENTS_TEXTBOX_H_
#define COMPONENTS_UI_COMPONENTS_TEXTBOX_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "sdl_utils/input/InputEvent.h"

#include "components/ui/base_classes/UIComponentBase.h"
#include "components/drawing/Image.h"
#include "components/drawing/Text.h"
#include "components/ui/ui_utils/TextInputter.h"

// Forward declarations
struct TextBoxConfig;

class TextBox
	: public UIComponentBase
{
public:
	TextBox();
	~TextBox();

	bool				Init(const TextBoxConfig& cfg);
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;

	void				SetPosition(const Point& newPos) final;
	void				Reset() final;

	void				SetIsEnabled(bool enable) final;

	const std::string&	GetTextContent() const;

	void				ToggleShouldHandleEnterKey(bool enterKey);

	int32_t				m_MaxChars;

private:
	TextInputter		m_TextInputter;
};

#endif // !COMPONENTS_UI_COMPONENTS_TEXTBOX_H_