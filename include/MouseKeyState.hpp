#pragma once

class MouseKeyState
{
public:
	enum state_t {
		Release,
		Press
	};

	bool pressed() const;
	bool released() const;

	operator bool() { return state_; }

	MouseKeyState(bool state);
private:

	bool state_;
};
