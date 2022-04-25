#include "Key.hpp"

bool Key::is(Key key) const
{
	return false;
}

const char* Key::name() const
{
	switch (key_)
	{
	case Key::Cancel:
		return "Cancel";
	case Key::Back:
		return "Backspace";
	case Key::Tab:
		return "Tabular";
	case Key::Clear:
		return "Clear";
	case Key::Return:
		return "Return";
	case Key::Shift:
		return "Shift";
	case Key::Control:
		return "Control";
	case Key::Menu:
		return "Alternate";
	case Key::Pause:
		return "Pause";
	case Key::Capital:
		return "Capital";
	case Key::Kana:
		return "IME Kana";
	case Key::Junja:
		return "IME Junja";
	case Key::Final:
		return "IME Final";
	case Key::Kanji:
		return "IME Kanji";
	case Key::Escape:
		return "Escape";
	case Key::Convert:
		return "IME Convert";
	case Key::NonConvert:
		return "IME Nonconvert";
	case Key::Accept:
		return "IME Accept";
	case Key::ModeChange:
		return "IME Modechange";
	case Key::Space:
		return "Space";
	case Key::Prior:
		return "Page Up";
	case Key::Next:
		return "Page Down";
	case Key::End:
		return "End";
	case Key::Home:
		return "Home";
	case Key::Left:
		return "Left";
	case Key::Up:
		return "Up";
	case Key::Right:
		return "Right";
	case Key::Down:
		return "Down";
	case Key::Select:
		return "Select";
	case Key::Print:
		return "Print";
	case Key::Execute:
		return "Execute";
	case Key::Snapshot:
		return "Printscreen";
	case Key::Insert:
		return "Insert";
	case Key::Delete:
		return "Delete";
	case Key::Help:
		return "Help";
	case Key::Num0:
		return "0";
	case Key::Num1:
		return "1";
	case Key::Num2:
		return "2";
	case Key::Num3:
		return "3";
	case Key::Num4:
		return "4";
	case Key::Num5:
		return "5";
	case Key::Num6:
		return "6";
	case Key::Num7:
		return "7";
	case Key::Num8:
		return "8";
	case Key::Num9:
		return "9";
	case Key::A:
		return "A";
	case Key::B:
		return "B";
	case Key::C:
		return "C";
	case Key::D:
		return "D";
	case Key::E:
		return "E";
	case Key::F:
		return "F";
	case Key::G:
		return "G";
	case Key::H:
		return "H";
	case Key::I:
		return "I";
	case Key::J:
		return "J";
	case Key::K:
		return "K";
	case Key::L:
		return "L";
	case Key::M:
		return "M";
	case Key::N:
		return "N";
	case Key::O:
		return "O";
	case Key::P:
		return "P";
	case Key::Q:
		return "Q";
	case Key::R:
		return "R";
	case Key::S:
		return "S";
	case Key::T:
		return "T";
	case Key::U:
		return "U";
	case Key::V:
		return "V";
	case Key::W:
		return "W";
	case Key::X:
		return "X";
	case Key::Y:
		return "Y";
	case Key::Z:
		return "Z";
	case Key::LSuper:
		return "Left Super";
	case Key::RSuper:
		return "Right Super";
	case Key::Apps:
		return "Applications";
	case Key::Sleep:
		return "Sleep";
	case Key::Numpad0:
		return "Num 0";
	case Key::Numpad1:
		return "Num 1";
	case Key::Numpad2:
		return "Num 2";
	case Key::Numpad3:
		return "Num 3";
	case Key::Numpad4:
		return "Num 4";
	case Key::Numpad5:
		return "Num 5";
	case Key::Numpad6:
		return "Num 6";
	case Key::Numpad7:
		return "Num 7";
	case Key::Numpad8:
		return "Num 8";
	case Key::Numpad9:
		return "Num 9";
	case Key::Multiply:
		return "Multiply";
	case Key::Add:
		return "Add";
	case Key::Separator:
		return "Separator";
	case Key::Subtract:
		return "Subtract";
	case Key::Decimal:
		return "Decimal";
	case Key::Divide:
		return "Divide";
	case Key::F1:
		return "F1";
	case Key::F2:
		return "F2";
	case Key::F3:
		return "F3";
	case Key::F4:
		return "F4";
	case Key::F5:
		return "F5";
	case Key::F6:
		return "F6";
	case Key::F7:
		return "F7";
	case Key::F8:
		return "F8";
	case Key::F9:
		return "F9";
	case Key::F10:
		return "F10";
	case Key::F11:
		return "F11";
	case Key::F12:
		return "F12";
	case Key::F13:
		return "F13";
	case Key::F14:
		return "F14";
	case Key::F15:
		return "F15";
	case Key::F16:
		return "F16";
	case Key::F17:
		return "F17";
	case Key::F18:
		return "F18";
	case Key::F19:
		return "F19";
	case Key::F20:
		return "F20";
	}

	return "Unknown Key";
}

Key::Key(int key) : key_(key)
{
}