// define methods of SimpleFileSystem class here
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"


using namespace std;

class TextFile;
class ImageFile;

int SimpleFileSystem::addFile(std::string name, AbstractFile* obj) {
	if (this->map.find(name) == this->map.end()) {
		//not found
		if (obj != nullptr) {
			map.insert({ name,obj });

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

int SimpleFileSystem::deleteFile(std::string name) {
	if (this->map.find(name) == this->map.end()) {
		//not found
		return 1;
	}
	else {
		AbstractFile* pointer = this->map.find(name)->second;
		if (this->set.find(pointer) == set.end()) {
			//not found
			this->map.erase(name);
			return 0;
		}
		else {
			return 1;
		}
	}
}

AbstractFile* SimpleFileSystem::openFile(std::string name) {
	if (this->map.find(name) == this->map.end()) {
		//not found
		return nullptr;
	}
	else {
		AbstractFile* pointer = this->map.find(name)->second;
		if (this->set.find(pointer) == set.end()) {
			//not found
			this->set.insert(pointer);
			return pointer;
		}
		else {
			return nullptr;
		}
	}

}
int SimpleFileSystem::closeFile(AbstractFile* obj) {
	if (this->set.find(obj) == set.end()) {
		//not found
		return 1;
	}
	else {

		this->set.erase(obj);
		return 0;
	}
}


std::set<string> SimpleFileSystem::getFileNames() {
	std::set<string> names;
	std::string fileName;
	for (auto it = this->map.cbegin(); it != this->map.cend(); it++) {
		fileName = (*it).first;
		names.insert(fileName);
	}
	return names;
}