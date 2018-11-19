#include "MainForm.h"


MainForm::MainForm(Controller controller)
{
	setController(controller);
}


MainForm::~MainForm()
{
}


HWND MainForm::getHWnd()
{
	return hWnd;
}


Controller MainForm::getController()
{
	return controller;
}


HMENU MainForm::getMainMenu()
{
	return mainMenu;
}


HMENU MainForm::getFileMenu()
{
	return fileMenu;
}


HWND MainForm::getCreatedDateLabel()
{
	return createdDateLabel;
}


HWND MainForm::getEditedDateLabel()
{
	return editedDateLabel;
}


HWND MainForm::getOpenedDateLabel()
{
	return openedDateLabel;
}


void MainForm::setHWnd(HWND hWnd)
{
	this->hWnd = hWnd;
}


void MainForm::setController(Controller controller)
{
	this->controller = controller;
}
