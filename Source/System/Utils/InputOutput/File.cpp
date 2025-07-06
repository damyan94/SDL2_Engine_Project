#include "stdafx.h"

#include "System/Utils/InputOutput/File.h"

#include <fstream>
#include <filesystem>

//////////////////////////////////////////////////////////////////////////////////
File::File(const std::string& fileName, bool autoSave)
    : m_FileName(fileName)
    , m_Autosave(autoSave)
{
    if (Create())
    {
        Load();
    }
}

//////////////////////////////////////////////////////////////////////////////////
File::~File()
{
    if (m_Autosave)
    {
        Save();
    }
}

//////////////////////////////////////////////////////////////////////////////////
void File::Load()
{
    m_Lines.clear();
    std::ifstream file(m_FileName);
    AssertReturnIf(!file.is_open());

    std::string line;
    while (std::getline(file, line))
    {
        m_Lines.push_back(line);
    }
}

//////////////////////////////////////////////////////////////////////////////////
void File::Save() const
{
    std::ofstream file(m_FileName, std::ios::trunc);
    AssertReturnIf(!file.is_open());

    for (const auto& line : m_Lines)
    {
        file << line << '\n';
    }
}

//////////////////////////////////////////////////////////////////////////////////
void File::AddLine(const std::string& line)
{
    m_Lines.push_back(line);
}

//////////////////////////////////////////////////////////////////////////////////
void File::InsertLine(const std::string& line, std::size_t index)
{
    AssertReturnIf(index > m_Lines.size());
    m_Lines.insert(m_Lines.begin() + index, line);
}

//////////////////////////////////////////////////////////////////////////////////
void File::DeleteLine(std::size_t index)
{
    AssertReturnIf(!HasLine(index));
    m_Lines.erase(m_Lines.begin() + index);
}

//////////////////////////////////////////////////////////////////////////////////
void File::DeleteAllLines()
{
    m_Lines.clear();
}

//////////////////////////////////////////////////////////////////////////////////
bool File::HasLine(size_t index) const
{
    return index < m_Lines.size();
}

//////////////////////////////////////////////////////////////////////////////////
size_t File::GetLinesCount() const
{
    return m_Lines.size();
}

//////////////////////////////////////////////////////////////////////////////////
const StringVector& File::GetLines() const
{
    return m_Lines;
}

//////////////////////////////////////////////////////////////////////////////////
StringVector& File::GetLinesMutable()
{
    return m_Lines;
}

//////////////////////////////////////////////////////////////////////////////////
bool File::Create()
{
    ReturnIf(std::filesystem::exists(m_FileName), true);

    std::ofstream file(m_FileName);
    AssertReturnIf(!file.is_open(), false);

    return true;
}

//////////////////////////////////////////////////////////////////////////////////
std::string File::TrimCarriageReturn(const std::string& str)
{
	ReturnIf(!str.empty() && str.back() == '\r', str.substr(0, str.size() - 1));

	return str;
}