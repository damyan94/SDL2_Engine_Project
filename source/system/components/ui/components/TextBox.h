#pragma once

#include "system/sdl_utils/input/InputEvent.h"

#include "system/components/ui/base_classes/UIComponentBase.h"
#include "system/components/drawing/Image.h"
#include "system/components/drawing/Text.h"
#include "system/components/ui/ui_utils/TextInputter.h"

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