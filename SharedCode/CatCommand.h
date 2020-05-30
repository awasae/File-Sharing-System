#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	~CatCommand() = default;
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* fileSystem;

};