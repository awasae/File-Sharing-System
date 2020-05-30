#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include "AbstractFile.h"

class AbstractFile;

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();
	virtual std::vector<char> read();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual void accept(AbstractFileVisitor*);
	virtual AbstractFile* clone(std::string);

private:
	AbstractFile* file;
	std::string password;

protected:
	string  passwordPrompt();
};