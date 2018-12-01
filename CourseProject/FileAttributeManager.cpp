#include "FileAttributeManager.h"



FileAttributeManager::FileAttributeManager()
{
}


FileAttributeManager::~FileAttributeManager()
{
}


bool FileAttributeManager::attributeStatus(BY_HANDLE_FILE_INFORMATION file,
	DWORD attribute)
{
	return hasAttribute(file.dwFileAttributes, attribute);
}


void FileAttributeManager::setAttributeStatus(std::string fileName, DWORD attribute,
	bool status)
{
	DWORD attributes = GetFileAttributes((LPCSTR)fileName.c_str());
	if (hasAttribute(attributes, attribute) != status)
	{
		SetFileAttributes((LPCSTR)fileName.c_str(), 
			(status) ? (attributes + attribute) : (attributes - attribute));
	}
}


bool FileAttributeManager::hasAttribute(DWORD attributes, DWORD attribute)
{
	return (attributes & attribute) == attribute;
}
