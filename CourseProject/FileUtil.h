#pragma once
#include <Windows.h>
#include <string>
class FileUtil
{
public:
	HANDLE getFileHandle(std::string fileName);
	HANDLE getFileHandleForCompression(std::string fileName);	///////////////////
	BY_HANDLE_FILE_INFORMATION getFileInformation(HANDLE file);
	static FileUtil* getFileUtil();
private:
	FileUtil();
	~FileUtil();
	static FileUtil* fileUtil;
};

