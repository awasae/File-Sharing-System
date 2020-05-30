// definition of ImageFile class here

#include "ImageFile.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include "AbstractFileVisitor.h"

class AbstractFileVisitor;




using namespace std;

ImageFile::ImageFile(std::string fileName) {
	this->name = fileName;
	this->size = 0;
}

unsigned int ImageFile::getSize() {
	return this->contents.size();
}

std::string ImageFile::getName() {
	return this->name;
}

int ImageFile::write(std::vector<char> param) {
	char last = param.back();
	this->size = last-48;
	char board = last - '0';

	this->contents.clear();
	for (unsigned int i = 0; i < param.size()-1; i++) {
		this->contents.push_back(param[i]);
	}
	
	//this->contents.swap(param);
	if (contents.size() != board*board) {
		this->size = 0;
		this->contents.clear();
		return 1;
	}


	for (int i = 0; i < contents.size(); i++) {
		if (contents.at(i) != 'X') {
			if (contents.at(i) != ' ') {
				this->size = 0;
				this->contents.clear();
				return 1;
			}
		}
	}
	return 0;
}

int ImageFile::append(std::vector<char> add) {
	return 1;
}

vector<char> ImageFile::read() {
	std::vector<char> v;
	for (unsigned int i = 0; i < this->contents.size(); i++) {
		v.push_back(this->contents[i]);
	}
	return v;
	/**for (unsigned int i = this->size; i >=1; i--) {
		for (int j = 0; j < this->size; j++) {
			unsigned int index = ((i - 1) * this->size) + j;
			cout << this->contents[index];
		}
		cout << endl;
	}**/
}

void ImageFile::accept(AbstractFileVisitor* po) {
	AbstractFileVisitor* file = po;
	file->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string name) {
	ImageFile* file = new ImageFile(*this);
	file->name = name;
	return file;
}
