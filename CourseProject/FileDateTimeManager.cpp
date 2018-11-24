#include "FileDateTimeManager.h"


FileDateTimeManager::FileDateTimeManager()
{
}


FileDateTimeManager::~FileDateTimeManager()
{
}


std::string FileDateTimeManager::getCreatedDateTimeFile(HANDLE file)
{
	FILETIME fCreatedTime;
	SYSTEMTIME createdTime;
	GetFileTime(file, &fCreatedTime, NULL, NULL);
	FileTimeToSystemTime(&fCreatedTime, &createdTime);
	return std::to_string(createdTime.wDay) + "." + std::to_string(createdTime.wMonth) +
		 "." + std::to_string(createdTime.wYear) + " " + std::to_string(createdTime.wHour) + ":" +
		std::to_string(createdTime.wMinute) + ":" + std::to_string(createdTime.wSecond);
}


std::string FileDateTimeManager::getEditedDateTimeFile(HANDLE file)
{
	FILETIME fEditedTime;
	SYSTEMTIME editedTime;
	GetFileTime(file, NULL, &fEditedTime, NULL);
	FileTimeToSystemTime(&fEditedTime, &editedTime);
	return std::to_string(editedTime.wDay) + "." + std::to_string(editedTime.wMonth) +
		"." + std::to_string(editedTime.wYear) + " " + std::to_string(editedTime.wHour) + ":" +
		std::to_string(editedTime.wMinute) + ":" + std::to_string(editedTime.wSecond);
}


std::string FileDateTimeManager::getOpenedDateTimeFile(HANDLE file)
{
	FILETIME fOpenedTime;
	SYSTEMTIME openedTime;
	GetFileTime(file, NULL, NULL, &fOpenedTime);
	FileTimeToSystemTime(&fOpenedTime, &openedTime);
	return std::to_string(openedTime.wDay) + "." + std::to_string(openedTime.wMonth) +
		"." + std::to_string(openedTime.wYear) + " " + std::to_string(openedTime.wHour) + ":" +
		std::to_string(openedTime.wMinute) + ":" + std::to_string(openedTime.wSecond);
}
