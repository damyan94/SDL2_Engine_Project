#ifndef COMPONENTS_UI_UI_UTILS_TEXTINPUTTER_H_
#define COMPONENTS_UI_UI_UTILS_TEXTINPUTTER_H_

// C/C++ system includes
#include <cstdint>
#include <vector>
#include <string>

// Third-party includes

// Own includes
#include "utils/Defines.h"
#include "sdl_utils/Defines.h"
#include "sdl_utils/input/InputEvent.h"

#include "components/ui/base_classes/UIComponentBase.h"
#include "components/drawing/Image.h"
#include "components/drawing/DynamicText.h"
#include "components/audio/Sound.h"
#include "components/time/Timer.h"

// Forward declarations
class InputEvent;

struct TextInputterConfig
{
	Point				m_Pos					= Point::Undefined;
	int32_t				m_MaxChars				= 0;
	std::string			m_TextString;
	FontId				m_FontId				= 0;
	Color				m_Color					= Colors::Black;
};

class TextInputter
{
public:
	TextInputter();
	~TextInputter();

	bool				Init(const TextInputterConfig& cfg);
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);
	void				Draw() const;

	void				SetPosition(const Point& newPos);
	void				ToggleActive(bool activate);
	void				ToggleShouldHandleEnterKey(bool enterKey);

	int32_t				GetHeight() const;
	const std::string& GetTextContent() const;

	void				Reset();

private:
	void				HandleHistoryNavigation(const InputEvent& e);
	void				HandleHorizontalNavigation(const InputEvent& e);
	void				HandleTextInput(const InputEvent& e);
	void				HandleDeletion(const InputEvent& e);
	void				HandleEnterKey(const InputEvent& e);

private:
	Point				m_Pos;
	bool				m_IsActive;
	bool				m_IsDirty;
	bool				m_ShouldHandleEnterKey;

	int32_t				m_MaxChars;
	std::string			m_TextContent;
	std::wstring		m_WSTextContent;

	int32_t				m_CursorPos;
	int32_t				m_WSCursorPos;

	std::vector<std::string> m_History;
	int32_t				m_CurrHistory;

	Timer				m_CursorTimer;
	DynamicText			m_Text;
	DynamicText			m_Cursor;
};

#endif // !COMPONENTS_UI_UI_UTILS_TEXTINPUTTER_H_