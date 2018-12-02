#include "FileDateTimeManager.h"


FileDateTimeManager::FileDateTimeManager()
{
}


FileDateTimeManager::~FileDateTimeManager()
{
}


std::string FileDateTimeManager::getCreatedDateTimeFile(BY_HANDLE_FILE_INFORMATION file)
{
	SYSTEMTIME createdTime;
	FileTimeToLocalFileTime(&(file.ftCreationTime), &(file.ftCreationTime));
	FileTimeToSystemTime(&(file.ftCreationTime), &createdTime);
	char buff[260];
	sprintf_s(buff, "%02d.%02d.%d %02d:%02d:%02d", createdTime.wDay, createdTime.wMonth, 
		createdTime.wYear, createdTime.wHour, createdTime.wMinute, createdTime.wSecond);
	return buff;
}


std::string FileDateTimeManager::getEditedDateTimeFile(BY_HANDLE_FILE_INFORMATION file)
{
	SYSTEMTIME editedTime;
	FileTimeToLocalFileTime(&(file.ftLastWriteTime), &(file.ftLastWriteTime));
	FileTimeToSystemTime(&(file.ftLastWriteTime), &editedTime);
	char buff[260];
	sprintf_s(buff, "%02d.%02d.%d %02d:%02d:%02d", editedTime.wDay, editedTime.wMonth,
		editedTime.wYear, editedTime.wHour, editedTime.wMinute, editedTime.wSecond);
	return buff;
}


std::string FileDateTimeManager::getOpenedDateTimeFile(BY_HANDLE_FILE_INFORMATION file)
{
	SYSTEMTIME openedTime;
	FileTimeToLocalFileTime(&(file.ftLastAccessTime), &(file.ftLastAccessTime));
	FileTimeToSystemTime(&(file.ftLastAccessTime), &openedTime);
	char buff[260];
	sprintf_s(buff, "%02d.%02d.%d %02d:%02d:%02d", openedTime.wDay, openedTime.wMonth,
		openedTime.wYear, openedTime.wHour, openedTime.wMinute, openedTime.wSecond);
	return buff;
}
