#include "CFileManager.h"

CFileManager::CFileManager()
{
	mFileName = new std::string();
	mF = new std::fstream();
}

CFileManager::~CFileManager()
{
}