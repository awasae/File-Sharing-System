// definitions of metadata visitor here
#include "BasicDisplayVisitor.h"
#include "MetadataDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
class TextFile;
class ImageFile;

void MetadataDisplayVisitor::visit_TextFile(TextFile* a) {
	TextFile* file = a;
	std::string name;
	std::string type;
	std::string data;
	name = a->getName();
	type = "text";
	data = to_string(a->getSize());
	cout << name + ' ' + ' ' + '\t'+ type + ' '+ ' ' + '\t' + data << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img) {
	ImageFile* file = img;
	std::string name;
	std::string type;
	std::string data;
	name = file->getName();
	type = "image";
	data = to_string(file->getSize());
	cout << name + ' ' + ' ' + '\t' + type + ' ' + ' ' + '\t' + data << endl;

}
