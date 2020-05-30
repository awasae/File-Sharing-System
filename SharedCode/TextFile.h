#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>

class AbstractFile;
class AbstractFileVisitor;

class TextFile : public AbstractFile {
public:
	TextFile(std::string);
	virtual std::vector<char> read();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(std::string);
	std::vector<char> contents;
	std::string name;

};