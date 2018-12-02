#pragma once
#include <map>
#include "MainForm.h";
#include "FileAttributeManager.h";
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
	void viewStatus(BY_HANDLE_FILE_INFORMATION file, DWORD attribute);
	void readOnlyCheckAction();
	void hiddenCheckAction();
	void archiveCheckAction();
	void compressedCheckAction();
	void encryptedCheckAction();
	void indexedCheckAction();
	void changeCheckBoxStatus(DWORD attributeAction);
	void changeAttributeStatus(DWORD attribute);
	std::string GetOfn();
	MainForm getForm();
	FileAttributeManager getFileAttributeManager();
	FileDateTimeManager getDateTimeManager();
	FileSizeManager getFileSizeManager();
	void setOfn(std::string ofn);
	void setForm(MainForm form);
	void setFileAttributeManager(FileAttributeManager fileAttributeManager);
	void setDateTimeManager(FileDateTimeManager dateTimeManager);
	void setFileSizeManager(FileSizeManager fileSizeManager);
private:
	std::string ofn;
	MainForm form;
	FileAttributeManager fileAttributeManager;
	FileDateTimeManager dateTimeManager;
	FileSizeManager fileSizeManager;
};

typedef void(Controller::*events)(WPARAM);
typedef void(Controller::*commEvents)();
