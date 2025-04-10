#include "stdafx.h"

#include "System/Utils/InputOutput/Logger.h"

#include <iostream>

ELogLevel		Logger::m_LogLevel			= ELogLevel::LogInfo;
ETextColor		Logger::m_DefaultTextColor	= ETextColor::White;
ETextStyle		Logger::m_DefaultTextStyle	= ETextStyle::Regular;

static constexpr std::string_view GetTextColor(ETextColor textColor)
{
	switch (textColor)
	{
	case ETextColor::Black:		return "90m";
	case ETextColor::Red:		return "91m";
	case ETextColor::Green:		return "92m";
	case ETextColor::Yellow:	return "93m";
	case ETextColor::Blue:		return "94m";
	case ETextColor::Magenta:	return "95m";
	case ETextColor::Cyan:		return "96m";
	case ETextColor::White:		return "97m";
	default:					return "";
	}
}

static constexpr std::string_view GetTextStyle(ETextStyle textStyle)
{
	switch (textStyle)
	{
	case ETextStyle::Regular:			return "\033[0;";
	case ETextStyle::Dim:				return "\033[2;";
	case ETextStyle::Italic:			return "\033[3;";
	case ETextStyle::Underlined:		return "\033[4;";
	case ETextStyle::CrossedOut:		return "\033[9;";
	case ETextStyle::DoublyUnderlined:	return "\033[21";
	default:							return "";
	}
}

static File s_ErrorFile(Format("error_{0}.txt",
	Time::GetNow().GetString(ETimeStringFormat::Timestamp)), true);

static void SaveErrorFileOnExit()
{
	s_ErrorFile.Save();
}

////////////////////////////////////////////////////////////////////////////////
void Logger::Init()
{
	std::atexit(SaveErrorFileOnExit);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::Log(const std::string& text)
{
	Log(text, m_DefaultTextColor, m_DefaultTextStyle);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::Log(const std::string& text, ETextColor textColor)
{
	Log(text, textColor, m_DefaultTextStyle);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::Log(const std::string& text, ETextColor textColor, ETextStyle textStyle)
{
	ReturnIf(m_LogLevel < ELogLevel::LogText);
	PrintLineToConsole(text, textColor, textStyle, EMessageType::Text);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::LogError(const std::string& text)
{
	ReturnIf(m_LogLevel < ELogLevel::LogError);
	PrintLineToConsole("[ERROR] " + text, ETextColor::Red, ETextStyle::Regular, EMessageType::Error);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::LogWarning(const std::string& text)
{
	ReturnIf(m_LogLevel < ELogLevel::LogWarning);
	PrintLineToConsole("[WARNING] " + text, ETextColor::Yellow, ETextStyle::Regular, EMessageType::Error);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::LogInfo(const std::string& text)
{
	ReturnIf(m_LogLevel < ELogLevel::LogInfo);
	PrintLineToConsole("[INFO] " + text, ETextColor::White, ETextStyle::Regular, EMessageType::Text);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::SetLogLevel(ELogLevel logLevel)
{
	m_LogLevel = logLevel;
}

////////////////////////////////////////////////////////////////////////////////
ELogLevel Logger::GetLogLevel()
{
	return m_LogLevel;
}

////////////////////////////////////////////////////////////////////////////////
void Logger::TestLogging()
{
	const auto previousLogLevel = GetLogLevel();

	Log("----------------------------------------");
	Log("Text, log level = " + std::to_string((int8_t)GetLogLevel()), ETextColor::Blue);
	LogInfo("Info 1");
	LogWarning("Warning 1");
	LogError("Error 1");

	Log("----------------------------------------");
	SetLogLevel(ELogLevel::LogInfo);
	Log("Text, log level = " + std::to_string((int8_t)GetLogLevel()), ETextColor::Cyan, ETextStyle::Italic);
	LogInfo("Info 2");
	LogWarning("Warning 2");
	LogError("Error 2");

	Log("----------------------------------------");
	SetLogLevel(ELogLevel::LogWarning);
	Log("Text, log level = " + std::to_string((int8_t)GetLogLevel()), ETextColor::Green, ETextStyle::CrossedOut);
	LogInfo("Info 3");
	LogWarning("Warning 3");
	LogError("Error 3");

	Log("----------------------------------------");
	SetLogLevel(ELogLevel::LogError);
	Log("Text, log level = " + std::to_string((int8_t)GetLogLevel()), ETextColor::Magenta, ETextStyle::DoublyUnderlined);
	LogInfo("Info 4");
	LogWarning("Warning 4");
	LogError("Error 4");

	Log("----------------------------------------");
	SetLogLevel(ELogLevel::LogText);
	Log("Text, log level = " + std::to_string((int8_t)GetLogLevel()));
	LogInfo("Info 5");
	LogWarning("Warning 5");
	LogError("Error 5");

	Log("----------------------------------------");
	SetLogLevel(ELogLevel::LogNone);
	Log("Text, log level = " + std::to_string((int8_t)GetLogLevel()));
	LogInfo("Info 6");
	LogWarning("Warning 6");
	LogError("Error 6");
	Log("----------------------------------------");

	SetLogLevel(previousLogLevel);
}

////////////////////////////////////////////////////////////////////////////////
void Logger::PrintLineToConsole(const std::string& text,
	ETextColor textColor, ETextStyle textStyle, EMessageType messageType)
{
	AssertReturnIf(!IsEnumValueValid(messageType));
	AssertReturnIf(!IsEnumValueValid(textColor));
	AssertReturnIf(!IsEnumValueValid(textStyle));

	auto print = [&text, &textColor, &textStyle](std::ostream& outStream)
		{
#ifndef DISTRIBUTION
			outStream << GetTextStyle(textStyle) << GetTextColor(textColor);
			outStream << text << '\n';
			outStream << GetTextStyle(m_DefaultTextStyle) << GetTextColor(m_DefaultTextColor);
#endif
		};

	// Why do I even need different streams?
	switch (messageType)
	{
	case EMessageType::Text:
		print(std::cout);
		break;

	case EMessageType::Error:
		print(std::cerr);
		LogErrorToFile(text);
		break;

	default:
		Assert("Invalid message type.");
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////
void Logger::LogErrorToFile(const std::string& text)
{
	const auto timestamp = Time::GetNow().GetString(ETimeStringFormat::Default);
	s_ErrorFile.AddLine(Format("[{0}] ", timestamp) + text);
}