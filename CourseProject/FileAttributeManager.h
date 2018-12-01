#pragma once
#include <Windows.h>
#include <string>
class FileAttributeManager
{
public:
	FileAttributeManager();
	~FileAttributeManager();
	bool attributeStatus(BY_HANDLE_FILE_INFORMATION file, DWORD attribute);
	void setAttributeStatus(std::string fileName, DWORD attribute, 
		bool status);
private:
	bool hasAttribute(DWORD attributes, DWORD attribute);
};

