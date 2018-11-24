#pragma once
#include <Windows.h>
#include <string>

class FileDateTimeManager
{
public:
	FileDateTimeManager();
	~FileDateTimeManager();
	std::string getCreatedDateTimeFile(HANDLE file);
	std::string getEditedDateTimeFile(HANDLE file);
	std::string getOpenedDateTimeFile(HANDLE file);
};

