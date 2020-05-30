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
#include "AbstractParsingStrategy.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;

class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem*);
	~MacroCommand() = default;
	virtual int execute(std::string);
	virtual void displayInfo();
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);

private:
	AbstractFileSystem* fileSystem;
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* parse1;
};