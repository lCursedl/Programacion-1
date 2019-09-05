#pragma once
#include <fstream>
#include <iostream>
#include <string>

class CFileManager
{
public:
	std::string* mFileName;
	std::fstream* mF;

	CFileManager();
	~CFileManager();
};

