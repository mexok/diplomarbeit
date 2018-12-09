
#include <windows.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#include <IAOpenGL.h>
#include "CSrc.h"
#include "IAWinTouchHandler.h"
#include "IALibrary.h"

#define CLASSNAME "main"

LONG WINAPI WndProc(HWND,UINT,WPARAM,LPARAM);
void CreateOpenGLContext(HWND hwnd);

static HGLRC openGLContextHandle;

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nCmdShow) {
	static char szAppName[] = "Flower";
	static char szTitle[]="Flower";
	WNDCLASS windowClass = (WNDCLASS){
			.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
			.lpfnWndProc = (WNDPROC)WndProc,
			.cbClsExtra = 0,
			.cbWndExtra = 0,
			.hInstance = hInstance,
			.hIcon = NULL,
			.hCursor = LoadCursor(NULL, IDC_ARROW),
			.hbrBackground = (HBRUSH)0,
			.lpszMenuName = NULL,
			.lpszClassName = szAppName
	};
	RegisterClass(&windowClass);

	HWND mainWindowHandle = CreateWindow(
			szAppName, // app name
			szTitle,   // Text for window title bar
			WS_TILEDWINDOW,
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
			NULL,     // no parent window
			NULL,     // Use the window class menu.
			hInstance,// This instance owns this window
			NULL      // We don't use any extra data
	);
	if (!mainWindowHandle) {
		return(0);
	}

	CreateOpenGLContext(mainWindowHandle);

	ShowWindow(mainWindowHandle, SW_SHOWDEFAULT);
	UpdateWindow(mainWindowHandle);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return( msg.wParam );

}

LONG WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	static bool areResourcesCreated = false;
	HDC hDC;
	switch (msg) {
		case WM_SIZE:
		case WM_PAINT:
			hDC = GetDC(hwnd);
			RECT clientRect;
			GetClientRect(hwnd, &clientRect);
			int framebufferWidth = clientRect.right - clientRect.left;
			int framebufferHeight = clientRect.bottom - clientRect.top;

			if (areResourcesCreated == false) {
				createResources(framebufferWidth, framebufferHeight);
				areResourcesCreated = true;
			}else{
				updateFramebufferSize(framebufferWidth, framebufferHeight);
			}
			RECT windowRect;
			GetWindowRect(hwnd, &windowRect);
			long border = ((windowRect.right - windowRect.left) - framebufferWidth) / 2;
			float offsetX = windowRect.left + border;
			float offsetY = windowRect.bottom - border - framebufferHeight;
			IAWinTouchHandler_setWindowOffset(offsetX, offsetY);

			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
			render();
			SwapBuffers(hDC);
			ReleaseDC(hwnd, hDC);
			return 0;

		case WM_DESTROY:
			wglDeleteContext(openGLContextHandle);
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void CreateOpenGLContext(HWND hwnd){
	static PIXELFORMATDESCRIPTOR pfd = {
			sizeof (PIXELFORMATDESCRIPTOR), // strcut size
			1,                              // Version number
			PFD_DRAW_TO_WINDOW |    // Flags, draw to a window,
			PFD_DRAW_TO_BITMAP |
			PFD_DOUBLEBUFFER |
			PFD_SUPPORT_OPENGL,     // use OpenGL
			PFD_TYPE_RGBA,          // RGBA pixel values
			24,                     // 24-bit color
			0, 0, 0,                // RGB bits & shift sizes.
			0, 0, 0,                // Don't care about them
			0, 0,                   // No alpha buffer info
			0, 0, 0, 0, 0,          // No accumulation buffer
			32,                     // 32-bit depth buffer
			0,                      // No stencil buffer
			0,                      // No auxiliary buffers
			PFD_MAIN_PLANE,         // Layer type
			0,                      // Reserved (must be 0)
			0,                      // No layer mask
			0,                      // No visible mask
			0                       // No damage mask
	};

	int nMyPixelFormatID;

	HDC hDC = GetDC(hwnd);
	nMyPixelFormatID = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, nMyPixelFormatID, &pfd);

	openGLContextHandle = wglCreateContext(hDC);
	wglMakeCurrent(hDC, openGLContextHandle);
	glewInit();
	glEnable(GL_MULTISAMPLE);
	ReleaseDC(hwnd, hDC);
}

