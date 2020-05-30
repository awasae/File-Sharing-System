#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <map>
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include "MacroCommand.h"
#include "RenameParsingStrategy.h"
#include "AbstractParsingStrategy.h"
#include "RenameParsingStrategy.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* s) {
	this->fileSystem = s;
}

void MacroCommand::displayInfo() {
	cout << "Macro command takes a bunch of command and execute them together" << endl;

}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* poi) {
	this->parse1 = poi;
}
int MacroCommand::execute(std::string file) {
	std::vector<string> fileNames = this->parse1->parse(file);
	int i = 0;
	for (auto a = this->commands.begin(); a != this->commands.end(); a++) {
		AbstractCommand* c = *a;
		int success =c->execute(fileNames[i]);
		if (success == 1) {
			return 1;
		}
		i++;
	}
	return 0;

}
void MacroCommand::addCommand(AbstractCommand* poi) {
	this->commands.push_back(poi);
}

