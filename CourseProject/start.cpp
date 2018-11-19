#include "Controller.h";
#include "MainForm.h";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nShowCmd)
{
	Controller &controller = *(new Controller());
	MainForm &mainForm = *(new MainForm(controller));
	return mainForm.run(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}
