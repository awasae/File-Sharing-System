#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "AbstractFileVisitor.h"

class AbstractFileVisitor;
using namespace std;

class AbstractFile {
public:
	virtual std::vector<char> read()=0;
	virtual int write(std::vector<char>)=0;
	virtual int append(std::vector<char>)=0;
	virtual unsigned int getSize()=0;
	virtual std::string getName()=0;
	virtual void accept(AbstractFileVisitor*)=0;
	virtual AbstractFile* clone(std::string) = 0;
	
};