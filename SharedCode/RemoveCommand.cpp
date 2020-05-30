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
#include "RemoveCommand.h"
#include "TouchCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"



class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;
class SimpleFileFactory;
class SimpleFileSystem;
class MetaDisplayVisitor;

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* s) {
	this->fileSystem = s;
}

void RemoveCommand::displayInfo() {
	cout << "Remove command removes the file, rm can be invoked with the command: rm" << endl;
}

int RemoveCommand::execute(std::string file) {
	std::string name = file;
	int remove = this->fileSystem->deleteFile(file);
	if (remove == 0) {
		return 0;
	}
	else cout << "Can't Delete. "; return 1;

}