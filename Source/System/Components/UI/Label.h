#pragma once

#include "System/SDLUtils/Input/InputEvent.h"

#include "System/Components/UI/UIComponentBase.h"
#include "System/Components/Drawing/Text.h"

struct LabelConfig;

class Label
	: public UIComponentBase
{
public:
	Label();
	~Label();

	bool				Init(const LabelConfig& cfg);
	void				Deinit() final;
	void				HandleEvent(const InputEvent& e) final;
	void				Update(int32_t dt) final;
	void				Draw() const final;

	void				SetPosition(const Point& newPos) final;
	void				Reset() final;

	void				SetIsEnabled(bool enable) final;

	void				SetPlaceholders(const std::vector<std::string>& values);

private:
	Text				m_Text;
};