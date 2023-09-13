#ifndef SDL_UTILS_INPUT_EVENTDEFINES_H_
#define SDL_UTILS_INPUT_EVENTDEFINES_H_

enum class EEventType
{
	Unknown						= -1
	, FirstEvent				= 0
	
	// Application events
	, Quit						= 256 // 0x100
	, App_Terminating			= 257       
	, App_LowMemory				= 258
	, App_WillEnterBackground	= 259                           
	, App_DidEnterBackGround	= 260
	, App_WillEnterForeground	= 261
	, App_DidEnterForeground	= 262
	, LocaleChanged				= 263
	
	// Display events
	, DisplayEvent				= 336 // 0x150
	
	// Window events
	, WindowEvent				= 512 // 0x200
	, SysWMEvent				= 513
	
	// Keyboard events
	, KeyboardPress				= 768 // 0x300
	, KeyboardRelease			= 769
	, TextEditing				= 770
	, TextInput					= 771
	, KeyMapChanged				= 772
	, TextEditingExt			= 773
	
	// Mouse events
	, MouseMotion				= 1024 // 0x400
	, MouseButtonDown			= 1025
	, MouseButtonUp				= 1026
	, MouseWheel				= 1027
	, MouseHoldMotion			= 1028
	
	// Touch events
	, FingerDown				= 1792 // 0x700
	, FingerUp					= 1793
	, FingerMotion				= 1794
	
	// Gesture events
	, DollarGesture				= 2048 // 0x800
	, DollarRecord				= 2049
	, MultiGesture				= 2050
	
	// Audio hotplug events
	, AudioDeviceAdded			= 4352 // 0x1100
	, AudioDeviceRemoved		= 4353
	
	// Sensor events
	, SensorUpdate				= 4608 // 0x1200
	
	// User events
	, UserEvent					= 32768 // 0x8000
};

enum class EKeyboardKey
{
	Unknown				= 0

	, Return			= '\r'
	, Escape			= '\x1B'
	, Backspace			= '\b'
	, Tab				= '\t'
	, Space				= ' '
	, Exclaim			= '!'
	, QuoteDbl			= '"'
	, Hash				= '#'
	, Dollar			= '$'
	, Percent			= '%'
	, Ampersand			= '&'
	, Quote				= '\''
	, LeftParen			= '('
	, RightParen		= ')'
	, Asterisk			= '*'
	, Plus				= '+'
	, Comma				= ','
	, Minus				= '-'
	, Period			= '.'
	, Slash				= '/'
	, Key0				= '0'
	, Key1				= '1'
	, Key2				= '2'
	, Key3				= '3'
	, Key4				= '4'
	, Key5				= '5'
	, Key6				= '6'
	, Key7				= '7'
	, Key8				= '8'
	, Key9				= '9'
	, Colon				= ':'
	, Semicolon			= ';'
	, Less				= '<'
	, Equals			= '='
	, Greater			= '>'
	, Question			= '?'
	, At				= '@'
	
	, LeftBracket		= '['
	, BackSlash			= '\\'
	, RightBracket		= ']'
	, Caret				= '^'
	, UnderScore		= '_'
	, BackQuote			= '`'
	, A					= 'a'
	, B					= 'b'
	, C					= 'c'
	, D					= 'd'
	, E					= 'e'
	, F					= 'f'
	, G					= 'g'
	, H					= 'h'
	, I					= 'i'
	, J					= 'j'
	, K					= 'k'
	, L					= 'l'
	, M					= 'm'
	, N					= 'n'
	, O					= 'o'
	, P					= 'p'
	, Q					= 'q'
	, R					= 'r'
	, S					= 's'
	, T					= 't'
	, U					= 'u'
	, V					= 'v'
	, W					= 'w'
	, X					= 'x'
	, Y					= 'y'
	, Z					= 'z'
	
	, Delete			= 127
	
	, F1				= 1073741882
	, F2				= 1073741883
	, F3				= 1073741884
	, F4				= 1073741885
	, F5				= 1073741886
	, F6				= 1073741887
	, F7				= 1073741888
	, F8				= 1073741889
	, F9				= 1073741890
	, F10				= 1073741891
	, F11				= 1073741892
	, F12				= 1073741893
	
	, PrintScreen		= 1073741894
	, ScrollLock		= 1073741895
	, Pause				= 1073741896
	, Insert			= 1073741897
	, Home				= 1073741898
	, PageUp			= 1073741899
	, End				= 1073741901
	, PageDown			= 1073741902
	
	, Right				= 1073741903
	, Left				= 1073741904
	, Down				= 1073741905
	, Up				= 1073741906
	
	, Numpad_Numlock	= 1073741907
	, Numpad_Divide		= 1073741908
	, Numpad_Multiply	= 1073741909
	, Numpad_Minus		= 1073741910
	, Numpad_Plus		= 1073741911
	, Numpad_Enter		= 1073741912
	
