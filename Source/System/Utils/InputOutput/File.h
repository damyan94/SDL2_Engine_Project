#pragma once

class File
{
public:
	File(const std::string& fileName, bool autoSave = false);
	~File();

	void				Load();
	void				Save() const;

	void				AddLine(const std::string& line);
	void				InsertLine(const std::string& line, size_t index);
	void				DeleteLine(size_t index);
	void				DeleteAllLines();
	bool				HasLine(size_t index) const;
	size_t				GetLinesCount() const;

	const LinesOfText&	GetLines() const;
	LinesOfText&		GetLinesMutable();

private:
	bool				Create();
	std::string			TrimCarriageReturn(const std::string& str);

private:
	const std::string	m_FileName;
	const bool			m_Autosave;
	LinesOfText			m_Lines;
};