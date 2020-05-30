#pragma once
// declaration of SimpleFileSystem class goes here
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include "AbstractFileSystem.h"
#include <map>
#include <set>


using namespace std;

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(std::string, AbstractFile*);
	//virtual int createFile(std::string);
	virtual int deleteFile(std::string);
	virtual AbstractFile* openFile(std::string);
	virtual int closeFile(AbstractFile*);
	virtual std::set<string> getFileNames();


private:
	std::map<string,AbstractFile*> map;
	std::set<AbstractFile*> set;

};