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
#include "SimpleFileSystem.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem*);
	~LSCommand() = default;
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* fileSystem;
};