	, Numpad_1			= 1073741913
	, Numpad_2			= 1073741914
	, Numpad_3			= 1073741915
	, Numpad_4			= 1073741916
	, Numpad_5			= 1073741917
	, Numpad_6			= 1073741918
	, Numpad_7			= 1073741919
	, Numpad_8			= 1073741920
	, Numpad_9			= 1073741921
	, Numpad_0			= 1073741922
	, Numpad_Period		= 1073741923
	
	, LeftCtrl			= 1073742048
};

enum class EKeymod
{
	None				= 0
	, LShift			= 1
	, RShift			= 2
	, LCtrl				= 64
	, RCtrl				= 128
	, LAlt				= 256
	, RAlt				= 512
	, LGui				= 1024
	, RGui				= 2048
	, Num				= 4096
	, Caps				= 8192
	, Mode				= 16384
	, Scroll			= 32768
	
	, Ctrl				= LCtrl | RCtrl
	, Shift				= LShift | RShift
	, Alt				= LAlt | RAlt
	, Gui				= LGui | RGui
	
	, Reserved			= Scroll
};

enum class EScancode
{
	SCANCODE_UNKNOWN = 0,

	SCANCODE_A = 4,
	SCANCODE_B = 5,
	SCANCODE_C = 6,
	SCANCODE_D = 7,
	SCANCODE_E = 8,
	SCANCODE_F = 9,
	SCANCODE_G = 10,
	SCANCODE_H = 11,
	SCANCODE_I = 12,
	SCANCODE_J = 13,
	SCANCODE_K = 14,
	SCANCODE_L = 15,
	SCANCODE_M = 16,
	SCANCODE_N = 17,
	SCANCODE_O = 18,
	SCANCODE_P = 19,
	SCANCODE_Q = 20,
	SCANCODE_R = 21,
	SCANCODE_S = 22,
	SCANCODE_T = 23,
	SCANCODE_U = 24,
	SCANCODE_V = 25,
	SCANCODE_W = 26,
	SCANCODE_X = 27,
	SCANCODE_Y = 28,
	SCANCODE_Z = 29,

	SCANCODE_1 = 30,
	SCANCODE_2 = 31,
	SCANCODE_3 = 32,
	SCANCODE_4 = 33,
	SCANCODE_5 = 34,
	SCANCODE_6 = 35,
	SCANCODE_7 = 36,
	SCANCODE_8 = 37,
	SCANCODE_9 = 38,
	SCANCODE_0 = 39,

	SCANCODE_RETURN = 40,
	SCANCODE_ESCAPE = 41,
	SCANCODE_BACKSPACE = 42,
	SCANCODE_TAB = 43,
	SCANCODE_SPACE = 44,

	SCANCODE_MINUS = 45,
	SCANCODE_EQUALS = 46,
	SCANCODE_LEFTBRACKET = 47,
	SCANCODE_RIGHTBRACKET = 48,
	SCANCODE_BACKSLASH = 49,
	SCANCODE_NONUSHASH = 50,
	SCANCODE_SEMICOLON = 51,
	SCANCODE_APOSTROPHE = 52,
	SCANCODE_GRAVE = 53,
	SCANCODE_COMMA = 54,
	SCANCODE_PERIOD = 55,
	SCANCODE_SLASH = 56,

	SCANCODE_CAPSLOCK = 57,

	SCANCODE_F1 = 58,
	SCANCODE_F2 = 59,
	SCANCODE_F3 = 60,
	SCANCODE_F4 = 61,
	SCANCODE_F5 = 62,
	SCANCODE_F6 = 63,
	SCANCODE_F7 = 64,
	SCANCODE_F8 = 65,
	SCANCODE_F9 = 66,
	SCANCODE_F10 = 67,
	SCANCODE_F11 = 68,
	SCANCODE_F12 = 69,

	SCANCODE_PRINTSCREEN = 70,
	SCANCODE_SCROLLLOCK = 71,
	SCANCODE_PAUSE = 72,
	SCANCODE_INSERT = 73,
	SCANCODE_HOME = 74,
	SCANCODE_PAGEUP = 75,
	SCANCODE_DELETE = 76,
	SCANCODE_END = 77,
	SCANCODE_PAGEDOWN = 78,

	SCANCODE_RIGHT = 79,
	SCANCODE_LEFT = 80,
	SCANCODE_DOWN = 81,
	SCANCODE_UP = 82,

	SCANCODE_NUMLOCKCLEAR = 83,
	SCANCODE_KP_DIVIDE = 84,
	SCANCODE_KP_MULTIPLY = 85,
	SCANCODE_KP_MINUS = 86,
	SCANCODE_KP_PLUS = 87,
	SCANCODE_KP_ENTER = 88,
	SCANCODE_KP_1 = 89,
	SCANCODE_KP_2 = 90,
	SCANCODE_KP_3 = 91,
	SCANCODE_KP_4 = 92,
	SCANCODE_KP_5 = 93,
	SCANCODE_KP_6 = 94,
	SCANCODE_KP_7 = 95,
	SCANCODE_KP_8 = 96,
	SCANCODE_KP_9 = 97,
	SCANCODE_KP_0 = 98,
	SCANCODE_KP_PERIOD = 99,

