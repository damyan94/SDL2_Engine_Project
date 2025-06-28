#include "stdafx.h"

#include "Application/Application.h"

#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>

constexpr size_t s_ExpectedArgumentsCount = 6;

// Jenkins One At A Time hashing algorithm
uint32_t Hash(const std::string& text)
{
    uint32_t result = 0;
    const size_t n = text.size();

    for (size_t i = 0; i < n; i++)
    {
        result += text[i];
        result += result << 10;
        result ^= result >> 6;
    }

    result += result << 3;
    result ^= result >> 11;
    result += result << 15;

    return result;
}

////////////////////////////////////////////////////////////////////////////////
struct Date
{
    uint32_t Day = 0;
    uint32_t Month = 0;
    uint32_t Year = 0;

    bool operator>(const Date& rhs) const
    {
        return Year > rhs.Year ||
            (Year == rhs.Year && Month > rhs.Month) ||
            (Year == rhs.Year && Month == rhs.Month && Day > rhs.Day);
    }

    bool operator<(const Date& rhs) const
    {
        return !operator>(rhs);
    }

    // Assumed date format is DD.MM.YYYY
    static Date ParseFromString(const std::string& dateString)
    {
        std::stringstream ss(dateString);
        std::string tmp;

        Date date;

        try
        {
            std::getline(ss, tmp, '.');
            date.Day = std::stoi(tmp);

            std::getline(ss, tmp, '.');
            date.Month = std::stoi(tmp);

            std::getline(ss, tmp, '.');
            date.Year = std::stoi(tmp);
        }
        catch (...)
        {
            std::cerr << "Invalid date format. Must be [DD.MM.YYYY], but was: "
                << dateString << std::endl;
        }

        return date;
    }

    static Date GetTodayDate()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%d.%m.%Y");

        return ParseFromString(ss.str());
    }
};

////////////////////////////////////////////////////////////////////////////////
struct LicenseData
{
    std::string Name;
    std::string DateIssued;
    std::string DateDue;
    std::string SecretPhrase;

    size_t GenerateHash() const
    {
        return Hash(Name + DateIssued + DateDue + SecretPhrase);
    }
};

////////////////////////////////////////////////////////////////////////////////
class License
{
public:
    License(const LicenseData& data = LicenseData()) : m_LicenseData(data)
    {
        m_Signature = m_LicenseData.GenerateHash();
    };

    ~License() = default;

    bool WriteLicenseFile(const std::string& fileName) const
    {
        std::ofstream file(fileName, std::ios::out);
        if (!file.is_open())
        {
            std::cerr << "Error, could not open file: " << fileName << std::endl;
            return false;
        }

        file << m_LicenseData.Name << '\n';
        file << m_LicenseData.DateIssued << '\n';
        file << m_LicenseData.DateDue << '\n';
        file << m_Signature;

        std::cout << "The secret phrase is: [" << m_LicenseData.SecretPhrase << "]." << std::endl;
        std::cout << "Remember it well, because it is used to validate the license." << std::endl;

        std::ofstream of("passphrase.txt");
        of << m_LicenseData.SecretPhrase;

        return true;
    }

    bool ReadLicenseFile(const std::string& fileName, const std::string& secretPhrase)
    {
        std::ifstream file(fileName, std::ios::in);
        if (!file.is_open())
        {
            std::cerr << "Error, could not open file: " << fileName << std::endl;
            return false;
        }

        std::getline(file, m_LicenseData.Name);
        std::getline(file, m_LicenseData.DateIssued);
        std::getline(file, m_LicenseData.DateDue);
        file >> m_Signature;

        m_LicenseData.SecretPhrase = secretPhrase;

        return true;
    }

    bool IsLicenseValid() const
    {
        if (m_LicenseData.GenerateHash() != m_Signature)
        {
            std::cerr << "License file corrupted." << std::endl;
            return false;
        }

        if (!IsValidDateDue())
        {
            std::cerr << "License is expired." << std::endl;
            return false;
        }

        return true;
    }

    bool IsValidDateDue() const
    {
        Date today = Date::GetTodayDate();
        Date licenseDateDue = Date::ParseFromString(m_LicenseData.DateDue);

        return today < licenseDateDue;
    }

private:
    LicenseData m_LicenseData;
    uint32_t m_Signature;
};

////////////////////////////////////////////////////////////////////////////////
int32_t main([[maybe_unused]] int32_t argC, [[maybe_unused]] char* argV[])
{
    //TODO move to application.init and use some string that is present in the program as the secret phrase
    License license;
    license.ReadLicenseFile("License.txt", "sokeresmondelez");
    if (!license.IsLicenseValid())
    {
        UI::ShowMessageBoxOK("Invalid License", "The license you are using is either invalid or expired. The application will now exit.",
            UI::EMessageBoxIcon::Info);
        return EXIT_FAILURE;
    }

	Application app;
	ReturnIf(!app.Init(), EXIT_FAILURE);

	app.RunApplication();

	return EXIT_SUCCESS;
}