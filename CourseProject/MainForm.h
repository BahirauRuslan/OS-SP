#pragma once
#include <Windows.h>
#include <string>

#define DEFAULT_X_POS 10
#define DEFAULT_X_LAYOUT 15
#define DEFAULT_Y_LAYOUT 10
#define TOP_Y_POS 10

#define WCLASS_NAME "myWindow"
#define TITLE "NTFS file attributes"
#define MAIN_X_POS 100
#define MAIN_Y_POS 100
#define MAIN_WIDTH 700
#define MAIN_HEIGHT 380

#define PIC_X_POS 410
#define PIC_SIZE 32

#define LABELS_WIDHT 380
#define LABELS_HEIGHT 20
#define LABELS_Y_LAYOUT LABELS_HEIGHT + DEFAULT_Y_LAYOUT
#define CREATED_DATETIME_LABEL "Created: "
#define EDITED_DATETIME_LABEL "Modified: "
#define OPENED_DATETIME_LABEL "Accessed: "
#define PATH_LABEL "Path: "
#define FILE_SIZE_LABEL "Size: "
#define FILE_SIZE_LABEL_SUFFIX " bytes"
#define FILE_TYPE_LABEL "Type: "
#define CREATED_DATETIME_LABEL_Y_POS TOP_Y_POS
#define EDITED_DATETIME_LABEL_Y_POS CREATED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT
#define OPENED_DATETIME_LABEL_Y_POS EDITED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT
#define PATH_LABEL_Y_POS OPENED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT + DEFAULT_Y_LAYOUT
#define FILE_SIZE_LABEL_Y_POS PATH_LABEL_Y_POS + LABELS_Y_LAYOUT
#define FILE_TYPE_LABEL_X_POS PIC_X_POS
#define FILE_TYPE_LABEL_Y_POS DEFAULT_Y_LAYOUT + PIC_SIZE

#define CHECKBOX_WIDTH 210
#define CHECKBOX_HEIGHT 20
#define CHECKBOX_X_LAYOUT CHECKBOX_WIDTH + DEFAULT_X_LAYOUT
#define CHECKBOX_Y_LAYOUT CHECKBOX_HEIGHT + DEFAULT_Y_LAYOUT
#define READONLY_CBOX "Read-only"
#define READONLY_CBOX_Y_POS FILE_SIZE_LABEL_Y_POS + CHECKBOX_Y_LAYOUT + DEFAULT_Y_LAYOUT
#define HIDDEN_CBOX "Hidden"
#define HIDDEN_CBOX_X_POS DEFAULT_X_POS + CHECKBOX_X_LAYOUT
#define HIDDEN_CBOX_Y_POS READONLY_CBOX_Y_POS
#define ARCHIVE_CBOX "Archive"
#define ARCHIVE_CBOX_X_POS HIDDEN_CBOX_X_POS + CHECKBOX_X_LAYOUT
#define ARCHIVE_CBOX_Y_POS HIDDEN_CBOX_Y_POS
#define COMPRESSED_CBOX "Compressed"
#define COMPRESSED_CBOX_Y_POS READONLY_CBOX_Y_POS + CHECKBOX_Y_LAYOUT
#define ENCRYPTED_CBOX "Encrypted"
#define ENCRYPTED_CBOX_Y_POS COMPRESSED_CBOX_Y_POS + CHECKBOX_Y_LAYOUT
#define INDEXED_CBOX "Disable indexing"
#define INDEXED_CBOX_Y_POS ENCRYPTED_CBOX_Y_POS + CHECKBOX_Y_LAYOUT

#define HELP "help"
#define FILE_MENU "File"
#define FILE_MENU_OPEN "Open"
#define FILE_MENU_EXIT "Exit"

#define FILE_MENU_OPEN_ACTION 1
#define FILE_MENU_EXIT_ACTION 3
#define READONLY_CHECK_ACTION 5
#define HIDDEN_CHECK_ACTION 7
#define ARCHIVE_CHECK_ACTION 9
#define COMPRESSED_CHECK_ACTION 11
#define ENCRYPTED_CHECK_ACTION 13
#define INDEXED_CHECK_ACTION 15

#define DEFAULT_STR_SIZE 260


class MainForm
{
public:
	MainForm();
	~MainForm();	
	std::string selectFile();
	std::string getFromLabel(HWND label);
	void setToLabel(HWND label, std::string str);
	void initWindow();
	void registerWClass(HINSTANCE hInstance, WNDPROC wndProc);
	void addMenus();
	void addLabels();
	void addCheckBoxes();
	void addPicture(HICON bitmap);
	void setAllCheckBoxEnableStatus(bool status);
	HWND getHWnd();
	HMENU getMainMenu();
	HMENU getFileMenu();
	HWND getCreatedDateTimeLabel();
	HWND getEditedDateTimeLabel();
	HWND getOpenedDateTimeLabel();
	HWND getPathLabel();
	HWND getFileSizeLabel();
	HWND getFileTypeLabel();
	HWND getReadOnlyCBox();
	HWND getHiddenCBox();
	HWND getArchiveCBox();
	HWND getCompressedCBox();
	HWND getEncryptedCBox();
	HWND getIndexedCBox();
	HWND getPicture();
	void setHWnd(HWND hWnd);
	void setMainMenu(HMENU mainMenu);
	void setFileMenu(HMENU fileMenu);
	void setCreatedDateTimeLabel(HWND createdDateTimeLabel);
	void setEditedDateTimeLabel(HWND editedDateTimeLabel);
	void setOpenedDateTimeLabel(HWND openedDateTimeLabel);
	void setPathLabel(HWND pathLabel);
	void setFileSizeLabel(HWND fileSizeLabel);
	void setFileTypeLabel(HWND fileTypeLabel);
	void setReadOnlyCBox(HWND readOnlyCBox);
	void setHiddenCBox(HWND hiddenCBox);
	void setArchiveCBox(HWND archiveCBox);
	void setCompressedCBox(HWND compressedCBox);
	void setEncryptedCBox(HWND encryptedCBox);
	void setIndexedCBox(HWND indexedCBox);
	void setPicture(HWND picture);
private:
	HWND hWnd;
	HMENU mainMenu;
	HMENU fileMenu;
	HWND createdDateTimeLabel;
	HWND editedDateTimeLabel;
	HWND openedDateTimeLabel;
	HWND pathLabel;
	HWND fileSizeLabel;
	HWND fileTypeLabel;
	HWND readOnlyCBox;
	HWND hiddenCBox;
	HWND archiveCBox;
	HWND compressedCBox;
	HWND encryptedCBox;
	HWND indexedCBox;
	HWND picture;
};

