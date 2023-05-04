// Corresponding header
#include "app/game/Camera.h"

// C/C++ system includes

// Third-party includes

// Own includes
#include "utils/input_output/Log.h"
#include "utils/others/CodeReadability.h"
#include "utils/string/String.h"
#include "managers/ManagersHelpers.h"
#include "components/drawing/DynamicText.h"

// =============================================================================
Camera::Camera()
	: m_Pos(Point::Undefined)
	, m_Width(0)
	, m_Height(0)
	, m_Vx(0)
	, m_Vy(0)
	, m_CameraChanged(true)
{
}

// =============================================================================
Camera::~Camera()
{
}

// =============================================================================
bool Camera::Init()
{
	auto windowRect = Helpers::GetWindowRect();

	m_Pos = Point::Zero;

	m_CameraData.m_PosOffset = 100;
	m_CameraData.m_MinPosX = -m_CameraData.m_PosOffset;
	m_CameraData.m_MinPosY = -m_CameraData.m_PosOffset;
	m_CameraData.m_MaxPosX = windowRect.w + m_CameraData.m_PosOffset;
	m_CameraData.m_MaxPosY = windowRect.h + m_CameraData.m_PosOffset;
	m_CameraData.m_MinZoom = 0;
	m_CameraData.m_MaxZoom = 100;

	m_KeyboardScrollData.m_ScrollSpeed = 4;

	m_MouseScrollData.m_ScrollSpeed = 4;
	m_MouseScrollData.m_ScrollFieldSize = 20;

	m_ZoomData.m_ZoomSpeed = 4;

	return true;
}

// =============================================================================
void Camera::Deinit()
{
}

// =============================================================================
void Camera::HandleEvent(const InputEvent& e)
{
	if (e.m_Type == EEventType::WindowEvent)
	{
		auto& windowRect = Helpers::GetWindowRect();
		m_CameraData.m_MaxPosX = windowRect.w + m_CameraData.m_PosOffset;
		m_CameraData.m_MaxPosY = windowRect.h + m_CameraData.m_PosOffset;
	}

	if (e.m_Type == EEventType::KeyboardPress ||
		e.m_Type == EEventType::KeyboardRelease)
	{
		HandleKeyboardScrolling(e);
	}

	HandleMouseScrolling(e);

	if (e.m_Type == EEventType::MouseWheel)
	{
		HandleZooming(e);
	}
}

// =============================================================================
void Camera::Update(int32_t dt)
{
	m_CameraChanged = false;

	bool hasScrollX = m_KeyboardScrollData.m_Vx != 0 || m_MouseScrollData.m_Vx != 0;
	bool hasScrollY = m_KeyboardScrollData.m_Vy != 0 || m_MouseScrollData.m_Vy != 0;
	ReturnIf(!(hasScrollX || hasScrollY), void());

	m_CameraChanged = true;

	UpdateVelocityAndPosition(dt);
	CheckBoundsAndLimitMovement();
}

// =============================================================================
void Camera::Reset()
{
	m_Pos = Point::Undefined;
	m_Vx = 0;
	m_Vy = 0;

	m_ZoomData.m_Zoom = 0;
}

// =============================================================================
Point Camera::GetPos() const
{
	return m_Pos;
}

// =============================================================================
Rectangle Camera::GetPosRect() const
{
	return { m_Pos.x, m_Pos.y, m_Width, m_Height };
}

// =============================================================================
int32_t Camera::GetZoom() const
{
	return m_ZoomData.m_Zoom;
}

// =============================================================================
bool Camera::HasCameraChanged() const
{
	return m_CameraChanged;
}