	SCANCODE_NONUSBACKSLASH = 100,
	SCANCODE_KP_EQUALS = 103,
	SCANCODE_KP_COMMA = 133,
	SCANCODE_KP_EQUALSAS400 = 134,

	SCANCODE_KP_00 = 176,
	SCANCODE_KP_000 = 177,
	SCANCODE_THOUSANDSSEPARATOR = 178,
	SCANCODE_DECIMALSEPARATOR = 179,
	SCANCODE_CURRENCYUNIT = 180,
	SCANCODE_CURRENCYSUBUNIT = 181,
	SCANCODE_KP_LEFTPAREN = 182,
	SCANCODE_KP_RIGHTPAREN = 183,
	SCANCODE_KP_LEFTBRACE = 184,
	SCANCODE_KP_RIGHTBRACE = 185,
	SCANCODE_KP_TAB = 186,
	SCANCODE_KP_BACKSPACE = 187,
	SCANCODE_KP_A = 188,
	SCANCODE_KP_B = 189,
	SCANCODE_KP_C = 190,
	SCANCODE_KP_D = 191,
	SCANCODE_KP_E = 192,
	SCANCODE_KP_F = 193,
	SCANCODE_KP_XOR = 194,
	SCANCODE_KP_POWER = 195,
	SCANCODE_KP_PERCENT = 196,
	SCANCODE_KP_LESS = 197,
	SCANCODE_KP_GREATER = 198,
	SCANCODE_KP_AMPERSAND = 199,
	SCANCODE_KP_DBLAMPERSAND = 200,
	SCANCODE_KP_VERTICALBAR = 201,
	SCANCODE_KP_DBLVERTICALBAR = 202,
	SCANCODE_KP_COLON = 203,
	SCANCODE_KP_HASH = 204,
	SCANCODE_KP_SPACE = 205,
	SCANCODE_KP_AT = 206,
	SCANCODE_KP_EXCLAM = 207,
	SCANCODE_KP_MEMSTORE = 208,
	SCANCODE_KP_MEMRECALL = 209,
	SCANCODE_KP_MEMCLEAR = 210,
	SCANCODE_KP_MEMADD = 211,
	SCANCODE_KP_MEMSUBTRACT = 212,
	SCANCODE_KP_MEMMULTIPLY = 213,
	SCANCODE_KP_MEMDIVIDE = 214,
	SCANCODE_KP_PLUSMINUS = 215,
	SCANCODE_KP_CLEAR = 216,
	SCANCODE_KP_CLEARENTRY = 217,
	SCANCODE_KP_BINARY = 218,
	SCANCODE_KP_OCTAL = 219,
	SCANCODE_KP_DECIMAL = 220,
	SCANCODE_KP_HEXADECIMAL = 221,

	SCANCODE_LCTRL = 224,
	SCANCODE_LSHIFT = 225,
	SCANCODE_LALT = 226,
	SCANCODE_LGUI = 227,
	SCANCODE_RCTRL = 228,
	SCANCODE_RSHIFT = 229,
	SCANCODE_RALT = 230,
	SCANCODE_RGUI = 231,

	SCANCODE_MODE = 257,

	SCANCODE_AUDIONEXT = 258,
	SCANCODE_AUDIOPREV = 259,
	SCANCODE_AUDIOSTOP = 260,
	SCANCODE_AUDIOPLAY = 261,
	SCANCODE_AUDIOMUTE = 262,
	SCANCODE_MEDIASELECT = 263,
	SCANCODE_WWW = 264,
	SCANCODE_MAIL = 265,
	SCANCODE_CALCULATOR = 266,
	SCANCODE_COMPUTER = 267,
	SCANCODE_AC_SEARCH = 268,
	SCANCODE_AC_HOME = 269,
	SCANCODE_AC_BACK = 270,
	SCANCODE_AC_FORWARD = 271,
	SCANCODE_AC_STOP = 272,
	SCANCODE_AC_REFRESH = 273,
	SCANCODE_AC_BOOKMARKS = 274,

	SCANCODE_BRIGHTNESSDOWN = 275,
	SCANCODE_BRIGHTNESSUP = 276,
	SCANCODE_DISPLAYSWITCH = 277,
	SCANCODE_KBDILLUMTOGGLE = 278,
	SCANCODE_KBDILLUMDOWN = 279,
	SCANCODE_KBDILLUMUP = 280,
	SCANCODE_EJECT = 281,
	SCANCODE_SLEEP = 282,

	SCANCODE_APP1 = 283,
	SCANCODE_APP2 = 284,

	SCANCODE_AUDIOREWIND = 285,
	SCANCODE_AUDIOFASTFORWARD = 286,

	NUM_SCANCODES = 512 
};

enum class EMouseKey
{
	Unknown				= 0
	, Left				= 1
	, Middle			= 2
	, Right				= 3
};

enum class EMouseWheel
{
	UpDownTreshold		= 0
};

#endif // !SDL_UTILS_INPUT_EVENTDEFINES_H_