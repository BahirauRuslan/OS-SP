#pragma once
#include <Windows.h>
#include <string>

#define DEFAULT_X_POS 10
#define DEFAULT_X_LAYOUT 15
#define DEFAULT_Y_LAYOUT 10
#define TOP_Y_POS 10

#define WCLASS_NAME "myWindow"
#define TITLE "Атрибуты файла в NTFS"
#define MAIN_X_POS 100
#define MAIN_Y_POS 100
#define MAIN_WIDTH 700
#define MAIN_HEIGHT 450

#define LABELS_WIDHT 380
#define LABELS_HEIGHT 20
#define LABELS_Y_LAYOUT LABELS_HEIGHT + DEFAULT_Y_LAYOUT
#define CREATED_DATETIME_LABEL "Создан: "
#define EDITED_DATETIME_LABEL "Изменен: "
#define OPENED_DATETIME_LABEL "Открыт: "
#define PATH_LABEL "Путь: "
#define FILE_SIZE_LABEL "Размер файла: "
#define FILE_SIZE_LABEL_SUFFIX " байт"
#define CREATED_DATETIME_LABEL_Y_POS TOP_Y_POS
#define EDITED_DATETIME_LABEL_Y_POS CREATED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT
#define OPENED_DATETIME_LABEL_Y_POS EDITED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT
#define PATH_LABEL_Y_POS OPENED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT + DEFAULT_Y_LAYOUT
#define FILE_SIZE_LABEL_Y_POS PATH_LABEL_Y_POS + LABELS_Y_LAYOUT

#define CHECKBOX_WIDTH 160
#define CHECKBOX_HEIGHT 20
#define CHECKBOX_X_LAYOUT CHECKBOX_WIDTH + DEFAULT_X_LAYOUT
#define CHECKBOX_Y_LAYOUT CHECKBOX_HEIGHT + DEFAULT_Y_LAYOUT
#define READONLY_CBOX "Только чтение"
#define READONLY_CBOX_Y_POS FILE_SIZE_LABEL_Y_POS + CHECKBOX_Y_LAYOUT + DEFAULT_Y_LAYOUT
#define HIDDEN_CBOX "Скрытый"
#define HIDDEN_CBOX_X_POS DEFAULT_X_POS + CHECKBOX_X_LAYOUT
#define HIDDEN_CBOX_Y_POS READONLY_CBOX_Y_POS

#define HELP "Помощь"
#define FILE_MENU "Файл"
#define FILE_MENU_OPEN "Открыть"
#define FILE_MENU_EXIT "Выход"

#define FILE_MENU_OPEN_ACTION 1
#define FILE_MENU_EXIT_ACTION 3
#define READONLY_CHECK_ACTION 5
#define HIDDEN_CHECK_ACTION 7

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
	HWND getHWnd();
	HMENU getMainMenu();
	HMENU getFileMenu();
	HWND getCreatedDateTimeLabel();
	HWND getEditedDateTimeLabel();
	HWND getOpenedDateTimeLabel();
	HWND getPathLabel();
	HWND getFileSizeLabel();
	HWND getReadOnlyCBox();
	HWND getHiddenCBox();
	void setHWnd(HWND hWnd);
	void setMainMenu(HMENU mainMenu);
	void setFileMenu(HMENU fileMenu);
	void setCreatedDateTimeLabel(HWND createdDateTimeLabel);
	void setEditedDateTimeLabel(HWND editedDateTimeLabel);
	void setOpenedDateTimeLabel(HWND openedDateTimeLabel);
	void setPathLabel(HWND pathLabel);
	void setFileSizeLabel(HWND fileSizeLabel);
	void setReadOnlyCBox(HWND readOnlyCBox);
	void setHiddenCBox(HWND hiddenCBox);
private:
	HWND hWnd;
	HMENU mainMenu;
	HMENU fileMenu;
	HWND createdDateTimeLabel;
	HWND editedDateTimeLabel;
	HWND openedDateTimeLabel;
	HWND pathLabel;
	HWND fileSizeLabel;
	HWND readOnlyCBox;
	HWND hiddenCBox;
};

