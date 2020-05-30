// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
class TextFile;
class ImageFile;

void BasicDisplayVisitor::visit_TextFile(TextFile* a) {
	TextFile* file = a;
	std::string get;
	for (unsigned int i = 0; i < a->contents.size(); i++) {
		get += a->contents[i];
	}
	cout << get << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* img) {
	ImageFile* file = img;

	for (unsigned int i = img->size; i >= 1; i--) {
		for (int j = 0; j < img->size; j++) {
			unsigned int index = ((i - 1) * img->size) + j;
			cout << img->contents[index];

		}
		cout << endl;
	}
}


