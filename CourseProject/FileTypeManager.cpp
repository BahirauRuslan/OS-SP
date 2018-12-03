#include "FileTypeManager.h"



FileTypeManager::FileTypeManager()
{
}


FileTypeManager::~FileTypeManager()
{
}


HICON FileTypeManager::getIcon(std::string fileName)
{
	SHFILEINFO flInfo;
	SHGetFileInfo(fileName.c_str(), 0, &flInfo, sizeof(flInfo), SHGFI_ICON);
	return flInfo.hIcon;
}


std::string FileTypeManager::getFileType(std::string fileName)
{
	SHFILEINFO flInfo;
	SHGetFileInfo(fileName.c_str(), 0, &flInfo, sizeof(flInfo), SHGFI_TYPENAME);
	return flInfo.szTypeName;
}
