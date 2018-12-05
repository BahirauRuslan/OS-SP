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


void FileAttributeManager::setCompressedStatus(HANDLE file, bool status)
{
	DWORD dummy;
	USHORT compression = (status) ? COMPRESSION_FORMAT_DEFAULT : COMPRESSION_FORMAT_NONE;
	DeviceIoControl(file, FSCTL_SET_COMPRESSION,
		&compression, sizeof(USHORT), NULL, 0, (LPDWORD)&dummy, NULL);
}


void FileAttributeManager::setEncryptedStatus(std::string fileName, bool status)
{
	(status) ? EncryptFile(fileName.c_str()) : DecryptFile(fileName.c_str(), 0);
}


bool FileAttributeManager::hasAttribute(DWORD attributes, DWORD attribute)
{
	return (attributes & attribute) == attribute;
}
