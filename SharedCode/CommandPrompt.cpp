#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include "CommandPrompt.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractCommand.h"


using namespace std;

CommandPrompt::CommandPrompt() {
	this->factory = nullptr;
	this->fileSystem = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* file) {
	this->fileSystem = file;

}

void CommandPrompt::setFileFactory(AbstractFileFactory* file) {
	this->factory = file;

}

int CommandPrompt::addCommand(std::string s, AbstractCommand* file) {
	size_t mapSize = this->map.size();
	this->map.insert({ s, file });
	size_t afterInsert = this->map.size();

	if (afterInsert > mapSize) {
		return 0;
	}
	else return 1;
}

int CommandPrompt::run() {
	cout << "Enter a command,q to quit, help for a list of commands, or " << endl;
	cout << "help followed by a command name for more information about " << endl;
	cout << "that command " << endl;
	while (1) {
		std::string get = this->prompt();
		if (get == "q") {
			break;
		}
		else if (get == "help") {
			this->listCommands();
			
		}

		//string get = this->prompt();
		//check for space in the input
		else if (get.find(' ') == std::string::npos)
		{
			// no spaces.
			//search the map for command
			if (this->map.find(get) == this->map.end()) {
				//not found
				cout << "Command not found" << endl;
			}
			else {
				//command found
				int result = this->map.find(get)->second->execute("");
				if (result == 1) {
					cout << "Command Failed" << endl;
					
				}
			}
		}

		//check if there are space (input is more than one word)
		else if (get.find(' ') != std::string::npos) {
			//space found
			istringstream input(get);
			string firstWord;
			string secondWord;
			input >> firstWord;

			//check if firstWord is "help"
			if (firstWord=="help") {
				//extract secondWord
				input >> secondWord;
				//search the map for the command
				if (this->map.find(secondWord) == this->map.end()) {
					//not found
					cout << "Command not found" << endl;
				}
				else {
					//command found
					this->map.find(secondWord)->second->displayInfo();
	
				}
			}
			//else firstWord is command name
			else {
				//search map
				if (this->map.find(firstWord) == this->map.end()) {
					//not found
					cout << "Command not found" << endl;
					
					
				}
				else {
					secondWord = get.substr(get.find_first_of(" \t") + 1);
					int result = this->map.find(firstWord)->second->execute(secondWord);
					if (result == 1) {
						cout << "Command Failed" << endl;

					}
				}
			}
		}
	}
	return 1;
}

		


void CommandPrompt::listCommands() {
	for (auto it = this->map.cbegin(); it != this->map.cend(); it++) {
		cout << (*it).first << '\t' ;

	}
	cout << endl;
}


std::string CommandPrompt::prompt() {	
	std::string get = "";
	cout << "$  ";
	std::getline(std::cin, get);
	return get;
}