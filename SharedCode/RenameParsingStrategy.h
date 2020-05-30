#pragma once
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

class RenameParsingStrategy:public AbstractParsingStrategy {
public:
	virtual std::vector<string> parse(std::string);
};