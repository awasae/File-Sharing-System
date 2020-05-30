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


class AbstractCommand;
class AbstractFileFactory;
class AbstractFileSystem;
class SimpleFileFactory;
class SimpleFileSystem;
class MetaDisplayVisitor;
class BasicDisplayVisitor;

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* s) {
	this->fileSystem = s;
	
}

void CatCommand::displayInfo() {
	cout << "CAT command writes to the file, cat can be invoked with the command: cat <fileName> or cat <fileName> -a" << endl;

}

int CatCommand::execute(std::string file) {

	string get = file;

	std::string input = "";
	string word;
	if (get.find(' ') == std::string::npos) {
		std::vector<char> v;
		cout << "Enter the data you would like to write to the file. Enter :wq to save and exit, enter :q to exit without saving." << endl;
		string word;
		while (std::getline(std::cin, input)) {
			if (input == ":wq" || input == ":q") {
				word = input;
				break;
			}
			istringstream input1(input);
			while (input1 >> word) {

				for (int i = 0; i < word.size(); i++) {
					v.push_back(word.at(i));
				}
				v.push_back(' ');
			}

			input = "";
			v.pop_back();
			v.push_back('\n');
			
		}
		if (v.size() == 0) return 0;
		if (word == ":wq") {
			
			v.pop_back();
			if (v.size() == 0) return 0;
			AbstractFile* poi = this->fileSystem->openFile(file);
			if (poi == nullptr) {
				return 1;
			}
			poi->write(v);
			this->fileSystem->closeFile(poi);
		}
		else if (word == ":q"){
			return 0;
		}
		
		return 0;

	}
	else if (get.find(' ') != std::string::npos) {
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
		if (spaces == true) {
			// if -a is followed after the fileName append to the file
			if (secondWord == "-a") {
				//display the file contents
				cout << "File: " << firstWord << endl;
				AbstractFile* absFile = this->fileSystem->openFile(firstWord);
				if (absFile == nullptr) return 1;
				AbstractFileVisitor* ls = new BasicDisplayVisitor;
				absFile->accept(ls);
				this->fileSystem->closeFile(absFile);


				std::string input2 = "";

				std::vector<char> v;
				cout << "Enter the data you would like to append to the file. Enter :wq to save and exit, enter :q to exit without saving." << endl;
				string word1;
				while (std::getline(std::cin, input2)) {
					if (input2 == ":wq" || input2 == ":q") {
						word1 = input2;
						break;
					}
					istringstream input1(input2);
					//v.push_back('\n');
					while (input1 >> word) {
						for (int i = 0; i < word.size(); i++) {
							v.push_back(word.at(i));
						}
						v.push_back(' ');
					}
					input2 = "";
					v.pop_back();
					v.push_back('\n');
				}
				if (v.size() == 0) return 0;
				if (word1 == ":wq") {
					v.pop_back();

					AbstractFile* absFile1 = this->fileSystem->openFile(firstWord);
					int a = absFile1->append(v);
					this->fileSystem->closeFile(absFile);
					if (a == 1) {
						return 1;
					}

				}
				else if (word1 == ":q") {
					return 0;
				}

				return 0;

			}
			/// if there are all empty space after the fileName
			else if (spaces2 == true) {
				string get = file;
				std::string input = "";
				string word;
				std::vector<char> v;
				cout << "Enter the data you would like to write to the file. Enter :wq to save and exit, enter :q to exit without saving." << endl;
				while (std::getline(std::cin, input)) {
					if (input == ":wq" || input == ":q") {
						word = input;
						break;
					}
					istringstream input1(input);
					while (input1 >> word) {

						for (int i = 0; i < word.size(); i++) {
							v.push_back(word.at(i));
						}
						v.push_back(' ');
					}

					input = "";
					v.pop_back();
					v.push_back('\n');

				}
				if (v.size() == 0) return 0;
				if (word == ":wq") {

					v.pop_back();
					if (v.size() == 0) return 0;
					AbstractFile* poi = this->fileSystem->openFile(firstWord);
					if (poi == nullptr) {
						return 1;
					}
					poi->write(v);
					this->fileSystem->closeFile(poi);
				}
				else if (word == ":q") {
					return 0;
				}

				return 0;

			}
			else {
				return 1;
			}
		}
		else{
			
			return 1;
		}
	}
	else {
	return 1;
}



}