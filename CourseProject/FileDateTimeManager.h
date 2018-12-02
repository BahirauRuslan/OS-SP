#pragma once
#include <Windows.h>
#include <string>
#include <cstdio>

class FileDateTimeManager
{
public:
	FileDateTimeManager();
	~FileDateTimeManager();
	std::string getCreatedDateTimeFile(BY_HANDLE_FILE_INFORMATION file);
	std::string getEditedDateTimeFile(BY_HANDLE_FILE_INFORMATION file);
	std::string getOpenedDateTimeFile(BY_HANDLE_FILE_INFORMATION file);
};

