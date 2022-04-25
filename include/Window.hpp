#pragma once
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Gamepad.hpp"

class Application;

class Window
{
public:
	typedef void* handle_t;
	
	struct dimension_t { int width, height; };

	struct position_t { int x, y; };

	struct rect_t { int x, y, width, height; };

	const std::string& text() const;

	void text(const std::u8string& text);

	void text(const std::string& title);

	dimension_t dimension() const;

	int width() const;

	int height() const;

	position_t position() const;

	void move(int x, int y);

	void move(position_t position);

	void resize(int width, int height);

	void resizable(bool status);

	handle_t handle();

	rect_t rect() const;

	void resize(dimension_t dimension);

	const bool visible() const;

	void close();

	void show();

	void update();

	void hide();

	void minimize();

	void maximize();

	void restore();

	void systemMenu(bool status);

	const bool systemMenu() const;

	void caption(bool status);

	const bool caption() const;

	void closeButton(bool status);

	const bool closeButton() const;

	void minimizeButton(bool status);

	const bool minimizeButton() const;

	void maximizeButton(bool status);

	const bool maximizeButton() const;

	Window(Application& application);

	Window(const Window&) = delete;

protected:
	virtual void draw();

	virtual void joystickEvent();

	virtual void mouseKeyEvent(MouseKey key, MouseKeyState state, int mods);

	virtual void mouseMoveEvent(int x, int y);

	virtual void mouseLeaveEvent();

	virtual void mouseEnterEvent();

	virtual void moveEvent(int x, int y);

	virtual void resizeEvent(int width, int height);

	virtual void keyEvent(Key key, KeyState state, KeyMods mods, int scancode);

	virtual void minimizeEvent();

	virtual void maximizeEvent();

	virtual void restoreEvent();

	virtual void closeEvent();

private:
	void trackMouse(bool value);

	bool mouseTracked() const;

	void visible(bool value);

	std::string text_;

	handle_t windowHandle_;

	rect_t rect_;

	Application& application_;

	bool trackMouse_;

	bool systemMenu_;
	
	bool maximizeButton_;

	bool minimizeButton_;

	bool closeButton_;

	bool caption_;

	bool resizable_;

	friend class WindowHandler;
};
