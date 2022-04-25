#pragma once
#include <string>

class Key
{
public:
	enum key_t {
		Cancel = 0x03, // Control - break processing
		Back = 0x08, // BACKSPACE key
		Tab = 0x09, // TAB key
		Clear = 0x0C, // CLEAR key
		Return = 0x0D, // ENTER key
		Shift = 0x10, // SHIFT key
		Control = 0x11, // CTRL key
		Menu = 0x12, // ALT key
		Pause = 0x13, // PAUSE key
		Capital = 0x14, // CAPS LOCK key
		Kana = 0x15, // IME Kana mode
		Junja = 0x17, // IME Junja mode
		Final = 0x18, // IME final mode
		Kanji = 0x19, // IME Kanji mode
		Escape = 0x1B, // ESC key
		Convert = 0x1C, // IME convert
		NonConvert = 0x1D, // IME nonconvert
		Accept = 0x1E, // IME accept
		ModeChange = 0x1F, // IME mode change request
		Space = 0x20, // SPACEBAR
		Prior = 0x21, // PAGE UP key
		Next = 0x22, // PAGE DOWN key
		End = 0x23, // END key
		Home = 0x24, // HOME key
		Left = 0x25, // LEFT ARROW key
		Up = 0x26, // UP ARROW key
		Right = 0x27, // RIGHT ARROW key
		Down = 0x28, // DOWN ARROW key
		Select = 0x29, // SELECT key
		Print = 0x2A, // PRINT key
		Execute = 0x2B, // EXECUTE key
		Snapshot = 0x2C, // PRINT SCREEN key
		Insert = 0x2D, // INS key
		Delete = 0x2E, // DEL key
		Help = 0x2F, // HELP key
		Num0 = 0x30, // 0 key
		Num1 = 0x31, // 1 key
		Num2 = 0x32, // 2 key
		Num3 = 0x33, // 3 key
		Num4 = 0x34, // 4 key
		Num5 = 0x35, // 5 key
		Num6 = 0x36, // 6 key
		Num7 = 0x37, // 7 key
		Num8 = 0x38, // 8 key
		Num9 = 0x39, // 9 key
		A = 0x41, // A key
		B = 0x42, // B key
		C = 0x43, // C key
		D = 0x44, // D key
		E = 0x45, // E key
		F = 0x46, // F key
		G = 0x47, // G key
		H = 0x48, // H key
		I = 0x49, // I key
		J = 0x4A, // J key
		K = 0x4B, // K key
		L = 0x4C, // L key
		M = 0x4D, // M key
		N = 0x4E, // N key
		O = 0x4F, // O key
		P = 0x50, // P key
		Q = 0x51, // Q key
		R = 0x52, // R key
		S = 0x53, // S key
		T = 0x54, // T key
		U = 0x55, // U key
		V = 0x56, // V key
		W = 0x57, // W key
		X = 0x58, // X key
		Y = 0x59, // Y key
		Z = 0x5A, // Z key
		LSuper = 0x5B, // Left Windows key(Natural keyboard)
		RSuper = 0x5C, // Right Windows key(Natural keyboard)
		Apps = 0x5D, // Applications key(Natural keyboard)
		Sleep = 0x5F, // Computer Sleep key
		Numpad0 = 0x60, // Numeric keypad 0 key
		Numpad1 = 0x61, // Numeric keypad 1 key
		Numpad2 = 0x62, // Numeric keypad 2 key
		Numpad3 = 0x63, // Numeric keypad 3 key
		Numpad4 = 0x64, // Numeric keypad 4 key
		Numpad5 = 0x65, // Numeric keypad 5 key
		Numpad6 = 0x66, // Numeric keypad 6 key
		Numpad7 = 0x67, // Numeric keypad 7 key
		Numpad8 = 0x68, // Numeric keypad 8 key
		Numpad9 = 0x69, // Numeric keypad 9 key
		Multiply = 0x6A, // Multiply key
		Add = 0x6B, // Add key
		Separator = 0x6C, // Separator key
		Subtract = 0x6D, // Subtract key
		Decimal = 0x6E, // Decimal key
		Divide = 0x6F, // Divide key
		F1 = 0x70, // F1 key
		F2 = 0x71, // F2 key
		F3 = 0x72, // F3 key
		F4 = 0x73, // F4 key
		F5 = 0x74, // F5 key
		F6 = 0x75, // F6 key
		F7 = 0x76, // F7 key
		F8 = 0x77, // F8 key
		F9 = 0x78, // F9 key
		F10 = 0x79, // F10 key
		F11 = 0x7A, // F11 key
		F12 = 0x7B, // F12 key
		F13 = 0x7C, // F13 key
		F14 = 0x7D, // F14 key
		F15 = 0x7E, // F15 key
		F16 = 0x7F, // F16 key
		F17 = 0x80, // F17 key
		F18 = 0x81, // F18 key
		F19 = 0x82, // F19 key
		F20 = 0x83, // F20 key
		F21 = 0x84, // F21 key
		F22 = 0x85, // F22 key
		F23 = 0x86, // F23 key
		F24 = 0x87, // F24 key
		NumLock = 0x90, // NUM LOCK key
		ScrollLock = 0x91, // SCROLL LOCK key
		LShift = 0xA0, // Left SHIFT key
		RShift = 0xA1, // Right SHIFT key
		LControl = 0xA2, // Left CONTROL key
		RControl = 0xA3, // Right CONTROL key
		LMenu = 0xA4, // Left MENU key
		RMenu = 0xA5, // Right MENU key
		BrowserBack = 0xA6, // Browser Back key
		BrowserForward = 0xA7, // Browser Forward key
		BrowserRefresh = 0xA8, // Browser Refresh key
		BrowserStop = 0xA9, // Browser Stop key
		BrowserSearch = 0xAA, // Browser Search key
		BrowserFavorites = 0xAB, // Browser Favorites key
		BrowserHome = 0xAC, // Browser Start and Home key
		VolumeMute = 0xAD, // Volume Mute key
		VolumeDown = 0xAE, // Volume Down key
		VolumeUp = 0xAF, // Volume Up key
		MediaNext = 0xB0, // Next Track key
		MediaPrevious = 0xB1, // Previous Track key
		MediaStop = 0xB2, // Stop Media key
		MediaPlayPause = 0xB3, // Play / Pause Media key
		LaunchMail = 0xB4, // Start Mail key
		LaunchMedia = 0xB5, // Select Media key
		LaunchApp1 = 0xB6, // Start Application 1 key
		LaunchApp2 = 0xB7, // Start Application 2 key
		OEM_1 = 0xBA, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_PLUS = 0xBB, // For any country / region, the '+' key
		OEM_COMMA = 0xBC, // For any country / region, the ',' key
		OEM_MINUS = 0xBD, // For any country / region, the '-' key
		OEM_PERIOD = 0xBE, // For any country / region, the '.' key
		OEM_2 = 0xBF, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_3 = 0xC0, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_3B = 0xC1, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_4 = 0xDB, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_5 = 0xDC, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_6 = 0xDD, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_7 = 0xDE, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_8 = 0xDF, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_9 = 0xE0, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_10 = 0xE1, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_11 = 0xE2, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_12 = 0xE3, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_13 = 0xE4, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_14 = 0xE5, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_15 = 0xE6, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_16 = 0xE7, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_17 = 0xE8, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_18 = 0xE9, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_19 = 0xEA, // Used for miscellaneous characters; it can vary by keyboard.
		OEM_20 = 0xEB, // Used for miscellaneous characters; it can vary by keyboard.
		ATTN = 0xF6, // Attn key
		CrSel = 0xF7, // CrSel key
		ExSel = 0xF8, // ExSel key
		EREOF = 0xF9, // Erase EOF key
		Play = 0xFA, // Play key
		Zoom = 0xFB, // Zoom key
	};

	bool is(Key key) const;

	const char* name() const;

	operator int& () { return key_; }

	Key(int key);

private:
	int key_;
};