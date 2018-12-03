#pragma once
#include <Windows.h>
#include <string>
class FileTypeManager
{
public:
	FileTypeManager();
	~FileTypeManager();
	HICON getIcon(std::string fileName);
	std::string getFileType(std::string fileName);
};

