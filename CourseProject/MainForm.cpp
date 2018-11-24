#include "MainForm.h"

MainForm::MainForm()
{
}


MainForm::~MainForm()
{
}


void MainForm::registerWClass(HINSTANCE hInstance, WNDPROC wndProc)
{
	WNDCLASS wClass;
	memset(&wClass, 0, sizeof(WNDCLASS));
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.hInstance = hInstance;
	wClass.lpszClassName = WCLASS_NAME;
	wClass.lpfnWndProc = wndProc;
	wClass.cbWndExtra = 0;
	wClass.cbClsExtra = 0;

	if (!RegisterClass(&wClass))
	{
		MessageBox(NULL, "Error: custom class not register", "Error", MB_OK);
	}
}


std::string MainForm::selectFile()
{
	OPENFILENAME ofn;
	char szFile[DEFAULT_STR_SIZE];
	HANDLE hf;

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All\0*.*\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	GetOpenFileName(&ofn);
	return ofn.lpstrFile;
}


void MainForm::initWindow()
{
	addMenus();
	addLabels();
}


void MainForm::addMenus()
{
	mainMenu = CreateMenu();
	fileMenu = CreateMenu();
	AppendMenu(fileMenu, MF_STRING, FILE_MENU_OPEN_ACTION, FILE_MENU_OPEN);
	AppendMenu(fileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(fileMenu, MF_STRING, FILE_MENU_EXIT_ACTION, FILE_MENU_EXIT);

	AppendMenu(mainMenu, MF_POPUP, (UINT_PTR)fileMenu, FILE_MENU);
	AppendMenu(mainMenu, MF_STRING, NULL, HELP);
	SetMenu(hWnd, mainMenu);
}


void MainForm::addLabels()
{
	createdDateTimeLabel = CreateWindow("static", CREATED_DATETIME_LABEL, 
		WS_VISIBLE | WS_CHILD, DEFAULT_X_POS, CREATED_DATETIME_LABEL_Y_POS, 
		LABELS_WIDHT, LABELS_HEIGHT, hWnd, NULL, NULL, NULL);
	editedDateTimeLabel = CreateWindow("static", EDITED_DATETIME_LABEL, 
		WS_VISIBLE | WS_CHILD, DEFAULT_X_POS, EDITED_DATETIME_LABEL_Y_POS, 
		LABELS_WIDHT, LABELS_HEIGHT, hWnd, NULL, NULL, NULL);
	openedDateTimeLabel = CreateWindow("static", OPENED_DATETIME_LABEL, 
		WS_VISIBLE | WS_CHILD, DEFAULT_X_POS, OPENED_DATETIME_LABEL_Y_POS, 
		LABELS_WIDHT, LABELS_HEIGHT, hWnd, NULL, NULL, NULL);
}

std::string MainForm::getFromLabel(HWND label)
{
	LPSTR str = new char[DEFAULT_STR_SIZE];
	GetWindowText(label, str, DEFAULT_STR_SIZE);
	return str;
}


void MainForm::setToLabel(HWND label, std::string str)
{
	SetWindowText(label, (LPCSTR)str.c_str());
}


HWND MainForm::getHWnd()
{
	return hWnd;
}


HMENU MainForm::getMainMenu()
{
	return mainMenu;
}


HMENU MainForm::getFileMenu()
{
	return fileMenu;
}


HWND MainForm::getCreatedDateTimeLabel()
{
	return createdDateTimeLabel;
}


HWND MainForm::getEditedDateTimeLabel()
{
	return editedDateTimeLabel;
}


HWND MainForm::getOpenedDateTimeLabel()
{
	return openedDateTimeLabel;
}


void MainForm::setHWnd(HWND hWnd)
{
	this->hWnd = hWnd;
}


void MainForm::setMainMenu(HMENU mainMenu)
{
	this->mainMenu = mainMenu;
}


void MainForm::setFileMenu(HMENU fileMenu)
{
	this->fileMenu = fileMenu;
}


void MainForm::setCreatedDateTimeLabel(HWND createdDateTimeLabel)
{
	this->createdDateTimeLabel = createdDateTimeLabel;
}


void MainForm::setEditedDateTimeLabel(HWND editedDateTimeLabel)
{
	this->editedDateTimeLabel = editedDateTimeLabel;
}


void MainForm::setOpenedDateTimeLabel(HWND openedDateTimeLabel)
{
	this->openedDateTimeLabel = openedDateTimeLabel;
}
