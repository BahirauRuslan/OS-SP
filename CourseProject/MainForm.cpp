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
	addCheckBoxes();
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
	pathLabel = CreateWindow("static", PATH_LABEL,
		WS_VISIBLE | WS_CHILD, DEFAULT_X_POS, PATH_LABEL_Y_POS,
		LABELS_WIDHT, LABELS_HEIGHT, hWnd, NULL, NULL, NULL);
	fileSizeLabel = CreateWindow("static", FILE_SIZE_LABEL,
		WS_VISIBLE | WS_CHILD, DEFAULT_X_POS, FILE_SIZE_LABEL_Y_POS,
		LABELS_WIDHT, LABELS_HEIGHT, hWnd, NULL, NULL, NULL);
	fileTypeLabel = CreateWindow("static", FILE_TYPE_LABEL,
		WS_VISIBLE | WS_CHILD, FILE_TYPE_LABEL_X_POS, FILE_TYPE_LABEL_Y_POS,
		LABELS_WIDHT, LABELS_HEIGHT, hWnd, NULL, NULL, NULL);
}


void MainForm::addCheckBoxes()
{
	readOnlyCBox = CreateWindow("button", READONLY_CBOX, WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
		DEFAULT_X_POS, READONLY_CBOX_Y_POS, CHECKBOX_WIDTH, 
		CHECKBOX_HEIGHT, hWnd, (HMENU)READONLY_CHECK_ACTION, NULL, NULL);
	hiddenCBox = CreateWindow("button", HIDDEN_CBOX, WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
		HIDDEN_CBOX_X_POS, HIDDEN_CBOX_Y_POS, CHECKBOX_WIDTH,
		CHECKBOX_HEIGHT, hWnd, (HMENU)HIDDEN_CHECK_ACTION, NULL, NULL);
	archiveCBox = CreateWindow("button", ARCHIVE_CBOX, WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
		ARCHIVE_CBOX_X_POS, ARCHIVE_CBOX_Y_POS, CHECKBOX_WIDTH,
		CHECKBOX_HEIGHT, hWnd, (HMENU)ARCHIVE_CHECK_ACTION, NULL, NULL);
	compressedCBox = CreateWindow("button", COMPRESSED_CBOX, WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
		DEFAULT_X_POS, COMPRESSED_CBOX_Y_POS, CHECKBOX_WIDTH,
		CHECKBOX_HEIGHT, hWnd, (HMENU)COMPRESSED_CHECK_ACTION, NULL, NULL);
	encryptedCBox = CreateWindow("button", ENCRYPTED_CBOX, WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
		DEFAULT_X_POS, ENCRYPTED_CBOX_Y_POS, CHECKBOX_WIDTH,
		CHECKBOX_HEIGHT, hWnd, (HMENU)ENCRYPTED_CHECK_ACTION, NULL, NULL);
	indexedCBox = CreateWindow("button", INDEXED_CBOX, WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
		DEFAULT_X_POS, INDEXED_CBOX_Y_POS, CHECKBOX_WIDTH,
		CHECKBOX_HEIGHT, hWnd, (HMENU)INDEXED_CHECK_ACTION, NULL, NULL);
	setAllCheckBoxEnableStatus(false);
}


void MainForm::setAllCheckBoxEnableStatus(bool status)
{
	EnableWindow(readOnlyCBox, status);
	EnableWindow(hiddenCBox, status);
	EnableWindow(archiveCBox, status);
	EnableWindow(compressedCBox, status);
	EnableWindow(encryptedCBox, status);
	EnableWindow(indexedCBox, status);
}


void MainForm::addPicture(HICON bitmap1)
{
	PAINTSTRUCT ps;
	ICONINFO inf;
	GetIconInfo(bitmap1, &inf);
	BITMAP bm;
	HBITMAP bitmap = inf.hbmColor;
	GetObject(bitmap, sizeof(bm), &bm);
	picture = CreateWindow("static", INDEXED_CBOX, WS_VISIBLE | WS_CHILD | SS_BITMAP,
		PIC_X_POS, DEFAULT_Y_LAYOUT, bm.bmWidth,
		bm.bmHeight, hWnd, NULL, NULL, NULL);
	HDC hdc = GetDC(picture);
	HDC memBit = CreateCompatibleDC(hdc);
	SelectObject(memBit, bitmap);
	ReleaseDC(picture, hdc);
	hdc = BeginPaint(picture, &ps);
	BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, memBit, 0, 0, SRCCOPY);
	EndPaint(picture, &ps);
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


HWND MainForm::getPathLabel()
{
	return pathLabel;
}


HWND MainForm::getFileSizeLabel()
{
	return fileSizeLabel;
}


HWND MainForm::getFileTypeLabel()
{
	return fileTypeLabel;
}


HWND MainForm::getReadOnlyCBox()
{
	return readOnlyCBox;
}


HWND MainForm::getHiddenCBox()
{
	return hiddenCBox;
}


HWND MainForm::getArchiveCBox()
{
	return archiveCBox;
}


HWND MainForm::getCompressedCBox()
{
	return compressedCBox;
}


HWND MainForm::getEncryptedCBox()
{
	return encryptedCBox;
}


HWND MainForm::getIndexedCBox()
{
	return indexedCBox;
}


HWND MainForm::getPicture()
{
	return picture;
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


void MainForm::setPathLabel(HWND pathLabel)
{
	this->pathLabel = pathLabel;
}


void MainForm::setFileSizeLabel(HWND fileSizeLabel)
{
	this->fileSizeLabel = fileSizeLabel;
}


void MainForm::setFileTypeLabel(HWND fileTypeLabel)
{
	this->fileTypeLabel = fileTypeLabel;
}


void MainForm::setReadOnlyCBox(HWND readOnlyCBox)
{
	this->readOnlyCBox = readOnlyCBox;
}


void MainForm::setHiddenCBox(HWND hiddenCBox)
{
	this->hiddenCBox = hiddenCBox;
}


void MainForm::setArchiveCBox(HWND archiveCBox)
{
	this->archiveCBox = archiveCBox;
}


void MainForm::setCompressedCBox(HWND compressedCBox)
{
	this->compressedCBox = compressedCBox;
}


void MainForm::setEncryptedCBox(HWND encryptedCBox)
{
	this->encryptedCBox = encryptedCBox;
}


void MainForm::setIndexedCBox(HWND indexedCBox)
{
	this->indexedCBox = indexedCBox;
}


void MainForm::setPicture(HWND picture)
{
	this->picture = picture;
}
