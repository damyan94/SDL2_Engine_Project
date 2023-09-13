#ifndef Camera_GAME_CAMERA_H_
#define Camera_GAME_CAMERA_H_

#include "app/Defines.h"
#include "sdl_utils/input/InputEvent.h"

class Camera
{
private:
	struct CameraData
	{
		int32_t				m_PosOffset				= 0;
		int32_t				m_MinPosX				= 0;
		int32_t				m_MinPosY				= 0;
		int32_t				m_MaxPosX				= 0;
		int32_t				m_MaxPosY				= 0;
		int32_t				m_MinZoom				= 0;
		int32_t				m_MaxZoom				= 0;
	};
	
	struct KeyboardScrollData
	{
		int32_t				m_Vx					= 0;
		int32_t				m_Vy					= 0;
		int32_t				m_ScrollSpeed			= 0;
	};
	
	struct MouseScrollData
	{
		int32_t				m_Vx					= 0;
		int32_t				m_Vy					= 0;
		int32_t				m_ScrollSpeed			= 0;
		int32_t				m_ScrollFieldSize		= 0;
	};
	
	struct ZoomData
	{
		int32_t				m_Zoom					= 0;
		int32_t				m_ZoomSpeed				= 0;
	};

public:
	Camera();
	~Camera();

	Camera(const Camera& other) = delete;
	Camera(Camera&& other) = delete;

	Camera& operator=(const Camera& other) = delete;
	Camera& operator=(Camera&& other) = delete;

	bool				Init();
	void				Deinit();
	void				HandleEvent(const InputEvent& e);
	void				Update(int32_t dt);

	void				Reset();

	Point				GetPos() const;
	Rectangle			GetPosRect() const;
	int32_t				GetZoom() const;

	bool				HasCameraChanged() const;

private:
	void				HandleKeyboardScrolling(const InputEvent& e);
	void				HandleMouseScrolling(const InputEvent& e);
	void				HandleZooming(const InputEvent& e);

	void				UpdateVelocityAndPosition(int32_t dt);
	void				CheckBoundsAndLimitMovement();

private:
	Point				m_Pos;
	int32_t				m_Width;
	int32_t				m_Height;
	int32_t				m_Vx;
	int32_t				m_Vy;

	CameraData			m_CameraData;
	KeyboardScrollData	m_KeyboardScrollData;
	MouseScrollData		m_MouseScrollData;
	ZoomData			m_ZoomData;

	bool				m_CameraChanged;
};

#endif // !Camera_GAME_CAMERA_H_