// Corresponding header
#include "managers/DrawManager.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "sdl_utils/Window.h"
#include "sdl_utils/Renderer.h"

DrawManager* DrawManager::m_DrawManager = nullptr;

// =============================================================================
DrawManager::DrawManager()
	: m_Window(nullptr)
	, m_Renderer(nullptr)
{
}

// =============================================================================
DrawManager::~DrawManager()
{
	Deinit();
}

// =============================================================================
DrawManager* DrawManager::Get()
{
	if (!m_DrawManager)
	{
		m_DrawManager = new DrawManager;
	}

	return m_DrawManager;
}

// =============================================================================
bool DrawManager::Init()
{
	m_Window = new Window;
	AssertReturnIf(!m_Window, false);

	m_Renderer = new Renderer;
	AssertReturnIf(!m_Renderer, false);

	AssertReturnIf(!m_Window->Init(), false);
	AssertReturnIf(!m_Renderer->Init(m_Window->GetInstance(), Colors::VeryLightGrey), false);

	return true;
}

// =============================================================================
void DrawManager::Deinit()
{
	m_Renderer->Deinit();
	m_Window->Deinit();
}

// =============================================================================
void DrawManager::HandleEvent(const InputEvent& e)
{
}

// =============================================================================
void DrawManager::Update(int32_t dt)
{
	m_Renderer->Update();
}

// =============================================================================
void DrawManager::Draw() const
{
	m_Renderer->Draw();
}

// =============================================================================
Window* DrawManager::GetWindow() const
{
	return m_Window;
}

// =============================================================================
Renderer* DrawManager::GetRenderer() const
{
	return m_Renderer;
}
