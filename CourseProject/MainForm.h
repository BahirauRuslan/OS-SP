#pragma once
#include <Windows.h>
#include "Controller.h"
class MainForm
{
public:
	MainForm(Controller);
	~MainForm();
	int run(HINSTANCE, HINSTANCE, LPSTR, int);
	HWND getHWnd();
	Controller getController();
	HMENU getMainMenu();
	HMENU getFileMenu();
	HWND getCreatedDateLabel();
	HWND getEditedDateLabel();
	HWND getOpenedDateLabel();
	void setHWnd(HWND);
	void setController(Controller);
	void setMainMenu(HMENU);
	void setFileMenu(HMENU);
	void setCreatedDateLabel(HWND);
	void setEditedDateLabel(HWND);
	void setOpenedDateLabel(HWND);
private:
	HWND hWnd;
	Controller controller;
	HMENU mainMenu;
	HMENU fileMenu;
	HWND createdDateLabel;
	HWND editedDateLabel;
	HWND openedDateLabel;
};

