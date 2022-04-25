#include "KeyState.hpp"

bool KeyState::toggled() const
{
	return (state_ & Toggle);
}

bool KeyState::pressed() const
{
	return (state_ & Press);;
}

bool KeyState::released() const
{
	return (state_ & Release);
}

bool KeyState::untoggled() const
{
	return (state_ & Untoggle);
}

bool KeyState::repeated() const
{
	return (state_ & Repeat);
}

KeyState::KeyState(int state) : state_(state)
{
}