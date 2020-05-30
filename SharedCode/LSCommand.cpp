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
#include "LSCommand.h"
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

LSCommand::LSCommand(AbstractFileSystem* s) {
	this->fileSystem = s;
	
}

void LSCommand::displayInfo() {
	cout << "ls command display the filenames, ls can be invoked with the command: ls or ls -m" << endl;

}

int LSCommand::execute(std::string file) {
	istringstream input(file);
	string firstWord;
	string secondWord;
	input >> firstWord;
	input >> secondWord;
	string nextWord;
	string temp;
	while (input >> nextWord) {
		temp += nextWord;
	}
	bool spaces;
	bool spaces2;
	spaces2 = std::all_of(secondWord.begin(), secondWord.end(), isspace);
	spaces = std::all_of(nextWord.begin(), nextWord.end(), isspace);
	if (spaces == true) {
		if (firstWord == "") {
			std::set<string> result = this->fileSystem->getFileNames();
			int count = 0;
			for (auto it = result.begin(); it != result.end(); it++) {
				cout << *it << ' ' << ' '<< "\t";
				count++;
				if (count % 2 == 0) {
					cout << endl;
				}

			}
			if (count % 2 != 0) {
				cout << endl;
			}
			return 0;
		}

		if (firstWord == "-m" && spaces2==true) {
			std::set<string> result = this->fileSystem->getFileNames();
			for (auto it = result.begin(); it != result.end(); it++) {
				AbstractFile* poi = this->fileSystem->openFile(*it);
				AbstractFileVisitor* bdv = new MetadataDisplayVisitor;
				poi->accept(bdv);
				this->fileSystem->closeFile(poi);
			}

			return 0;

		}
	}
	return 1;
	
}