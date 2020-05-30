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
#include "TouchCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "PasswordProxy.h"

class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;
class SimpleFileFactory;
class SimpleFileSystem;

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* s, AbstractFileFactory* f) {
	this->fileSystem = s;
	this->factory = f;
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;

}

int TouchCommand::execute(std::string file) {
	string get = file;
	std::string input = "";
	string word;
	if (get.find(' ') == std::string::npos) {
		AbstractFile* temp = this->factory->createFile(file);
		//AbstractFile* poi = new PasswordProxy(temp, "1234");

		bool isNull = temp == nullptr;

		if (isNull == false) {
			int success = this->fileSystem->addFile(file,temp);
			if (success == 1) {
				delete temp;
				cout << "Can't create, File Already present ";
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			cout << "Can't create the file";
			return 1;
		}
	}
	else if (get.find(' ') != std::string::npos) {
		istringstream input(get);
		string temp;
		string firstWord;
		string secondWord;
		string nextWord;
		input >> firstWord;
		input >> secondWord;
		while (input >> nextWord) {
			temp += nextWord;
		}
		bool spaces;
		bool spaces2;
		spaces2 = std::all_of(secondWord.begin(), secondWord.end(), isspace);
		spaces = std::all_of(nextWord.begin(), nextWord.end(), isspace);
		if (spaces == true) {
			if (secondWord == "-p") {
				string password;
				AbstractFile* temp = this->factory->createFile(firstWord);
				cout << "Please choose a password for the file" << endl;
				std::getline(cin, password);
				AbstractFile* poi = new PasswordProxy(temp, password);

				bool isNull = temp == nullptr;

				if (isNull == false) {
					int success = this->fileSystem->addFile(firstWord, poi);
					if (success == 1) {
						delete temp;
						cout << "Can't add";
						cout << endl;
						return 1;
					}

					else {
						return 0;
					}
				}
				else {
					cout << "can't create the file" << endl;
					return 1;
				}

			}
			else if(spaces2==true){
				AbstractFile* temp = this->factory->createFile(firstWord);
				//AbstractFile* poi = new PasswordProxy(temp, "1234");

				bool isNull = temp == nullptr;

				if (isNull == false) {
					int success = this->fileSystem->addFile(firstWord, temp);
					if (success == 1) {
						delete temp;
						cout << "Can't create, File Already present ";
						return 1;
					}

					else {
						return 0;
					}
				}
				else {
					
					cout << "Can't create the file";
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
	else {
		return 1;
	}
	
}