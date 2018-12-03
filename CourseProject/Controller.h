#pragma once
#include <map>
#include "MainForm.h";
#include "FileAttributeManager.h";
#include "FileDateTimeManager.h";
#include "FileSizeManager.h";
#include "FileUtil.h";
#include "FileTypeManager.h";

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
	void viewIcon();
	void viewFileType();
	void readOnlyCheckAction();
	void hiddenCheckAction();
	void archiveCheckAction();
	void compressedCheckAction();
	void encryptedCheckAction();
	void indexedCheckAction();
	void changeCheckBoxStatus(DWORD attributeAction);
	void changeAttributeStatus(DWORD attribute);
	void changeCompressedStatus();
	void changeEncryptedStatus();
	std::string GetOfn();
	MainForm getForm();
	FileAttributeManager getFileAttributeManager();
	FileDateTimeManager getDateTimeManager();
	FileSizeManager getFileSizeManager();
	FileTypeManager getFileTypeManager();
	void setOfn(std::string ofn);
	void setForm(MainForm form);
	void setFileAttributeManager(FileAttributeManager fileAttributeManager);
	void setDateTimeManager(FileDateTimeManager dateTimeManager);
	void setFileSizeManager(FileSizeManager fileSizeManager);
	void setFileTypeManager(FileTypeManager fileTypeManager);
private:
	std::string ofn;
	MainForm form;
	FileAttributeManager fileAttributeManager;
	FileDateTimeManager dateTimeManager;
	FileSizeManager fileSizeManager;
	FileTypeManager fileTypeManager;
};

typedef void(Controller::*events)(WPARAM);
typedef void(Controller::*commEvents)();
