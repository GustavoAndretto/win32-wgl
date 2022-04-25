#pragma once

class KeyMods
{
public:
	enum mods_t {
		LShift = 0x01, // Left Shift
		RShift = 0x02, // Right Shift
		LControl = 0x04, // Left Control
		RControl = 0x08, // Right Control
		LMenu = 0x10, // Left Alt
		RMenu = 0x20, // Right Alt
		LSuper = 0x40, // Left Super
		RSuper = 0x80  // Right Super
	};

	operator int& () { return mods_; }

	KeyMods(int mods);
private:
	int mods_;
};
