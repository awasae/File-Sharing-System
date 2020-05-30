#include <deque>
#include <sstream>
#include <string>
#include <map>
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include "RenameParsingStrategy.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;

std::vector<string> RenameParsingStrategy::parse(std::string fileNames) {
	std::vector<string> v;
	std::string get = fileNames;
	string firstFile;
	string secondFile;
	istringstream input(get);
	input >> firstFile;
	input >> secondFile;
	string firstInput = firstFile + " "+ secondFile;
	v.push_back(firstInput);
	v.push_back(firstFile);
	return v;
}