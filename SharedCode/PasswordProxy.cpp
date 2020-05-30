#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include "AbstractFile.h"
#include "PasswordProxy.h"

class AbstractFile;
class TextFile;
class ImageFile;


PasswordProxy::PasswordProxy(AbstractFile* f, std::string n) {
	this->file = f;
	this->password = n;
}

PasswordProxy::~PasswordProxy() {
	delete this->file;
}

string PasswordProxy::passwordPrompt() {
	std::string get ="";
	cout << "Please enter the password for the file" << endl;
	std::getline(std::cin, get);
	return get;
}

vector<char> PasswordProxy::read() {
	std::string pass = this->passwordPrompt();
	if (pass == this->password) {
		return this->file->read();
	}
	else {
		std::vector<char> v;
		return v;
	}
}


int PasswordProxy::write(std::vector<char> v) {
	std::string pass = this->passwordPrompt();
	if (pass == this->password) {
		return this->file->write(v);
	}
	else {
		return 1;
	}
}

int PasswordProxy::append(std::vector<char> v) {
	std::string pass = this->passwordPrompt();
	if (pass == this->password) {
		return this->file->append(v);
	}
	else {
		return 1;
	}
}


unsigned int PasswordProxy::getSize() {
	return this->file->getSize();
}


std::string PasswordProxy::getName() {
	return this->file->getName();
}


void PasswordProxy::accept(AbstractFileVisitor* file) {
	std::string pass = this->passwordPrompt();
	if (pass == this->password) {
		return this->file->accept(file);
	}
}

AbstractFile* PasswordProxy::clone(std::string name) {
	PasswordProxy* poi = new PasswordProxy(this->file->clone(name),this->password);
	return poi;
}