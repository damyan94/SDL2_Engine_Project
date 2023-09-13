#include "stdafx.h"

#include "utils/others/Crypto.h"

// =============================================================================
void Crypto::CaesarEncrypt(std::string& text, int32_t offset)
{
	for (auto& letter : text)
	{
		letter += offset;
	}
}

// =============================================================================
void Crypto::CaesarDecrypt(std::string& text, int32_t offset)
{
	for (auto& letter : text)
	{
		letter -= offset;
	}
}

// =============================================================================
void Crypto::CaesarMovingEncrypt(std::string& text, int32_t offset, int32_t limit)
{
	int32_t d = 0;
	for (auto& letter : text)
	{
		letter += (offset + d);
		d++;

		if (d >= limit)
		{
			d = 0;
		}
	}
}

// =============================================================================
void Crypto::CaesarMovingDecrypt(std::string& text, int32_t offset, int32_t limit)
{
	int32_t d = 0;
	for (auto& letter : text)
	{
		letter -= (offset + d);
		d++;

		if (d >= limit)
		{
			d = 0;
		}
	}
}

// =============================================================================
std::vector<int32_t> Crypto::CaesarRandomEncryptStoredOffsets(std::string& text,
	int32_t magicValue)
{
	int32_t textSize = (int32_t)text.size();
	std::string newText;
	std::vector<int32_t> offsets;
	offsets.reserve(textSize);

	for (int32_t i = 0; i < textSize; i++)
	{
		int32_t r = 0;
		auto newLetter = 'a';

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
bool Crypto::CaesarRandomDecrypt(std::string& text,
	const std::vector<int32_t>& offsets, int32_t magicValue)
{
	AssertReturnIf(text.size() != offsets.size(), false,
		"Decrypting function received invalid input.");

	int32_t textSize = (int32_t)text.size();
	std::string newText;

	for (int32_t i = 0; i < textSize; i++)
	{
		auto newLetter = text[i];
		newLetter -= (offsets[i] + magicValue);
		newText += newLetter;
	}

	text = newText;

	return true;
}

// =============================================================================
std::vector<int32_t> Crypto::CaesarRandomEncryptWithFillingStoredOffsets(std::string& text,
	int32_t magicValue, int32_t fillingCount)
{
	int32_t textSize = (int32_t)text.size();
	std::string newText;
	std::vector<int32_t> offsets;
	offsets.reserve(size_t(textSize) * size_t(fillingCount));

	for (int32_t i = 0; i < textSize * fillingCount; i++)
	{
		int32_t r = 0;
		auto newLetter = 'a';

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
bool Crypto::CaesarRandomDecryptWithFilling(std::string& text,
	const std::vector<int32_t>& offsets, int32_t magicValue, int32_t fillingCount)
{
	// Error, decrypting function received invalid input.
	ReturnIf(text.size() != offsets.size(), false);

	int32_t textSize = (int32_t)text.size();
	std::string newText;

	for (int32_t i = 0; i < textSize; i++)
	{
		if (i % fillingCount == 0)
		{
			auto newLetter = text[i];
			newLetter -= (offsets[i] + magicValue);
			newText += newLetter;
		}
	}

	text = newText;

	return true;
}

// =============================================================================
void Crypto::InvertBits(std::string& text)
{
	for (auto& letter : text)
	{
		letter = ~letter;
	}
}