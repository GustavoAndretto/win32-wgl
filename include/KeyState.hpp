#pragma once

class KeyState
{
public:
	enum state_t {
		Press = 0x01, // Key press
		Release = 0x02, // Key release
		Toggle = 0x04, // Key toggle
		Untoggle = 0x08, // Key untoggle
		Repeat = 0x10  // Key repeat
	};

	bool toggled() const;

	bool pressed() const;

	bool released() const;

	bool untoggled() const;

	bool repeated() const;

	operator int& () { return state_; }

	KeyState(int state);
private:

	int state_;
};