// =============================================================================
void Camera::HandleKeyboardScrolling(const InputEvent& e)
{
	//TODO maybe move keys to configuration/options
	if (e.m_Type == EEventType::KeyboardPress)
	{
		switch (e.m_Key)
		{
		case EKeyboardKey::W:
			m_KeyboardScrollData.m_Vy = -m_KeyboardScrollData.m_ScrollSpeed;
			break;

		case EKeyboardKey::A:
			m_KeyboardScrollData.m_Vx = -m_KeyboardScrollData.m_ScrollSpeed;
			break;

		case EKeyboardKey::S:
			m_KeyboardScrollData.m_Vy = m_KeyboardScrollData.m_ScrollSpeed;
			break;

		case EKeyboardKey::D:
			m_KeyboardScrollData.m_Vx = m_KeyboardScrollData.m_ScrollSpeed;
			break;

		default:
			break;
		}
	}
	else if (e.m_Type == EEventType::KeyboardRelease)
	{
		switch (e.m_Key)
		{
		case EKeyboardKey::W:
		case EKeyboardKey::S:
			m_KeyboardScrollData.m_Vy = 0;
			break;

		case EKeyboardKey::A:
		case EKeyboardKey::D:
			m_KeyboardScrollData.m_Vx = 0;
			break;

		default:
			break;
		}
	}
}

// =============================================================================
void Camera::HandleMouseScrolling(const InputEvent& e)
{
	ReturnIf(e.m_Type != EEventType::MouseMotion, void());

	if (e.m_Pos.x < m_MouseScrollData.m_ScrollFieldSize)
	{
		m_MouseScrollData.m_Vx = -m_MouseScrollData.m_ScrollSpeed;
	}
	else if (e.m_Pos.x > m_CameraData.m_MaxPosX - m_CameraData.m_PosOffset -
		m_MouseScrollData.m_ScrollFieldSize)
	{
		m_MouseScrollData.m_Vx = m_MouseScrollData.m_ScrollSpeed;
	}
	else
	{
		m_MouseScrollData.m_Vx = 0;
	}

	if (e.m_Pos.y < m_MouseScrollData.m_ScrollFieldSize)
	{
		m_MouseScrollData.m_Vy = -m_MouseScrollData.m_ScrollSpeed;
	}
	else if (e.m_Pos.y > m_CameraData.m_MaxPosY - m_CameraData.m_PosOffset
		- m_MouseScrollData.m_ScrollFieldSize)
	{
		m_MouseScrollData.m_Vy = m_MouseScrollData.m_ScrollSpeed;
	}
	else
	{
		m_MouseScrollData.m_Vy = 0;
	}
}

// =============================================================================
void Camera::HandleZooming(const InputEvent& e)
{
	ReturnIf(e.m_Type != EEventType::MouseWheel, void());

	if (e.m_Wheel > (float)EMouseWheel::UpDownTreshold)
	{
		m_ZoomData.m_Zoom += m_ZoomData.m_ZoomSpeed;
		if (m_ZoomData.m_Zoom > m_CameraData.m_MaxZoom)
		{
			m_ZoomData.m_Zoom = m_CameraData.m_MaxZoom;
		}
	}
	else
	{
		m_ZoomData.m_Zoom -= m_ZoomData.m_ZoomSpeed;
		if (m_ZoomData.m_Zoom < m_CameraData.m_MinZoom)
		{
			m_ZoomData.m_Zoom = m_CameraData.m_MinZoom;
		}
	}
}

// =============================================================================
void Camera::UpdateVelocityAndPosition(int32_t dt)
{
	m_Vx = m_KeyboardScrollData.m_Vx + m_MouseScrollData.m_Vx;
	m_Vy = m_KeyboardScrollData.m_Vy + m_MouseScrollData.m_Vy;

	m_Pos.x += m_Vx * dt / 10;
	m_Pos.y += m_Vy * dt / 10;
}

// =============================================================================
void Camera::CheckBoundsAndLimitMovement()
{
	if (m_Pos.x < m_CameraData.m_MinPosX)
	{
		m_Pos.x = m_CameraData.m_MinPosX;
	}
	else if (m_Pos.x > m_CameraData.m_MaxPosX)
	{
		m_Pos.x = m_CameraData.m_MaxPosX;
	}

	if (m_Pos.y < m_CameraData.m_MinPosY)
	{
		m_Pos.y = m_CameraData.m_MinPosY;
	}
	else if (m_Pos.y > m_CameraData.m_MaxPosY)
	{
		m_Pos.y = m_CameraData.m_MaxPosY;
	}
}