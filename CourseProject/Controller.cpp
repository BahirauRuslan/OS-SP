#include "Controller.h"

std::map<DWORD, DWORD> attributesActionMap = { { FILE_ATTRIBUTE_READONLY, READONLY_CHECK_ACTION },
											   { FILE_ATTRIBUTE_HIDDEN, HIDDEN_CHECK_ACTION },
											   { FILE_ATTRIBUTE_ARCHIVE, ARCHIVE_CHECK_ACTION },
											   { FILE_ATTRIBUTE_COMPRESSED, COMPRESSED_CHECK_ACTION },
											   { FILE_ATTRIBUTE_ENCRYPTED, ENCRYPTED_CHECK_ACTION},
											   { FILE_ATTRIBUTE_NOT_CONTENT_INDEXED, INDEXED_CHECK_ACTION } };

std::map<UINT, events> mainEventMap = { { WM_DESTROY, &Controller::quit },
										{ WM_COMMAND, &Controller::commandEvents } };

std::map<UINT, commEvents> commandEventMap = { { FILE_MENU_OPEN_ACTION, &Controller::selectFileData },
											   { FILE_MENU_EXIT_ACTION, &Controller::closeWindow },
											   { READONLY_CHECK_ACTION, &Controller::readOnlyCheckAction },
											   { HIDDEN_CHECK_ACTION, &Controller::hiddenCheckAction },
											   { ARCHIVE_CHECK_ACTION, &Controller::archiveCheckAction },
											   { COMPRESSED_CHECK_ACTION, &Controller::compressedCheckAction },
											   { ENCRYPTED_CHECK_ACTION, &Controller::encryptedCheckAction },
											   { INDEXED_CHECK_ACTION, &Controller::indexedCheckAction } };


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
	std::string fileName = form.selectFile();
	if (fileName != "")
	{
		ofn = fileName;
		HANDLE file = FileUtil::getFileUtil()->getFileHandle(ofn);
		BY_HANDLE_FILE_INFORMATION fileInf
			= FileUtil::getFileUtil()->getFileInformation(file);
		CloseHandle(file);
		viewCreatedDateTimeFile(fileInf);
		viewEditedDateTimeFile(fileInf);
		viewOpenedDateTimeFile(fileInf);
		viewFilePath(ofn);
		viewFileSize(fileInf);
		viewStatus(fileInf, FILE_ATTRIBUTE_READONLY);
		viewStatus(fileInf, FILE_ATTRIBUTE_HIDDEN);
		viewStatus(fileInf, FILE_ATTRIBUTE_ARCHIVE);
		viewStatus(fileInf, FILE_ATTRIBUTE_COMPRESSED);
		viewStatus(fileInf, FILE_ATTRIBUTE_ENCRYPTED);
		viewStatus(fileInf, FILE_ATTRIBUTE_NOT_CONTENT_INDEXED);
		form.setAllCheckBoxEnableStatus(true);
		viewIcon();
		viewFileType();
	}
}


void Controller::viewCreatedDateTimeFile(BY_HANDLE_FILE_INFORMATION file)
{
	form.setToLabel(form.getCreatedDateTimeLabel(),
		CREATED_DATETIME_LABEL + dateTimeManager.getCreatedDateTimeFile(file));
}


void Controller::viewEditedDateTimeFile(BY_HANDLE_FILE_INFORMATION file)
{
	form.setToLabel(form.getEditedDateTimeLabel(),
		EDITED_DATETIME_LABEL + dateTimeManager.getEditedDateTimeFile(file));
}


void Controller::viewOpenedDateTimeFile(BY_HANDLE_FILE_INFORMATION file)
{
	form.setToLabel(form.getOpenedDateTimeLabel(),
		OPENED_DATETIME_LABEL + dateTimeManager.getOpenedDateTimeFile(file));
}


void Controller::viewFilePath(std::string path)
{
	form.setToLabel(form.getPathLabel(), PATH_LABEL + path);
}


void Controller::viewFileSize(BY_HANDLE_FILE_INFORMATION file)
{
	std::string sizeStr = std::to_string(fileSizeManager.getFileSize(file));
	form.setToLabel(form.getFileSizeLabel(), FILE_SIZE_LABEL + sizeStr
		+ FILE_SIZE_LABEL_SUFFIX);
}


void Controller::viewStatus(BY_HANDLE_FILE_INFORMATION file, DWORD attribute)
{
	CheckDlgButton(form.getHWnd(), attributesActionMap[attribute],
		(fileAttributeManager.attributeStatus(file, attribute) 
			? BST_CHECKED : BST_UNCHECKED));
}


void Controller::viewIcon()
{
	form.addPicture(fileTypeManager.getIcon(ofn));
}


