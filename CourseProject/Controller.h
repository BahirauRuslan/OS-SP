#pragma once
#include <map>
#include "MainForm.h";
#include "FileDateTimeManager.h";
#include "FileUtil.h";

class Controller
{
public:
	Controller();
	Controller(MainForm form);
	~Controller();
	int run(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
		int nShowCmd, WNDPROC wndProc);
	LONG mainEvents(HWND hwnd, UINT winEvent, WPARAM wParam, LPARAM lParam);
	void commandEvents(WPARAM wParam);
	void selectFileData();
	void closeWindow();
	void quit(WPARAM wParam);
	void viewCreatedDateTimeFile(HANDLE file);
	void viewEditedDateTimeFile(HANDLE file);
	void viewOpenedDateTimeFile(HANDLE file);
	MainForm getForm();
	FileDateTimeManager getDateTimeManager();
	void setForm(MainForm form);
	void setDateTimeManager(FileDateTimeManager dateTimeManager);
private:
	MainForm form;
	FileDateTimeManager dateTimeManager;
};

typedef void(Controller::*events)(WPARAM);
typedef void(Controller::*commEvents)();
