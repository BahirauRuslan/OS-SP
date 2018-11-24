#include "FileUtil.h"


FileUtil* FileUtil::fileUtil = nullptr;


FileUtil::FileUtil()
{
}


FileUtil::~FileUtil()
{
}


HANDLE FileUtil::getFileHandle(std::string fileName)
{
	return CreateFile((LPCSTR)fileName.c_str(), GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}


BY_HANDLE_FILE_INFORMATION FileUtil::getFileInformation(HANDLE file)
{
	BY_HANDLE_FILE_INFORMATION fileInformation;
	GetFileInformationByHandle(file, &fileInformation);
	return fileInformation;
}


FileUtil* FileUtil::getFileUtil()
{
	if (fileUtil == nullptr)
	{
		fileUtil = new FileUtil();
	}
	return fileUtil;
}
