#pragma once
// Studio 18 - simplefilefactory class declaration goes here

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include "SimpleFileSystem.h"

class AbstractFile;

class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string);
};