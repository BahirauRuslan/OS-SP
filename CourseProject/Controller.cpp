#include "Controller.h"

std::map<UINT, events> mainEventMap = { { WM_DESTROY, &Controller::quit },
										{ WM_COMMAND, &Controller::commandEvents } };

std::map<UINT, commEvents> commandEventMap = { { FILE_MENU_OPEN_ACTION, &Controller::selectFileData },
											   { FILE_MENU_EXIT_ACTION, &Controller::closeWindow } };


Controller::Controller()
{
}


Controller::Controller(MainForm form)
{
	this->form = form;
}


Controller::~Controller()
{
}


int Controller::run(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nShowCmd, WNDPROC wndProc)
{
	MSG msg;
	form.registerWClass(hInstance, wndProc);
	HWND hWnd = CreateWindow(WCLASS_NAME, TITLE, WS_OVERLAPPEDWINDOW, MAIN_X_POS,
		MAIN_Y_POS, MAIN_WIDTH, MAIN_HEIGHT, HWND_DESKTOP, NULL, hInstance,
		NULL);
	ShowWindow(hWnd, nShowCmd);
	UpdateWindow(hWnd);
	form.setHWnd(hWnd);

	form.initWindow();

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}


LONG Controller::mainEvents(HWND hwnd, UINT winEvent, WPARAM wParam, LPARAM lParam)
{
	if (mainEventMap.find(winEvent) != mainEventMap.end())
	{
		(this->*mainEventMap[winEvent])(wParam);
	}
	else
	{
		return DefWindowProc(hwnd, winEvent, wParam, lParam);
	}
	return 0;
}


void Controller::commandEvents(WPARAM wParam)
{
	UINT eventCode = LOWORD(wParam);
	if (commandEventMap.find(eventCode) != commandEventMap.end())
	{
		(this->*commandEventMap[eventCode])();
	}
}


void Controller::closeWindow()
{
	DestroyWindow(form.getHWnd());
}


void Controller::quit(WPARAM wParam)
{
	PostQuitMessage(0);
}


void Controller::selectFileData()
{
	std::string ofn = form.selectFile();
	HANDLE file = FileUtil::getFileUtil()->getFileHandle(ofn);
	viewCreatedDateTimeFile(file);
	viewEditedDateTimeFile(file);
	viewOpenedDateTimeFile(file);
}


void Controller::viewCreatedDateTimeFile(HANDLE file)
{
	form.setToLabel(form.getCreatedDateTimeLabel(),
		CREATED_DATETIME_LABEL + dateTimeManager.getCreatedDateTimeFile(file));
}


void Controller::viewEditedDateTimeFile(HANDLE file)
{
	form.setToLabel(form.getEditedDateTimeLabel(),
		EDITED_DATETIME_LABEL + dateTimeManager.getEditedDateTimeFile(file));
}


void Controller::viewOpenedDateTimeFile(HANDLE file)
{
	form.setToLabel(form.getOpenedDateTimeLabel(),
		OPENED_DATETIME_LABEL + dateTimeManager.getOpenedDateTimeFile(file));
}


MainForm Controller::getForm()
{
	return form;
}


FileDateTimeManager Controller::getDateTimeManager()
{
	return dateTimeManager;
}


void Controller::setForm(MainForm form)
{
	this->form = form;
}


void Controller::setDateTimeManager(FileDateTimeManager dateTimeManager)
{
	this->dateTimeManager = dateTimeManager;
}
