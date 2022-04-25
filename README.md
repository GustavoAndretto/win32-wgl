# win32-wgl

Example: Draw Triangle

```cpp
#include "Window.hpp"
#include "Application.hpp"

#include <Windows.h>
#include <GL/GL.h>
#include <GL/glext.h>
#include <GL/wglext.h>

class MyWindow : public Window
{
public:
	MyWindow(Application& application) : Window(application)
	{
		this->text(u8"Window Jánêlã 창문 نافذة او شباك 窓 窗口");
		this->caption(true);
		this->systemMenu(true);
		this->minimizeButton(true);
		this->maximizeButton(true);
		this->resizable(true);
		this->resize(800, 600);

		createContext();
		makeContextCurrent();
		swapInterval(1);

		this->show();
	}

private:
	void draw()
	{
		int w = this->width();
		int h = this->height();

		glViewport(0, 0, w, h);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		glFlush();
	}

	void closeEvent()
	{
		destroyContext();
		this->close();
	}

	void createContext()
	{
		if (deviceContext = GetDC((HWND)this->handle()); deviceContext)
		{
			PIXELFORMATDESCRIPTOR pixelFormatDesc;
			ZeroMemory(&pixelFormatDesc, sizeof(PIXELFORMATDESCRIPTOR));

			pixelFormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			pixelFormatDesc.nVersion = 1;
			pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
			pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
			pixelFormatDesc.cColorBits = 32;
			pixelFormatDesc.cAlphaBits = 8;
			pixelFormatDesc.cDepthBits = 24;

			if (int pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDesc); !pixelFormat)
			{
				printf("failed to choose pixel format\n");
				return;
			}
			else if (!SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDesc))
			{
				printf("failed to set pixel format\n");
				return;
			}
	
			if (renderContext = wglCreateContext(deviceContext); !renderContext)
			{
				printf("failed to create render context\n");
				return;
			}
		}
	}

	void destroyContext() {
		wglDeleteContext(renderContext);
	}

	void makeContextCurrent() {
		wglMakeCurrent(deviceContext, renderContext);
	}

	void swapInterval(int value) {
		PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
		if (!wglSwapIntervalEXT) {
			printf("extension wglSwapIntervalEXT not found\n");
			return;
		}

		wglSwapIntervalEXT(value);
	}

	HDC deviceContext;
	HGLRC renderContext;
};

int main(int argc, char* argv[]) 
{
	Application application(argc, argv);
	MyWindow mainWindow(application);
	return application.execute();
}
```
