//  Define the TextFile class here
#include "TextFile.h"
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

TextFile::TextFile(std::string fileName) {
	this->name = fileName;
}

unsigned int TextFile::getSize() {
	return (unsigned int)this->contents.size();
}

std::string TextFile::getName() {
	return this->name;
}

int TextFile::write(std::vector<char> param) {
	this->contents.swap(param);
	return 0;
}

int TextFile::append(std::vector<char> add) {
	for (unsigned int i = 0; i < add.size(); i++) {
		this->contents.push_back(add[i]);
	}
	return 0;
}

vector<char> TextFile::read() {

	std::vector<char> v;
	for (unsigned int i = 0; i < this->contents.size(); i++) {
		v.push_back(this->contents[i]);
	}
	return v;
}

void TextFile::accept(AbstractFileVisitor* po) {
	AbstractFileVisitor* file =po;
	file->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string name) {
	TextFile* file = new TextFile(*this);
	file->name = name;
	return file;
}
