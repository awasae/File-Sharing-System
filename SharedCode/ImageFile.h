#pragma once
// Image file class declaration here
#include "AbstractFile.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>


class AbstractFile;
class AbstractFileVisitor;

using namespace std;

class ImageFile : public AbstractFile {
	

public:
	ImageFile(std::string);
	virtual std::vector<char> read();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(std::string);

	std::string name;
	std::vector<char> contents;
	char size;


};