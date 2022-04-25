#include "Window.hpp"
#include "Application.hpp"

#if defined(_WIN32)
#include "Windows.hpp"
#endif // OS Windows(x86/x64)

Window::Window(Application& application) : application_(application), windowHandle_(nullptr), rect_(rect_t()),
trackMouse_(false), maximizeButton_(false), minimizeButton_(false), closeButton_(false), caption_(false), systemMenu_(false), resizable_(false)
{
	if (!ImplCreateWindow(reinterpret_cast<HWND&>(windowHandle_)))
	{
		// Window Creation Failed.
	}

	ImplSetProp(static_cast<HWND>(windowHandle_), this);
}

void Window::draw()
{
}

void Window::keyEvent(Key key, KeyState state, KeyMods mods, int scancode)
{
}

void Window::joystickEvent()
{
}

void Window::mouseKeyEvent(MouseKey key, MouseKeyState state, int mods)
{
}

void Window::mouseMoveEvent(int x, int y)
{
}

void Window::mouseLeaveEvent()
{
}

void Window::mouseEnterEvent()
{
}

void Window::moveEvent(int x, int y)
{
}

void Window::resizeEvent(int width, int height)
{
}

void Window::minimizeEvent()
{
}

void Window::maximizeEvent()
{
}

void Window::restoreEvent()
{
}

void Window::closeEvent()
{
	close();
}

int Window::width() const
{
	return rect_.width;
}

int Window::height() const
{
	return rect_.height;
}

Window::dimension_t Window::dimension() const
{
	return dimension_t{ rect_.width, rect_.height };
}

void Window::resize(dimension_t dimension)
{
	ImplResizeWindow(static_cast<HWND>(windowHandle_), dimension.width, dimension.height);
}

void Window::resize(int width, int height)
{
	ImplResizeWindow(static_cast<HWND>(windowHandle_), width, height);
}

void Window::resizable(bool status)
{
	if (status == true && resizable_ == false)
	{
		resizable_ = true;
		ImplEnableResize(static_cast<HWND>(windowHandle_));
	}
	else
	{
		resizable_ = false;
		ImplDisableResize(static_cast<HWND>(windowHandle_));
	}
}

Window::handle_t Window::handle()
{
	return windowHandle_;
}

Window::rect_t Window::rect() const
{
	return rect_;
}

Window::position_t Window::position() const
{
	return position_t{ rect_.x, rect_.y };
}

void Window::move(position_t position)
{
	ImplMoveWindow(static_cast<HWND>(windowHandle_), position.x, position.y);
}

void Window::move(int x, int y)
{
	ImplMoveWindow(static_cast<HWND>(windowHandle_), x, y);
}

const std::string& Window::text() const
{
	return text_;
}

void Window::text(const std::u8string& text)
{
	std::string txt(text.cbegin(), text.cend());
	this->text(txt);
}

void Window::text(const std::string& text)
{
	text_ = text;
	ImplSetWindowText(static_cast<HWND>(windowHandle_), text.c_str());
}

void Window::show()
{
	ImplShowWindow(static_cast<HWND>(windowHandle_));
}

void Window::update()
{
	ImplUpdateWindow(static_cast<HWND>(windowHandle_));
}

void Window::hide()
{
	ImplHideWindow(static_cast<HWND>(windowHandle_));
}

void Window::minimize()
{
	ImplMinimizeWindow(static_cast<HWND>(windowHandle_));
}

void Window::maximize()
{
	ImplMaximizeWindow(static_cast<HWND>(windowHandle_));
}

void Window::restore()
{
	ImplRestoreWindow(static_cast<HWND>(windowHandle_));
}

void Window::systemMenu(bool status)
{
	if (status == true && systemMenu_ == false)
	{
		systemMenu_ = true;
		ImplEnableSystemMenu(static_cast<HWND>(windowHandle_));
	}
	else
	{
		systemMenu_ = false;
		ImplDisableSystemMenu(static_cast<HWND>(windowHandle_));		
	}

	update();
}

const bool Window::systemMenu() const
{
	return systemMenu_;
}

void Window::caption(bool status)
{
	if (status == true && caption_ == false)
	{
		caption_ = true;
		ImplEnableCaption(static_cast<HWND>(windowHandle_));
	}
	else
	{
		caption_ = false;
		ImplDisableCaption(static_cast<HWND>(windowHandle_));
	}
}

const bool Window::caption() const
{
	return caption_;
}

void Window::closeButton(bool status)
{
	if (status == true && closeButton_ == false)
	{
		closeButton_ = true;
		ImplEnableCloseButton(static_cast<HWND>(windowHandle_));
	}
	else
	{
		closeButton_ = false;
		ImplDisableCloseButton(static_cast<HWND>(windowHandle_));
	}
}

const bool Window::closeButton() const
{
	return closeButton_;
}

void Window::minimizeButton(bool status)
{
	if (status == true && minimizeButton_ == false)
	{
		minimizeButton_ = true;
		ImplEnableMinimizeButton(static_cast<HWND>(windowHandle_));
	}
	else
	{
		minimizeButton_ = false;
		ImplDisableMinimizeButton(static_cast<HWND>(windowHandle_));
	}
}

const bool Window::minimizeButton() const
{
	return minimizeButton_;
}

void Window::maximizeButton(bool status)
{
	if (status == true && maximizeButton_ == false)
	{
		maximizeButton_ = true;
		ImplEnableMaximizeButton(static_cast<HWND>(windowHandle_));
	}
	else
	{
		maximizeButton_ = false;
		ImplDisableMaximizeButton(static_cast<HWND>(windowHandle_));
	}
}

const bool Window::maximizeButton() const
{
	return maximizeButton_;
}

void Window::close()
{
	ImplDestroyWindow(static_cast<HWND>(windowHandle_));
}

const bool Window::visible() const
{
	return bool();
}

void Window::trackMouse(bool value)
{
	trackMouse_ = value;
}

bool Window::mouseTracked() const
{
	return trackMouse_;
}

void Window::visible(bool value)
{
	// TODO
}
