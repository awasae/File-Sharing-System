#pragma once
// declaration of the interface all file systems provide goes here
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "AbstractFile.h"
#include <set>

using namespace std;
class SimpleFileFactory;
class AbstractFileSystem {

public:
	virtual int addFile(std::string,AbstractFile*) = 0;
	//virtual int createFile(std::string) = 0;
	virtual int deleteFile(std::string) = 0;
	virtual AbstractFile* openFile(std::string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
	virtual set<string> getFileNames() = 0;

};