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
#include "CatCommand.h"
#include "TouchCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include "AbstractFileVisitor.h"
#include "GrepCommand.h"


class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;
class SimpleFileFactory;
class SimpleFileSystem;
class MetaDisplayVisitor;
class BasicDisplayVisitor;

using namespace std;

GrepCommand::GrepCommand(AbstractFileSystem* s) {
	this->fileSystem = s;

}

void GrepCommand::displayInfo() {
	cout << "grep command finds a string in all the files, grep can be invoked with the command: grep <atring_to_be_searched>" << endl;

}

int GrepCommand::execute(std::string file) {

	string get = file;

	std::set<string> result = this->fileSystem->getFileNames();
	std::set<string> files;
	std::vector<char> fileContent;
	std::string contents;
	int count = 0;
	for (auto it = result.begin(); it != result.end(); it++) {
		AbstractFile* i = this->fileSystem->openFile(*it);
		if (i != nullptr) {
			fileContent = i->read();
			for (auto a = fileContent.begin(); a != fileContent.end(); a++) {
				contents += *a;
			
			}
			if (contents.find(get) != std::string::npos) {
				// string found
				files.insert(i->getName());
				contents = "";
			}
			this->fileSystem->closeFile(i);
		}		
	}
	if (files.size() != 0) {
		for (auto it = files.begin(); it != files.end(); it++) {
			cout << *it << '\t';
		}
		cout << endl;
		return 0;
	}
	else {
		cout << "String not found in any of the files" << endl;
		return 0;
	}



}