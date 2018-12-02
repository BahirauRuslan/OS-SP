#include "Controller.h";

LONG CALLBACK WinEvents(HWND hwnd, UINT winEvent, WPARAM wParam,
	LPARAM lParam);

MainForm &mainForm = *(new MainForm());
Controller &controller = *(new Controller(mainForm));

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nShowCmd)
{
	return controller.run(hInstance, hPrevInstance, lpCmdLine, nShowCmd, 
		WinEvents);
}

LONG CALLBACK WinEvents(HWND hwnd, UINT winEvent, WPARAM wParam,
	LPARAM lParam)
{
	return controller.mainEvents(hwnd, winEvent, wParam, lParam);
}
