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
#include "DisplayCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include "AbstractFileVisitor.h"


class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;
class SimpleFileFactory;
class SimpleFileSystem;
class MetaDisplayVisitor;
class BasicDisplayVisitor;

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* s) {
	this->fileSystem = s;

}

void DisplayCommand::displayInfo() {
	cout << "Display command displays the file contents, display can be invoked with the command: ds <fileName> or ds <fileName> -d" << endl;

}

int DisplayCommand::execute(std::string file) {
	string get = file;

	if (get.find(' ') == std::string::npos){
		
		std::vector<char> v;
		AbstractFile* poi = this->fileSystem->openFile(file);
		if (poi == nullptr) {
			cout << "No such file present ";
			return 1;
		}
		AbstractFileVisitor* ls = new BasicDisplayVisitor;
		poi->accept(ls);
		this->fileSystem->closeFile(poi);

		return 0;

	}
	//check for spaces
	else if(get.find(' ') != std::string::npos) {
		//space found
		istringstream input(get);
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
		std::vector<char> v;
		if (spaces == true) {
			if (secondWord == "-d") {
				//display the file contents
				AbstractFile* absFile = this->fileSystem->openFile(firstWord);
				if (absFile == nullptr) {
					return 1;
				}
				v = absFile->read();
				this->fileSystem->closeFile(absFile);
				for (int i = 0; i < v.size(); i++) {
					cout << v[i];
				}
				cout << endl;

				return 0;
				AbstractFileVisitor* ls = new BasicDisplayVisitor;
				absFile->accept(ls);
				this->fileSystem->closeFile(absFile);
				return 0;

			}
			else if (spaces2 == true) {
				std::vector<char> v;
				AbstractFile* poi = this->fileSystem->openFile(firstWord);
				if (poi == nullptr) {
					cout << "No such file present ";
					return 1;
				}
				AbstractFileVisitor* ls = new BasicDisplayVisitor;
				poi->accept(ls);
				this->fileSystem->closeFile(poi);
				return 0;

			}
			else {
				return 1;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 1;
	}


}