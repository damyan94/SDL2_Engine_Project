#include "stdafx.h"

#include <locale>
#include <codecvt>

#include "System/Components/UI/UIUtils/TextInputter.h"

#include "System/SDLUtils/Input/InputEvent.h"

static const int32_t	c_MaxHistoryRecords		= 100;
static const int32_t	c_CursorTickTime		= 1000;
static const char*		c_CursorSymbol			= "|";

//TODO move to some utils namespace
////////////////////////////////////////////////////////////////////////////////
template<typename String>
std::wstring UTF8BytesToWideString(const String& utf8_Bytes)
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(utf8_Bytes);
}

////////////////////////////////////////////////////////////////////////////////
template<typename WString>
std::string WideStringToUTF8Bytes(const WString& wideString)
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wideString);
}

////////////////////////////////////////////////////////////////////////////////
TextInputter::TextInputter()
	: m_Pos(Point::Undefined)
	, m_IsEnabled(false)
	, m_IsActive(false)
	, m_IsDirty(false)
	, m_ShouldHandleEnterKey(false)
	, m_MaxChars(0)
	, m_CursorPos(0)
	, m_WSCursorPos(0)
	, m_CurrHistory(0)
{
}

////////////////////////////////////////////////////////////////////////////////
TextInputter::~TextInputter()
{
}

