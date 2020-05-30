// studio 18 - simple file factory definitions
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"

using namespace std;

class TextFile;
class ImageFile;
class AbstractFile;


AbstractFile* SimpleFileFactory::createFile(std::string name) {
		//not found
		string txt = ".txt";
		string img = ".img";
		if (name.find(txt) != std::string::npos) {
			AbstractFile* file;
			file = new TextFile(name);
			return file;
		}
		if (name.find(img) != std::string::npos) {
			AbstractFile* file;
			file = new ImageFile(name);
			return file;

		}
		else {
			return nullptr;
		}
	return nullptr;
}
