#include "App/App.h"

#include <Windows.h>

int main() {
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	App* app = new App;
	app->run();
	delete app;
}