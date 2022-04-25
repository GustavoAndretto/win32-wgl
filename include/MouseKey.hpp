#pragma once

class MouseKey
{
public:
	enum key_t {
		Left = 0x01, // Left mouse button
		Right = 0x02, // Right mouse button
		Middle = 0x03, // Middle mouse button(three - button mouse)
		X1 = 0x04, // X1 mouse button
		X2 = 0x05, // X2 mouse button
		OEM1 = 0x06, // OEM
		OEM2 = 0x07, // OEM
		OEM3 = 0x08, // OEM
		OEM4 = 0x09, // OEM
		OEM5 = 0x10, // OEM
	};

	bool is(MouseKey key) const;

	const char* name() const;

	operator int& () { return key_; }

	MouseKey(int key);

private:

	int key_;
};
