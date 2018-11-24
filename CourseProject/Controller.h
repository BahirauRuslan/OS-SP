#pragma once
#include <map>
#include "MainForm.h";
#include "FileDateTimeManager.h";
#include "FileSizeManager.h";
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
	void viewCreatedDateTimeFile(BY_HANDLE_FILE_INFORMATION file);
	void viewEditedDateTimeFile(BY_HANDLE_FILE_INFORMATION file);
	void viewOpenedDateTimeFile(BY_HANDLE_FILE_INFORMATION file);
	void viewFilePath(std::string path);
	void viewFileSize(BY_HANDLE_FILE_INFORMATION file);
	MainForm getForm();
	FileDateTimeManager getDateTimeManager();
	FileSizeManager getFileSizeManager();
	void setForm(MainForm form);
	void setDateTimeManager(FileDateTimeManager dateTimeManager);
	void setFileSizeManager(FileSizeManager fileSizeManager);
private:
	MainForm form;
	FileDateTimeManager dateTimeManager;
	FileSizeManager fileSizeManager;
};

typedef void(Controller::*events)(WPARAM);
typedef void(Controller::*commEvents)();
