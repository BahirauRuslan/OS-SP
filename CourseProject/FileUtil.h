#pragma once
#include <Windows.h>
#include <string>
class FileUtil
{
public:
	HANDLE getFileHandle(std::string fileName);
	static FileUtil* getFileUtil();
private:
	FileUtil();
	~FileUtil();
	static FileUtil* fileUtil;
};

