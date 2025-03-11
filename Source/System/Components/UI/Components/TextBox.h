#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

#include "System/Components/UI/BaseClasses/UIComponentBase.h"
#include "System/Components/Drawing/Image.h"
#include "System/Components/Drawing/Text.h"
#include "System/Components/UI/UIUtils/TextInputter.h"

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
	void				Draw() const final;

	void				SetPosition(const Point& newPos) final;
	void				Reset() final;

	void				SetIsEnabled(bool enable) final;

	const std::string&	GetTextContent() const;

	void				ToggleShouldHandleEnterKey(bool enterKey);

	int32_t				m_MaxChars;

private:
	TextInputter		m_TextInputter;
};