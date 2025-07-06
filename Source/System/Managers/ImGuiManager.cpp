#include "stdafx.h"

#define IMGUI_HAS_DOCK

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "System/Managers/ImGuiManager.h"
#include "System/Managers/Config/ImGuiManagerConfig.h"

#include "System/SDLUtils/Drawing/Window.h"
#include "System/SDLUtils/Drawing/Renderer.h"

#include "System/Managers/DrawManager.h"

//// Our state
//bool show_demo_window = true;
//bool show_another_window = false;
//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

////////////////////////////////////////////////////////////////////////////////
ImGuiManager::ImGuiManager()
{
}

////////////////////////////////////////////////////////////////////////////////
ImGuiManager::~ImGuiManager()
{
	ImGui_ImplSDLRenderer2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

////////////////////////////////////////////////////////////////////////////////
ImGuiManager& ImGuiManager::Instance()
{
	static ImGuiManager instance;
	return instance;
}

////////////////////////////////////////////////////////////////////////////////
bool ImGuiManager::Init(const ImGuiManagerConfig& cfg)
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();

	static const ImWchar ranges[] = { 0x0400, 0x04FF, 0 };

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigDockingWithShift = true;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	io.Fonts->AddFontFromFileTTF("../../Assets/Fonts/Arial.ttf", 20.0f, NULL, ranges);
	io.FontDefault = io.Fonts->Fonts[0];

	// Setup Dear ImGui style
	switch (cfg.ImGuiStyle)
	{
	case EImGuiStyle::Dark:
		ImGui::StyleColorsDark();
		break;

	case EImGuiStyle::Classic:
		ImGui::StyleColorsClassic();
		break;

	case EImGuiStyle::Light:
		ImGui::StyleColorsLight();
		break;

	default:
		break;
	}

	// Setup Platform/Renderer backends
	auto sdlWindow = DrawManager::Instance().GetWindow().GetSDLWindow();
	auto sdlRenderer = DrawManager::Instance().GetRenderer().GetSDLRenderer();
	ImGui_ImplSDL2_InitForSDLRenderer(sdlWindow, sdlRenderer);
	ImGui_ImplSDLRenderer2_Init(sdlRenderer);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
void ImGuiManager::Deinit()
{
	// Cleanup
}

////////////////////////////////////////////////////////////////////////////////
void ImGuiManager::HandleEvent(const InputEvent& e)
{
	ImGui_ImplSDL2_ProcessEvent(e.GetBaseObject());
}

////////////////////////////////////////////////////////////////////////////////
void ImGuiManager::Update(int32_t dt)
{
}

////////////////////////////////////////////////////////////////////////////////
void ImGuiManager::Draw() const
{
	// Start the Dear ImGui frame
	ImGui_ImplSDLRenderer2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	// Custom code goes here
	//DrawInternal();
	RenderMassageLoyaltyUI();

	// Rendering
	ImGui::Render();
	auto sdlRenderer = DrawManager::Instance().GetRenderer().GetSDLRenderer();
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), sdlRenderer);
}

////////////////////////////////////////////////////////////////////////////////
void ImGuiManager::DrawInternal() const
{
	ImGui::Begin("Hello World!");

	ImGui::Text("Hello there!");
	ImGui::Button("Click me!");

	ImGui::End();
}