////////////////////////////////////////////////////////////////////////////////
bool TextInputter::Init(const TextInputterConfig& cfg)
{
	SetPosition(cfg.m_Pos);

	m_MaxChars			= cfg.m_MaxChars;
	m_TextContent		= cfg.m_TextString;
	m_WSTextContent		= UTF8BytesToWideString(m_TextContent);
	m_CursorPos			= m_TextContent.size();
	m_WSCursorPos		= m_WSTextContent.size();

	m_History.reserve(c_MaxHistoryRecords * 32);

	m_CursorTimer.Start(c_CursorTickTime, ETimerType::Pulse);
	m_CursorTimer.SetPause(true);

	m_Text.Init(cfg.m_TextString, cfg.m_FontId, cfg.m_Color);

	m_Cursor.Init(c_CursorSymbol, cfg.m_FontId, cfg.m_Color);
	m_Cursor.SetIsVisible(false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::Deinit()
{
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::HandleEvent(const InputEvent& e)
{
	ReturnIf(!m_IsEnabled);

	ReturnIf(!m_IsActive);
	ReturnIf(!(e.m_Type == EEventType::KeyboardPress || e.m_Type == EEventType::TextInput));

	if (e.m_Key == EKeyboardKey::Escape)
	{
		Reset();
		return;
	}

	HandleHistoryNavigation(e);
	HandleHorizontalNavigation(e);
	HandleTextInput(e);
	HandleDeletion(e);
	HandleEnterKey(e);
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::Update(int32_t dt)
{
	ReturnIf(!m_IsEnabled);

	if (!m_CursorTimer.IsPaused() && m_CursorTimer.IsTicked())
	{
		m_Cursor.SetIsVisible(!m_Cursor.IsVisible());
	}
	m_Cursor.SetPos(m_Pos.x + m_WSCursorPos * m_Cursor.GetWidth() - 3, m_Pos.y + 1);

	ReturnIf(!m_IsActive || !m_IsDirty);

	m_Text.SetText(m_TextContent);

	m_IsDirty = false;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::SetPosition(const Point& newPos)
{
	m_Pos = newPos;
	m_Text.SetPos(m_Pos.x, m_Pos.y + 2);
	m_Cursor.SetPos(m_Pos.x + m_WSCursorPos * m_Cursor.GetWidth() - 3, m_Pos.y + 1);
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::ToggleActive(bool activate)
{
	m_CursorTimer.SetPause(!activate);
	m_IsActive = activate;
	InputEvent::ToggleTextInput(activate);
}

////////////////////////////////////////////////////////////////////////////////
int32_t TextInputter::GetHeight() const
{
	return m_Cursor.GetHeight();
}

////////////////////////////////////////////////////////////////////////////////
const std::string& TextInputter::GetTextContent() const
{
	return m_TextContent;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::ToggleShouldHandleEnterKey(bool enterKey)
{
	m_ShouldHandleEnterKey = enterKey;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::Reset()
{
	m_CurrHistory		= m_History.size();
	m_CursorPos			= m_TextContent.size();
	m_WSTextContent		= UTF8BytesToWideString(m_TextContent);
	m_WSCursorPos		= m_WSTextContent.size();
	m_CursorTimer.SetPause(true);
	m_Cursor.SetIsVisible(false);
	InputEvent::ToggleTextInput(false);
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::Show()
{
	m_IsEnabled = true;
	m_Text.SetIsVisible(true);
	m_Cursor.SetIsVisible(true);
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::Hide()
{
	m_IsEnabled = false;
	m_Text.SetIsVisible(false);
	m_Cursor.SetIsVisible(false);
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::HandleHistoryNavigation(const InputEvent& e)
{
	// Handle history navigation
	ReturnIf(e.m_Type != EEventType::KeyboardPress);
	ReturnIf(!(e.m_Key == EKeyboardKey::Up || e.m_Key == EKeyboardKey::Down));

	if (e.m_Key == EKeyboardKey::Up)
	{
		m_CurrHistory--;
	}
	else if (e.m_Key == EKeyboardKey::Down)
	{
		m_CurrHistory++;
	}

	// Handle history record out of bounds
	if (m_CurrHistory < -1)
	{
		m_CurrHistory = -1;
		m_TextContent.clear();
		m_WSTextContent.clear();
	}
	else if (m_CurrHistory >= (int32_t)m_History.size() + 1)
	{
		m_CurrHistory = m_History.size();
	}

	// Handle valid history record
	if (m_CurrHistory >= 0 && m_CurrHistory < (int32_t)m_History.size())
	{
		m_TextContent = m_History[m_CurrHistory];
		m_WSTextContent = UTF8BytesToWideString(m_TextContent);
	}
	else
	{
		m_TextContent.clear();
		m_WSTextContent.clear();
	}

	// Handle history string shorter than current input
	if (m_CursorPos > m_TextContent.size())
	{
		m_CursorPos = m_TextContent.size();
	}
	if (m_WSCursorPos > m_WSTextContent.size())
	{
		m_WSCursorPos = m_WSTextContent.size();
	}

	m_IsDirty = true;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::HandleHorizontalNavigation(const InputEvent& e)
{
	// Handle arrow keys navigation
	ReturnIf(e.m_Type != EEventType::KeyboardPress);
	ReturnIf(!(e.m_Key == EKeyboardKey::Left || e.m_Key == EKeyboardKey::Right));

	if (e.m_Key == EKeyboardKey::Left)
	{
		ReturnIf(m_WSCursorPos <= 0);

		m_WSCursorPos--;
		size_t movedBytes = WideStringToUTF8Bytes(m_WSTextContent[m_WSCursorPos]).size();
		m_CursorPos -= movedBytes;
	}
	else if (e.m_Key == EKeyboardKey::Right)
	{
		ReturnIf(m_WSCursorPos >= m_WSTextContent.size());

		size_t movedBytes = WideStringToUTF8Bytes(m_WSTextContent[m_WSCursorPos]).size();
		m_WSCursorPos++;
		m_CursorPos += movedBytes;
	}

	m_IsDirty = true;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::HandleTextInput(const InputEvent& e)
{
	// Handle keyboard input
	ReturnIf(e.m_Type != EEventType::TextInput);
	ReturnIf(!e.m_TextInput);
	ReturnIf((int32_t)m_WSTextContent.size() >= m_MaxChars);

	size_t inputSize = strlen(e.m_TextInput);
	for (size_t i = 0; i < inputSize; i++)
	{
		m_TextContent.insert(m_CursorPos, 1, e.m_TextInput[i]);
		m_CursorPos++;
	}
	const auto& wSCharsToInsert = UTF8BytesToWideString(e.m_TextInput);
	m_WSTextContent += wSCharsToInsert;
	m_WSCursorPos += wSCharsToInsert.size();

	m_CurrHistory = m_History.size();
	m_IsDirty = true;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::HandleDeletion(const InputEvent& e)
{
	// Handle backspace and delete
	ReturnIf(e.m_Type != EEventType::KeyboardPress);
	ReturnIf(!(e.m_Key == EKeyboardKey::Backspace || e.m_Key == EKeyboardKey::Delete));

	if (e.m_Key == EKeyboardKey::Backspace)
	{
		ReturnIf(m_CursorPos <= 0 || m_WSCursorPos <= 0);

		m_WSCursorPos--;
		auto& wSCharToDelete = m_WSTextContent[m_WSCursorPos];
		size_t bytesToDelete = WideStringToUTF8Bytes(wSCharToDelete).size();
		m_WSTextContent.erase(m_WSCursorPos, 1);

		m_CursorPos -= bytesToDelete;
		m_TextContent.erase(m_CursorPos, bytesToDelete);
	}
	else if (e.m_Key == EKeyboardKey::Delete)
	{
		ReturnIf(m_CursorPos >= (int32_t)m_TextContent.size() || m_WSCursorPos >= (int32_t)m_WSTextContent.size());

		auto& wSCharToDelete = m_WSTextContent[m_WSCursorPos];
		size_t bytesToDelete = WideStringToUTF8Bytes(wSCharToDelete).size();
		m_TextContent.erase(m_CursorPos, bytesToDelete);
		m_WSTextContent.erase(m_WSCursorPos, 1);
	}

	m_IsDirty = true;
}

////////////////////////////////////////////////////////////////////////////////
void TextInputter::HandleEnterKey(const InputEvent& e)
{
	// Handle enter key
	ReturnIf(e.m_Type != EEventType::KeyboardPress);
	ReturnIf(!(e.m_Key == EKeyboardKey::Return || e.m_Key == EKeyboardKey::Numpad_Enter));

	if (m_TextContent.size() > 0)
	{
		m_History.push_back(m_TextContent);
	}
	if (m_History.size() >= c_MaxHistoryRecords)
	{
		m_History.erase(m_History.begin());
	}
	m_CursorPos = 0;
	m_TextContent.clear();
	m_WSTextContent = UTF8BytesToWideString(m_TextContent);
	m_WSCursorPos = m_WSTextContent.size();
	m_Text.SetText("");

	m_IsDirty = true;
}