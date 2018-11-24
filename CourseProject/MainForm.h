#pragma once
#include <Windows.h>
#include <string>

#define DEFAULT_X_POS 10
#define DEFAULT_Y_LAYOUT 10
#define TOP_Y_POS 10

#define WCLASS_NAME "myWindow"
#define TITLE "Атрибуты файла в NTFS"
#define MAIN_X_POS 100
#define MAIN_Y_POS 100
#define MAIN_WIDTH 400
#define MAIN_HEIGHT 450

#define LABELS_WIDHT 380
#define LABELS_HEIGHT 20
#define LABELS_Y_LAYOUT LABELS_HEIGHT + DEFAULT_Y_LAYOUT
#define CREATED_DATETIME_LABEL "Создан: "
#define EDITED_DATETIME_LABEL "Изменен: "
#define OPENED_DATETIME_LABEL "Открыт: "
#define CREATED_DATETIME_LABEL_Y_POS TOP_Y_POS
#define EDITED_DATETIME_LABEL_Y_POS CREATED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT
#define OPENED_DATETIME_LABEL_Y_POS EDITED_DATETIME_LABEL_Y_POS + LABELS_Y_LAYOUT

#define HELP "Помощь"
#define FILE_MENU "Файл"
#define FILE_MENU_OPEN "Открыть"
#define FILE_MENU_EXIT "Выход"
#define FILE_MENU_OPEN_ACTION 1
#define FILE_MENU_EXIT_ACTION 3

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
	HWND getHWnd();
	HMENU getMainMenu();
	HMENU getFileMenu();
	HWND getCreatedDateTimeLabel();
	HWND getEditedDateTimeLabel();
	HWND getOpenedDateTimeLabel();
	void setHWnd(HWND hWnd);
	void setMainMenu(HMENU mainMenu);
	void setFileMenu(HMENU fileMenu);
	void setCreatedDateTimeLabel(HWND createdDateTimeLabel);
	void setEditedDateTimeLabel(HWND editedDateTimeLabel);
	void setOpenedDateTimeLabel(HWND openedDateTimeLabel);
private:
	HWND hWnd;
	HMENU mainMenu;
	HMENU fileMenu;
	HWND createdDateTimeLabel;
	HWND editedDateTimeLabel;
	HWND openedDateTimeLabel;
};

