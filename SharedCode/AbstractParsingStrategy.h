#pragma once
#include <deque>
#include <sstream>
#include <string>
#include <map>
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;

class AbstractParsingStrategy {
public:
	virtual std::vector<string> parse(std::string)=0;
};