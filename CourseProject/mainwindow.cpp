#include <Windows.h>
#include <map>

LONG CALLBACK WinEvents(HWND, UINT, WPARAM, LPARAM);

typedef void(*event)();

void Quit();

std::map<UINT, event> events = { {WM_DESTROY, Quit} };

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nShowCmd)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS wClass;

	memset(&wClass, 0, sizeof(WNDCLASS));
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.hInstance = hInstance;
	wClass.lpszClassName = "window228";
	wClass.lpfnWndProc = WinEvents;
	wClass.cbWndExtra = 0;
	wClass.cbClsExtra = 0;

	if (!RegisterClass(&wClass))
	{
		MessageBox(NULL, "Error: custom class not register", "Error", MB_OK);
		return -1;
	}

	hwnd = CreateWindow("window228", "Properties", WS_OVERLAPPEDWINDOW, 30, 30, 
		200, 450, HWND_DESKTOP, NULL, hInstance, NULL);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LONG CALLBACK WinEvents(HWND hwnd, UINT winEvent, WPARAM wParam, LPARAM lParam)
{
	if (events.find(winEvent) != events.end())
	{
		events[winEvent]();
	}
	else
	{
		return DefWindowProc(hwnd, winEvent, wParam, lParam);
	}
	return 0;
}

void Quit()
{
	PostQuitMessage(0);
}
