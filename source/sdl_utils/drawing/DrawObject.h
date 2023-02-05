#ifndef SDL_UTILS_DRAWING_DRAWOBJECT_H_
#define SDL_UTILS_DRAWING_DRAWOBJECT_H_

// C/C++ system includes
#include <cstdint>

// Third-party includes

// Own includes
#include "utils/geometry/Point.h"
#include "utils/geometry/Rectangle.h"

// Forward declarations
struct SDL_Texture;

inline constexpr int32_t INVALID_ID = -1;
inline constexpr int32_t ZERO_OPACITY = 0;
inline constexpr int32_t FULL_OPACITY = 255;
inline constexpr int32_t ZERO_ROTATION = 0;
inline constexpr int32_t FULL_ROTATION = 360;

enum class ObjectType
{
	IMAGE = 0,
	TEXT = 1,
	Undefined = -1
};

enum class BlendMode : uint8_t
{
	NONE = 0,
	BLEND = 1,
	ADD = 2,
	MOD = 4
};

enum class FlipMode : uint8_t
{
	NONE = 0,
	HORIZONTAL = 1,
	VERTICAL = 2,
	HORIZONTAL_AND_VERTICAL = 3
};

struct DrawObject
{
	DrawObject();
	virtual ~DrawObject();

	void				Deinit();
	void				Reset();

	// Getters
	Point				GetPos() const;
	int32_t				GetWidth() const;
	int32_t				GetHeight() const;
	Rectangle			GetFrameRect() const;
	int32_t				GetOpacity() const;
	int32_t				GetRotationAngle() const;
	Point				GetRotationCenter() const;
	ObjectType			GetType();
	BlendMode			GetBlendMode();
	FlipMode			GetFlipMode();

	// Setters
	void				SetPos(int32_t x, int32_t y);
	void				SetPos(const Point& pos);
	void				SetWidth(int32_t width);
	void				SetHeight(int32_t height);
	void				SetFrameRect(Rectangle rect);
	void				SetOpacity(int32_t opacity);
	void				SetRotationAngle(int32_t rotationAngle);
	void				SetRotationCenter(Point rotationCenter);
	void				SetType(ObjectType type);
	void				SetBlendMode(BlendMode mode);
	void				SetFlipMode(FlipMode mode);

	// Others
	void				MoveUp(int32_t delta);
	void				MoveDown(int32_t delta);
	void				MoveLeft(int32_t delta);
	void				MoveRight(int32_t delta);

	void				ChangeWidthBy(int32_t delta);
	void				ChangeHeightBy(int32_t delta);
	void				Resize(int32_t width, int32_t height);
	void				Resize(int32_t percentage);

	void				ChangeOpacityBy(int32_t delta);
	void				SetZeroOpacity();
	void				SetMaxOpacity();
	void				Rotate(int32_t delta);

	void				Show();
	void				Hide();

	bool				GetIsVisible() const;
	bool				ContainsPoint(const Point& point) const;

protected:
	Point				m_Pos = Point::Undefined;
	int32_t				m_Width = 0;
	int32_t				m_Height = 0;
	int32_t				m_StandardWidth = 0;
	int32_t				m_StandardHeight = 0;

	Rectangle			m_FrameRect = Rectangle::Zero;

	int32_t				m_Opacity = FULL_OPACITY;
	int32_t				m_RotationAngle = ZERO_ROTATION;
	Point				m_RotationCenter = Point::Undefined;

	ObjectType			m_Type = ObjectType::Undefined;
	BlendMode			m_BlendMode = BlendMode::BLEND;
	FlipMode			m_FlipMode = FlipMode::NONE;

	bool				m_IsVisible = true;

	SDL_Texture*		m_Texture = nullptr;
};

#endif // !SDL_UTILS_DRAWING_DRAWOBJECT_H_