#include "FileSizeManager.h"



FileSizeManager::FileSizeManager()
{
}


FileSizeManager::~FileSizeManager()
{
}


int FileSizeManager::getFileSize(BY_HANDLE_FILE_INFORMATION file)
{
	return file.nFileSizeLow;
}
