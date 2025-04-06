#pragma once

class File
{
public:
	File(const std::string& fileName, EWriteMode writeMode = EWriteMode::App, bool readEmptyLines = true, char commentIndicator = '\0');
	~File();

	File(const File& other);
	File(File&& other);
	File& operator=(const File& other);
	File& operator=(File&& other);

	bool Open();
	bool Close();
	bool IsOpen() const;

	bool ReadContents();
	bool Write(const std::string& writeString);


	bool SetWriteMode(EWriteMode writeMode);
	bool ClearFileContents();

	const std::string&	GetFileName() const;
	EWriteMode			GetWriteMode() const;
	const LinesOfText&	GetFileContents() const;

private:
	std::string			TrimCarriageReturn(const std::string& str);

private:
	std::string			m_FileName;
	EWriteMode			m_WriteMode;
	bool				m_ReadEmptyLines;
	char				m_CommentIndicator;

	std::fstream		m_FileStream;
	LinesOfText			m_Lines;
};