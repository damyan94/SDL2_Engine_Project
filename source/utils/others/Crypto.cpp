// Corresponding header
#include "utils/others/Crypto.h"

// C/C++ system includes
#include <iostream>

// Third-party includes

// Own includes

// =============================================================================
void Crypto::CaesarEncrypt(std::wstring& text, int32_t offset)
{
	for (wchar_t& letter : text)
	{
		letter += offset;
	}
}

// =============================================================================
void Crypto::CaesarDecrypt(std::wstring& text, int32_t offset)
{
	for (wchar_t& letter : text)
	{
		letter -= offset;
	}
}

// =============================================================================
void Crypto::CaesarMovingEncrypt(std::wstring& text, int32_t offset)
{
	int32_t d = 0;
	for (wchar_t& letter : text)
	{
		letter += (offset + d);
		d++;
	}
}

// =============================================================================
void Crypto::CaesarMovingDecrypt(std::wstring& text, int32_t offset)
{
	int32_t d = 0;
	for (wchar_t& letter : text)
	{
		letter -= (offset + d);
		d++;
	}
}

// =============================================================================
std::vector<int32_t> Crypto::CaesarRandomEncryptStoredOffsets(std::wstring& text,
	int32_t magicValue)
{
	int32_t textSize = (int32_t)text.size();
	std::wstring newText;
	std::vector<int32_t> offsets;
	offsets.reserve(textSize);

	for (int32_t i = 0; i < textSize; i++)
	{
		int32_t r = 0;
		wchar_t newLetter = 'a';

		do
		{
			newLetter = text[i];
			r = rand() % 10;
			newLetter += r + magicValue;
		} while (newLetter < 0);

		newText += newLetter;
		offsets.push_back(r);
	}

	text = newText;

	return offsets;
}

//// =============================================================================
//bool Crypto::CaesarRandomEncryptHardcodedOffsets(std::wstring& text,
//	const std::vector<int32_t>& offsets, int32_t magicValue)
//{
//	if (text.size() != offsets.size())
//	{
//		std::cerr << "Error, decrypting function received invalid input."
//			<< std::endl;
//		return false;
//	}
//
//	int32_t textSize = (int32_t)text.size();
//	std::wstring newText;
//
//	for (int32_t i = 0; i < textSize; i++)
//	{
//		wchar_t newLetter = text[i];
//		newLetter += (offsets[i] + magicValue);
//		newText += newLetter;
//	}
//
//	text = newText;
//
//	return true;
//}

// =============================================================================
bool Crypto::CaesarRandomDecrypt(std::wstring& text,
	const std::vector<int32_t>& offsets, int32_t magicValue)
{
	// Error, decrypting function received invalid input.
	AssertReturnIf(text.size() != offsets.size(), false);

	int32_t textSize = (int32_t)text.size();
	std::wstring newText;

	for (int32_t i = 0; i < textSize; i++)
	{
		wchar_t newLetter = text[i];
		newLetter -= (offsets[i] + magicValue);
		newText += newLetter;
	}

	text = newText;

	return true;
}

// =============================================================================
std::vector<int32_t> Crypto::CaesarRandomEncryptWithFillingStoredOffsets(std::wstring& text,
	int32_t magicValue, int32_t fillingCount)
{
	int32_t textSize = (int32_t)text.size();
	std::wstring newText;
	std::vector<int32_t> offsets;
	offsets.reserve(size_t(textSize * fillingCount));

	for (int32_t i = 0; i < textSize * fillingCount; i++)
	{
		int32_t r = 0;
		wchar_t newLetter = 'a';

		if (i % fillingCount == 0)
		{
			do
			{
				newLetter = text[i / fillingCount];
				r = rand() % 10;
				newLetter += r + magicValue;
			} while (newLetter < 0);
		}
		else
		{
			newLetter = rand() % 222 + 33;
			r = rand() % 10;
		}

		newText += newLetter;
		offsets.push_back(r);
	}

	text = newText;

	return offsets;
}

//// =============================================================================
//bool Crypto::CaesarRandomEncryptWithFillingHardcodedOffsets(std::wstring& text,
//	const std::vector<int32_t>& offsets, int32_t magicValue, int32_t fillingCount)
//{
//	if (text.size() != offsets.size())
//	{
//		std::cerr << "Error, decrypting function received invalid input."
//			<< std::endl;
//		return false;
//	}
//
//	int32_t textSize = (int32_t)text.size();
//	std::wstring newText;
//
//	for (int32_t i = 0; i < textSize * fillingCount; i++)
//	{
//		wchar_t newLetter = 'a';
//		if (i % fillingCount == 0)
//		{
//			newLetter = text[i / fillingCount];
//			newLetter += (offsets[i] + magicValue);
//		}
//		else
//		{
//			newLetter = rand() % 222 + 33;
//		}
//
//		newText += newLetter;
//	}
//
//	text = newText;
//
//	return true;
//}

// =============================================================================
bool Crypto::CaesarRandomDecryptWithFilling(std::wstring& text,
	const std::vector<int32_t>& offsets, int32_t magicValue, int32_t fillingCount)
{
	// Error, decrypting function received invalid input.
	ReturnIf(text.size() != offsets.size(), false);

	int32_t textSize = (int32_t)text.size();
	std::wstring newText;

	for (int32_t i = 0; i < textSize; i++)
	{
		if (i % fillingCount == 0)
		{
			wchar_t newLetter = text[i];
			newLetter -= (offsets[i] + magicValue);
			newText += newLetter;
		}
	}

	text = newText;

	return true;
}

// =============================================================================
void Crypto::InvertBits(std::wstring& text)
{
	for (wchar_t& letter : text)
	{
		letter = ~letter;
	}
}