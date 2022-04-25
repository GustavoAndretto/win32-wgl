#pragma once
#include "Window.hpp"

class WindowHandler
{
public:
	void draw();

	void joystickEvent();

	void mouseKeyEvent(MouseKey key, MouseKeyState state, int mods);

	void mouseMoveEvent(int x, int y);

	void mouseLeaveEvent();

	void mouseEnterEvent();

	void moveEvent(int x, int y);

	void resizeEvent(int width, int height);

	void keyEvent(Key key, KeyState state, KeyMods mods, int scancode);

	void minimizeEvent();

	void maximizeEvent();

	void restoreEvent();

	void closeEvent();

	void visible(bool value);

	const bool visible() const;

	void trackMouse(bool value);

	bool mouseTracked() const;

	WindowHandler(Window* window);

	WindowHandler(const WindowHandler&) = delete;
private:

	Window* window_;
};