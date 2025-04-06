#include "stdafx.h"

#include "System/Utils/InputOutput/File.h"

////////////////////////////////////////////////////////////////////////////////
File::File(const std::string& fileName, EWriteMode writeMode, bool readEmptyLines, char commentIndicator)
	: m_FileName(fileName)
	, m_WriteMode(writeMode)
	, m_ReadEmptyLines(readEmptyLines)
	, m_CommentIndicator(commentIndicator)
{
	Open();
}

////////////////////////////////////////////////////////////////////////////////
File::~File()
{
	Close();
}

////////////////////////////////////////////////////////////////////////////////
File::File(const File& other)
	: m_FileName(other.m_FileName)
	, m_WriteMode(other.m_WriteMode)
	, m_ReadEmptyLines(other.m_ReadEmptyLines)
	, m_CommentIndicator(other.m_CommentIndicator)
{
	Open();
}

////////////////////////////////////////////////////////////////////////////////
File::File(File&& other)
	: m_FileName(other.m_FileName)
	, m_WriteMode(other.m_WriteMode)
	, m_ReadEmptyLines(other.m_ReadEmptyLines)
	, m_CommentIndicator(other.m_CommentIndicator)
{
	Open();
}

////////////////////////////////////////////////////////////////////////////////
File& File::operator=(const File& other)
{
	m_FileName = other.m_FileName;
	m_WriteMode = other.m_WriteMode;
	m_ReadEmptyLines = other.m_ReadEmptyLines;
	m_CommentIndicator = other.m_CommentIndicator;
	Open();

	return *this;
}

////////////////////////////////////////////////////////////////////////////////
File& File::operator=(File&& other)
{
	m_FileName = other.m_FileName;
	m_WriteMode = other.m_WriteMode;
	m_ReadEmptyLines = other.m_ReadEmptyLines;
	m_CommentIndicator = other.m_CommentIndicator;
	Open();

	return *this;
}

////////////////////////////////////////////////////////////////////////////////
bool File::Open()
{
	AssertReturnIf(IsOpen() && "The file is already open.", false);

	switch (m_WriteMode)
	{
	case EWriteMode::Out:
		m_FileStream.open(m_FileName, std::ios::in | std::ios::out);
		break;

	case EWriteMode::App:
		m_FileStream.open(m_FileName, std::ios::in | std::ios::app);
		break;

	default:
		AssertReturnIf(true && "Unsupported file open mode.", false);
	}

	ReturnIf(!ReadContents() && "Failed to read file contents.", false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool File::Close()
{
	ReturnIf(!IsOpen(), false);

	m_FileStream.close();
	m_Lines.clear();

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool File::IsOpen() const
{
	return m_FileStream.is_open();
}

////////////////////////////////////////////////////////////////////////////////
bool File::ReadContents()
{
	AssertReturnIf(!IsOpen() && "The file is not open.", false);

	m_FileStream.clear();
	m_FileStream.seekg(0, std::ios::beg);

	m_Lines.clear();
	m_Lines.reserve(10);

	std::string readLine;
	while (std::getline(m_FileStream, readLine))
	{
		//TODO make this part of the csv parser, here it should read the entire file
		//The '#' symbol will indicate a commented line in the input file
		ContinueIf(m_ReadEmptyLines && readLine.empty());
		ContinueIf(m_CommentIndicator != '\0' && readLine[0] == '#');

		m_Lines.emplace_back(TrimCarriageReturn(readLine));
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool File::Write(const std::string& writeString)
{
	AssertReturnIf(!IsOpen() && "The file is not open.", false);

	m_FileStream << writeString;
	AssertReturnIf(m_FileStream.fail() && "Write to file failed.", false);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
bool File::SetWriteMode(EWriteMode writeMode)
{
	ReturnIf(!Close(), false);

	m_WriteMode = writeMode;

	return Open();
}

////////////////////////////////////////////////////////////////////////////////
bool File::ClearFileContents()
{
	ReturnIf(!Close(), false);

	m_FileStream.open(m_FileName, std::ios::out | std::ios::trunc);
	AssertReturnIf(!IsOpen() && "File clean failed.", false);

	return SetWriteMode(m_WriteMode);
}

////////////////////////////////////////////////////////////////////////////////
const std::string& File::GetFileName() const
{
	return m_FileName;
}

////////////////////////////////////////////////////////////////////////////////
EWriteMode File::GetWriteMode() const
{
	return m_WriteMode;
}

////////////////////////////////////////////////////////////////////////////////
const LinesOfText& File::GetFileContents() const
{
	return m_Lines;
}

////////////////////////////////////////////////////////////////////////////////
//TODO Can be exported to StringUtils.h/.cpp or something
std::string File::TrimCarriageReturn(const std::string& str)
{
	ReturnIf(!str.empty() && str.back() == '\r', str.substr(0, str.size() - 1));

	return str;
}