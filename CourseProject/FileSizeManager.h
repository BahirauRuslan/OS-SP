#pragma once
#include <Windows.h>

class FileSizeManager
{
public:
	FileSizeManager();
	~FileSizeManager();
	int getFileSize(BY_HANDLE_FILE_INFORMATION file);
};

