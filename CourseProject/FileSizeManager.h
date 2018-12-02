#pragma once
#include <Windows.h>

class FileSizeManager
{
public:
	FileSizeManager();
	~FileSizeManager();
	long getFileSize(BY_HANDLE_FILE_INFORMATION file);
};