void Controller::viewFileType()
{
	form.setToLabel(form.getFileTypeLabel(), 
		FILE_TYPE_LABEL + fileTypeManager.getFileType(ofn));
}


void Controller::readOnlyCheckAction()
{
	changeCheckBoxStatus(attributesActionMap[FILE_ATTRIBUTE_READONLY]);
	changeAttributeStatus(FILE_ATTRIBUTE_READONLY);
}


void Controller::hiddenCheckAction()
{
	changeCheckBoxStatus(attributesActionMap[FILE_ATTRIBUTE_HIDDEN]);
	changeAttributeStatus(FILE_ATTRIBUTE_HIDDEN);
}


void Controller::archiveCheckAction()
{
	changeCheckBoxStatus(attributesActionMap[FILE_ATTRIBUTE_ARCHIVE]);
	changeAttributeStatus(FILE_ATTRIBUTE_ARCHIVE);
}


void Controller::compressedCheckAction()
{
	changeCompressedStatus();
	changeCheckBoxStatus(attributesActionMap[FILE_ATTRIBUTE_COMPRESSED]);
}


void Controller::encryptedCheckAction()
{
	changeEncryptedStatus();
	changeCheckBoxStatus(attributesActionMap[FILE_ATTRIBUTE_ENCRYPTED]);
}


void Controller::indexedCheckAction()
{
	changeCheckBoxStatus(attributesActionMap[FILE_ATTRIBUTE_NOT_CONTENT_INDEXED]);
	changeAttributeStatus(FILE_ATTRIBUTE_NOT_CONTENT_INDEXED);
}


void Controller::changeCheckBoxStatus(DWORD attributeAction)
{
	if (IsDlgButtonChecked(form.getHWnd(), attributeAction))
	{
		CheckDlgButton(form.getHWnd(), attributeAction, BST_UNCHECKED);
	}
	else
	{
		CheckDlgButton(form.getHWnd(), attributeAction, BST_CHECKED);
	}
}


void Controller::changeAttributeStatus(DWORD attribute)
{
	if (ofn != "")
	{
		fileAttributeManager.setAttributeStatus(ofn, attribute,
			IsDlgButtonChecked(form.getHWnd(), attributesActionMap[attribute]));
	}
}


void  Controller::changeCompressedStatus()
{
	if (ofn != "")
	{
		if (!IsDlgButtonChecked(form.getHWnd(), attributesActionMap[FILE_ATTRIBUTE_COMPRESSED])
			&& IsDlgButtonChecked(form.getHWnd(), attributesActionMap[FILE_ATTRIBUTE_ENCRYPTED]))
		{
			encryptedCheckAction();
		}
		HANDLE file = FileUtil::getFileUtil()->getFileHandleForCompression(ofn);
		fileAttributeManager.setCompressedStatus(file,
			!IsDlgButtonChecked(form.getHWnd(), COMPRESSED_CHECK_ACTION));
		CloseHandle(file);
	}
}


void Controller::changeEncryptedStatus()
{
	if (ofn != "")
	{
		if (!IsDlgButtonChecked(form.getHWnd(), attributesActionMap[FILE_ATTRIBUTE_ENCRYPTED])
			&& IsDlgButtonChecked(form.getHWnd(), attributesActionMap[FILE_ATTRIBUTE_COMPRESSED]))
		{
			compressedCheckAction();
		}
		fileAttributeManager.setEncryptedStatus(ofn,
			!IsDlgButtonChecked(form.getHWnd(), ENCRYPTED_CHECK_ACTION));
	}
}


std::string Controller::GetOfn()
{
	return ofn;
}


MainForm Controller::getForm()
{
	return form;
}


FileAttributeManager Controller::getFileAttributeManager()
{
	return fileAttributeManager;
}


FileDateTimeManager Controller::getDateTimeManager()
{
	return dateTimeManager;
}


FileSizeManager Controller::getFileSizeManager()
{
	return fileSizeManager;
}


FileTypeManager Controller::getFileTypeManager()
{
	return fileTypeManager;
}


void Controller::setOfn(std::string ofn)
{
	this->ofn = ofn;
}


void Controller::setForm(MainForm form)
{
	this->form = form;
}


void Controller::setFileAttributeManager(FileAttributeManager fileAttributeManager)
{
	this->fileAttributeManager = fileAttributeManager;
}


void Controller::setDateTimeManager(FileDateTimeManager dateTimeManager)
{
	this->dateTimeManager = dateTimeManager;
}


void Controller::setFileSizeManager(FileSizeManager fileSizeManager)
{
	this->fileSizeManager = fileSizeManager;
}


void Controller::setFileTypeManager(FileTypeManager fileTypeManager)
{
	this->fileTypeManager = fileTypeManager;
}
