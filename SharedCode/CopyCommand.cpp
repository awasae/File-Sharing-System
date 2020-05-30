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
#include "CopyCommand.h"
#include "TouchCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include "AbstractFileVisitor.h"
#include "PasswordProxy.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;
class SimpleFileFactory;
class SimpleFileSystem;
class MetaDisplayVisitor;
class BasicDisplayVisitor;

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* s) {
	this->fileSystem = s;
	
}

void CopyCommand::displayInfo() {
	cout << "COPY command makes a new file, copy can be invoked with the command: copy <fileName> <fileName>" << endl;

}

int CopyCommand::execute(std::string file) {

	string get = file;
	string firstFile;
	string secondFile;
	istringstream input(get);
	input >> firstFile;
	input >> secondFile;
	string nextWord;
	string temp;
	while (input >> nextWord) {
		temp += nextWord;
	}
	bool spaces;
	spaces = std::all_of(nextWord.begin(), nextWord.end(), isspace);
	string txt = ".txt";
	string img = ".img";
	if (spaces == true) {
		//check if the first file is present
		AbstractFile* absFile = this->fileSystem->openFile(firstFile);

		this->fileSystem->closeFile(absFile);
		//file Opened
		if (absFile != nullptr) {
			if (firstFile.find(txt) != std::string::npos) {
				secondFile += txt;
			}
			else if (firstFile.find(img) != std::string::npos) {
				secondFile += img;
			}

			AbstractFile* f = absFile->clone(secondFile);

			bool isNull = f == nullptr;

			int success;
			if (isNull == false) {
				success = this->fileSystem->addFile(secondFile, f);

				if (success == 1) {
					delete f;
					cout << "Can't add the file";
					return 1;
				}

				else {
					return 0;
				}
			}
			else {
				cout << "can't create the file";
				return 1;
			}
		}
		else {
			cout << "No File Present in the File System. ";
			return 1;
		}
	}
	else {
		return 1;
	}

}