void ImGuiManager::RenderMassageLoyaltyUI() const
{
	ImGui::DockSpaceOverViewport();
	ImGui::Begin("Централен панел"); // целият изглед

	if (ImGui::BeginTabBar("ГлавноМеню", ImGuiTabBarFlags_None))
	{
		if (ImGui::BeginTabItem("Начало"))
		{
			RenderMainMenu();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Служители"))
		{
			RenderEmployeesDB();
			ImGui::EndTabItem();
		}
		
		if (ImGui::BeginTabItem("Клиенти"))
		{
			RenderClientsDB();
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Масажи"))
		{
			RenderMassagesDB();
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}

	ImGui::End();
}

void ImGuiManager::RenderMainMenu() const
{
	// === Sekciya: Skanirane / vavezhdane na klient ===
	ImGui::Text("Сканирай карта или въведи клиентски код:");
	static char clientCode[64] = "";
	ImGui::InputText("##Клиентски код", clientCode, IM_ARRAYSIZE(clientCode));
	ImGui::SameLine();
	if (ImGui::Button("Зареди клиент"))
	{
		// zarezhdane na klient (fiktivno)
	}

	ImGui::NewLine();
	ImGui::Separator();
	ImGui::NewLine();

	// === Sekciya: Danni za klienta ===
	ImGui::Text("Име: %s", "Пенка Иванова");
	ImGui::Text("Клиент от: %s", "15.03.2023");
	ImGui::Text("Брой посещения: %d", 12);
	ImGui::Text("Остават до бонус: %d", 3);

	ImGui::NewLine();
	ImGui::Separator();
	ImGui::NewLine();

	// === Sekciya: Dobavyane na masazh ===
	ImGui::Text("Добави нов масаж:");
	static int selectedMassage = 0;
	const char* massages[] = { "Класически", "Шиацу", "Арома", "Спортен" };
	ImGui::Combo("Вид масаж", &selectedMassage, massages, IM_ARRAYSIZE(massages));

	static float price = 50.0f;
	ImGui::InputFloat("Цена (лв.)", &price);

	static int selectedMasseur = 0;
	const char* masseurs[] = { "Гошо", "Пенка", "Марияна" };
	ImGui::Combo("Масажист", &selectedMasseur, masseurs, IM_ARRAYSIZE(masseurs));

	if (ImGui::Button("Запиши масажа")) {
		// zapisvane (fiktivno)
	}

	ImGui::NewLine();
	ImGui::Separator();
	ImGui::NewLine();

	// === Sekciya: Istoriya na masazhi ===
	ImGui::Text("История на последните масажи:");
	if (ImGui::BeginTable("История", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
	{
		ImGui::TableSetupColumn("Дата");
		ImGui::TableSetupColumn("Услуга");
		ImGui::TableSetupColumn("Цена");
		ImGui::TableSetupColumn("Масажист");
		ImGui::TableHeadersRow();

		for (int i = 0; i < 3; ++i)
		{
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0); ImGui::Text("25.06.2025");
			ImGui::TableSetColumnIndex(1); ImGui::Text("Арома");
			ImGui::TableSetColumnIndex(2); ImGui::Text("50 лв.");
			ImGui::TableSetColumnIndex(3); ImGui::Text("Пенка");
		}

		ImGui::EndTable();
	}
}

void ImGuiManager::RenderEmployeesDB() const
{
	if (ImGui::BeginTable("Служители", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
	{
		ImGui::TableSetupColumn("ID");
		ImGui::TableSetupColumn("Име");
		ImGui::TableSetupColumn("Масажист");
		ImGui::TableSetupColumn("Статус");
		ImGui::TableHeadersRow();

		ImGui::TableNextRow();
		ImGui::TableSetColumnIndex(0); ImGui::Text("01");
		ImGui::TableSetColumnIndex(1); ImGui::Text("Диляна");
		ImGui::TableSetColumnIndex(2); ImGui::Text("Админ");
		ImGui::TableSetColumnIndex(3); ImGui::Text("Активен");

		ImGui::TableNextRow();
		ImGui::TableSetColumnIndex(0); ImGui::Text("02");
		ImGui::TableSetColumnIndex(1); ImGui::Text("Мария");
		ImGui::TableSetColumnIndex(2); ImGui::Text("Масажист");
		ImGui::TableSetColumnIndex(3); ImGui::Text("Активен");

		ImGui::TableNextRow();
		ImGui::TableSetColumnIndex(0); ImGui::Text("03");
		ImGui::TableSetColumnIndex(1); ImGui::Text("Дамян");
		ImGui::TableSetColumnIndex(2); ImGui::Text("ИТ");
		ImGui::TableSetColumnIndex(3); ImGui::Text("Неактивен");

		ImGui::EndTable();
	}
}

void ImGuiManager::RenderClientsDB() const
{
	if (ImGui::BeginTable("Клиенти", 5, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
	{
		ImGui::TableSetupColumn("ID");
		ImGui::TableSetupColumn("E-mail");
		ImGui::TableSetupColumn("Име");
		ImGui::TableSetupColumn("Пол");
		ImGui::TableSetupColumn("Клиент от");
		ImGui::TableHeadersRow();

		for (int i = 0; i < 3; ++i)
		{
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0); ImGui::Text("12345");
			ImGui::TableSetColumnIndex(1); ImGui::Text("pesho@abv.bg");
			ImGui::TableSetColumnIndex(2); ImGui::Text("Пешо");
			ImGui::TableSetColumnIndex(3); ImGui::Text("Мъж");
			ImGui::TableSetColumnIndex(4); ImGui::Text("1.08.1932");
		}

		ImGui::EndTable();
	}
}

struct Client
{
	std::string name;
	int visits;
	float discount;
};

std::vector<Client> clients =
{
	{ "Пешо", 3, 0.0f },
	{ "Гошо", 10, 15.0f }
};

bool isAdmin = true;
std::vector<Client> editedClients = clients; // временен буфер

void ImGuiManager::RenderMassagesDB() const
{
	if (ImGui::Button("Нов"))
	{
		editedClients.emplace_back();
	}
	ImGui::SameLine();
	if (ImGui::Button("Редактиране"))
	{
		isAdmin = !isAdmin;
	}
	ImGui::SameLine();
	if (ImGui::Button("Запази промените")) {
		clients = editedClients; // прилага промените
		// Тук вече можеш да извикаш SaveCSV() или SaveJSON()
	}
	ImGui::NewLine();

	if (ImGui::BeginTable("ClientsTable", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
	{
		ImGui::TableSetupColumn("Име");
		ImGui::TableSetupColumn("Посещения");
		ImGui::TableSetupColumn("Отстъпка");
		ImGui::TableSetupColumn("Действия");
		ImGui::TableHeadersRow();

		for (size_t i = 0; i < editedClients.size(); ++i)
		{
			Client& client = editedClients[i];

			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);

			if (isAdmin)
			{
				static char nameBuf[128];
				snprintf(nameBuf, sizeof(nameBuf), "%s", client.name.c_str());
				if (ImGui::InputText(("##Name" + std::to_string(i)).c_str(), nameBuf, sizeof(nameBuf)))
					client.name = nameBuf;
			}
			else
			{
				ImGui::Text("%s", client.name.c_str());
			}

			ImGui::TableSetColumnIndex(1);
			if (isAdmin)
				ImGui::InputInt(("##Visits" + std::to_string(i)).c_str(), &client.visits);
			else
				ImGui::Text("%d", client.visits);

			ImGui::TableSetColumnIndex(2);
			if (isAdmin)
				ImGui::InputFloat(("##Discount" + std::to_string(i)).c_str(), &client.discount);
			else
				ImGui::Text("%.1f%%", client.discount);

			ImGui::TableSetColumnIndex(3);
			if (isAdmin && ImGui::Button(("Премахни##" + std::to_string(i)).c_str()))
			{
				editedClients.erase(editedClients.begin() + i);
				--i;
			}
		}

		ImGui::EndTable();
	}
}