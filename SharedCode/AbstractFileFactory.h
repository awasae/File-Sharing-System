#pragma once
// studio 18 - file factory interface declared here

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "AbstractFile.h"

class AbstractFile;
class SimpleFileFactory;

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string)=0;
};