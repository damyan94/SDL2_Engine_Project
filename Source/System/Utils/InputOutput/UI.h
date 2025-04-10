#pragma once

namespace UI
{
enum class EMessageBoxIcon
    : int8_t
{
    Invalid = -1
    , Error
    , Warning
    , Info
    , Count
};

void ShowMessageBoxOK(const std::string& title, const std::string& text, EMessageBoxIcon icon);
} // !namespace UI