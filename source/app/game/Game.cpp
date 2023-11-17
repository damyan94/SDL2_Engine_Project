#include "stdafx.h"

#include "app/game/Game.h"
#include "app/game/config/GameConfig.h"

#include "system/utils/containers/BinaryStruct.h"

#include <locale>
#include <codecvt>

DynamicText displayText;
template<typename WString>
std::string WideStringToUTF8Bytes(const WString& wideString)
{
	return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wideString);
}

// =============================================================================
Game::Game()
{
}

// =============================================================================
Game::~Game()
{
}

// =============================================================================
bool Game::Init(const GameConfig& cfg)
{
	//ReturnUnless(!m_Camera.Init(), false);

	//BinaryStruct testStruct;

	/*uint8_t data[]
	{ 
		0xAA, 0xAA, 0xAA, 0x01,
		0x14, 0x00, 0x00, 0x00,

		0xAA, 0xAA, 0xAA, 0x02,
		0x04, 0x00, 0x00, 0x00,

		0x2, 0x4D, 0x00, 0x00,
	};*/
	String as("a");
	int an = 7;

	String bs("b");
	int bn = 123456;

	String cs("c");
	std::string cn = "Hello";

	constexpr size_t dataSize = 46;

	struct Data
	{
		Hash32 h;
		uint32_t size;

		Hash32 h1;
		uint32_t size1;
		int data1;

		Hash32 h2;
		uint32_t size2;
		int data2;

		Hash32 h3;
		uint32_t size3;
		char data3[6];
	};
	Data data{ as.m_Hash, dataSize , as.m_Hash, 4, an, bs.m_Hash, 4, bn, cs.m_Hash, 6 , "дедов" };

	std::ofstream out("binary_test.bin", std::ios::out | std::ios::binary);
	out.write(reinterpret_cast<char*>(&data), dataSize);
	out.close();

	//uint8_t newData[dataSize];
	//std::ifstream in("binary_test.bin", std::ios::in | std::ios::binary);
	//in.read(reinterpret_cast<char*>(&newData), dataSize);
	//in.close();
	//
	//testStruct.m_Data = newData;

	BinaryStruct testStruct(std::string("binary_test.bin"));

	String value;
	testStruct.Get("c", value);
	Log::Console(EConsoleTextColor::Green, value.m_String.c_str());

	uint32_t v = 0;
	testStruct.Get("a", v);
	Log::Console(EConsoleTextColor::Green, "%i", v);

	testStruct.Get("b", v);
	Log::Console(EConsoleTextColor::Green, "%i", v);

	testStruct.Get("does not exist", v);
	Log::Console(EConsoleTextColor::Green, "%i", v);

	displayText.Init(value.m_String, String("ARIAL_12").m_Hash, Colors::Black);
	displayText.SetPos(20, 20);

	//TODO logging doesn't support cyrillic
	Log::Console(EConsoleTextColor::Green, /*WideStringToUTF8Bytes(L*/"Какъв корав крив кур като кремиковски комин!"/*).c_str()*/);

	return true;
}

// =============================================================================
void Game::Deinit()
{
	m_Camera.Deinit();
}

// =============================================================================
void Game::HandleEvent(const InputEvent& e)
{
	m_Camera.HandleEvent(e);
}

// =============================================================================
void Game::Update(int32_t dt)
{
	m_Camera.Update(dt);
	ReturnUnless(m_Camera.HasCameraChanged(), void());

	const auto& cameraPos = m_Camera.GetPos();

}

// =============================================================================
const Camera& Game::GetCamera()
{
	return m_Camera;
}