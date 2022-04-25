#include "MouseKeyState.hpp"

bool MouseKeyState::pressed() const
{
	return (state_ == true);
}

bool MouseKeyState::released() const
{
	return (state_ == false);
}

MouseKeyState::MouseKeyState(bool state) : state_(state)
{
}
