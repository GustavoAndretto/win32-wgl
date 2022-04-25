#include "WindowHandler.hpp"
#include "Window.hpp"

void WindowHandler::maximizeEvent()
{
	window_->maximizeEvent();
}

void WindowHandler::restoreEvent()
{
	window_->restoreEvent();
}

void WindowHandler::closeEvent()
{
	window_->closeEvent();
}

void WindowHandler::visible(bool value)
{
	window_->visible(value);
}

const bool WindowHandler::visible() const
{
	return window_->visible();
}

void WindowHandler::trackMouse(bool value)
{
	window_->trackMouse(value);
}

bool WindowHandler::mouseTracked() const
{
	return window_->mouseTracked();
}

WindowHandler::WindowHandler(Window* window) : window_(window)
{
}

void WindowHandler::resizeEvent(int width, int height)
{
	window_->rect_.height = height;
	window_->rect_.width = width;
	window_->resizeEvent(width, height);
}

void WindowHandler::keyEvent(Key key, KeyState state, KeyMods mods, int scancode)
{
	window_->keyEvent(key, state, mods, scancode);
}

void WindowHandler::minimizeEvent()
{
	window_->minimizeEvent();
}

void WindowHandler::draw()
{
	window_->draw();
}

void WindowHandler::mouseKeyEvent(MouseKey key, MouseKeyState state, int mods)
{
	window_->mouseKeyEvent(key, state, mods);
}

void WindowHandler::mouseMoveEvent(int x, int y)
{
	window_->mouseMoveEvent(x, y);
}

void WindowHandler::mouseLeaveEvent()
{
	window_->mouseLeaveEvent();
}

void WindowHandler::mouseEnterEvent()
{
	window_->mouseEnterEvent();
}

void WindowHandler::moveEvent(int x, int y)
{
	window_->rect_.x = x;
	window_->rect_.y = y;
	window_->moveEvent(x, y);
}
