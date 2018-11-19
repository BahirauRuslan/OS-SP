#include <Windows.h>
#include <map>
#include <string>

#define FILE_MENU_OPEN 1
#define FILE_MENU_EXIT 2

LONG CALLBACK WinEvents(HWND, UINT, WPARAM, LPARAM);

typedef void(*event)(HWND, WPARAM);
typedef void(*simpleEvent)(HWND);

void Quit(HWND, WPARAM);
void CommandEvents(HWND, WPARAM);
void InitWindow(HWND, WPARAM);
void AddMenus(HWND);
void AddLabels(HWND);
void SelectFile(HWND);
void MenuExit(HWND);

std::map<UINT, event> events = { {WM_DESTROY, Quit},
								 {WM_CREATE, InitWindow},
								 {WM_COMMAND, CommandEvents} };

std::map<UINT, simpleEvent> simpleEvents = { {FILE_MENU_OPEN, SelectFile},
											 {FILE_MENU_EXIT, MenuExit} };

HMENU hMenu;

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
	wClass.lpszClassName = "myWindow";
	wClass.lpfnWndProc = WinEvents;
	wClass.cbWndExtra = 0;
	wClass.cbClsExtra = 0;

	if (!RegisterClass(&wClass))
	{
		MessageBox(NULL, "Error: custom class not register", "Error", MB_OK);
		return -1;
	}

	hwnd = CreateWindow("myWindow", "Properties", WS_OVERLAPPEDWINDOW, 30, 30, 
		400, 450, HWND_DESKTOP, NULL, hInstance, NULL);
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
		events[winEvent](hwnd, wParam);
	}
	else
	{
		return DefWindowProc(hwnd, winEvent, wParam, lParam);
	}
	return 0;
}

/*
	IMPLEMENTATION
*/

void InitWindow(HWND hWnd, WPARAM wParam)
{
	AddMenus(hWnd);
	AddLabels(hWnd);
}

void CommandEvents(HWND hWnd, WPARAM wParam)
{
	UINT eventCode = LOWORD(wParam);
	if (simpleEvents.find(eventCode) != simpleEvents.end())
	{
		simpleEvents[eventCode](hWnd);
	}
}

void AddMenus(HWND hWnd)
{
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_OPEN, "Открыть");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Выход");

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "Файл");
	AppendMenu(hMenu, MF_STRING, NULL, "Помощь");
	SetMenu(hWnd, hMenu);
}

void AddLabels(HWND hWnd)
{
	HWND label = CreateWindow("static", "Создан: ", WS_VISIBLE | WS_CHILD, 10, 10, 380, 
		20, hWnd, NULL, NULL, NULL);
	HWND label2 = CreateWindow("static", "Изменен: ", WS_VISIBLE | WS_CHILD, 10, 40, 380,
		20, hWnd, NULL, NULL, NULL);
	HWND label3 = CreateWindow("static", "Открыт: ", WS_VISIBLE | WS_CHILD, 10, 70, 380,
		20, hWnd, NULL, NULL, NULL);
	/*
	LPSTR a = new char[260];
	GetWindowText(label, a, 260);
	std::string b = a;
	std::string con = b + "яяя";
	SetWindowText(label, (LPCSTR)con.c_str());
	delete[] a;
	*/
}

void SelectFile(HWND hWnd)
{
	OPENFILENAME ofn;
	char szFile[260];
	HANDLE hf;

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn))
	{
		MessageBox(NULL, ofn.lpstrFile, "File", MB_OK);
	}
}

void MenuExit(HWND hWnd)
{
	DestroyWindow(hWnd);
}

void Quit(HWND hWnd, WPARAM wParam)
{
	PostQuitMessage(0);
}
