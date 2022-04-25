#include "MouseKey.hpp"

bool MouseKey::is(MouseKey key) const
{
	return (key.key_ == key_);
}

const char* MouseKey::name() const
{
	switch (key_)
	{
	case Left:
		return "Left Mouse Button";
	case Right:
		return "Right Mouse Button";
	case Middle:
		return "Middle Mouse Button";
	case X1:
		return "X1 Mouse Button";
	case X2:
		return "X2 Mouse Button";
	}

	return "Unknown Mouse Button";
}

MouseKey::MouseKey(int key) : key_(key)
{
}
