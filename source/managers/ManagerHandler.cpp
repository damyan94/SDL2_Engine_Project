// Corresponding header
#include "managers/ManagerHandler.h"
#include "managers/config/ManagerHandlerConfig.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "managers/DrawManager.h"
#include "managers/AssetManager.h"
#include "managers/TimerManager.h"
#include "managers/ImGuiManager.h"

// =============================================================================
ManagerHandler::ManagerHandler()
{
}

// =============================================================================
ManagerHandler::~ManagerHandler()
{
	SafeDelete(g_ImGuiManager);
	SafeDelete(g_TimerManager);
	SafeDelete(g_AssetManager);
	SafeDelete(g_DrawManager);
}

// =============================================================================
bool ManagerHandler::Init(const ManagerHandlerConfig& cfg)
{
	g_DrawManager = new DrawManager;
	g_AssetManager = new AssetManager;
	g_TimerManager = new TimerManager;
	g_ImGuiManager = new ImGuiManager;

	AssertReturnIf(!g_DrawManager, false, "Failed to allocate memory.");
	AssertReturnIf(!g_AssetManager, false, "Failed to allocate memory.");
	AssertReturnIf(!g_TimerManager, false, "Failed to allocate memory.");
	AssertReturnIf(!g_ImGuiManager, false, "Failed to allocate memory.");

	ReturnIf(!g_DrawManager->Init(cfg.m_DrawManagerConfig), false);
	ReturnIf(!g_AssetManager->Init(cfg.m_AssetManagerConfig), false);
	ReturnIf(!g_TimerManager->Init(cfg.m_TimerManagerConfig), false);
	ReturnIf(!g_ImGuiManager->Init(cfg.m_ImGuiManagerConfig), false);

	return true;
}

// =============================================================================
void ManagerHandler::Deinit()
{
	g_AssetManager->Deinit();
	g_DrawManager->Deinit();
	g_TimerManager->Deinit();
	g_ImGuiManager->Deinit();
}

// =============================================================================
void ManagerHandler::HandleEvent(const InputEvent& e)
{
	g_ImGuiManager->HandleEvent(e);
}

// =============================================================================
void ManagerHandler::Update(int32_t dt)
{
	g_DrawManager->ClearScreen();
	g_TimerManager->Update(dt);
}

// =============================================================================
void ManagerHandler::Draw() const
{
	g_ImGuiManager->Draw();
	g_DrawManager->FinishFrame();
}