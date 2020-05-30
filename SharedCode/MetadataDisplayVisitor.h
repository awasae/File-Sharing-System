#pragma once
// declaration of MetadataDisplayVisitor here

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
class AbstractFileVisitor;

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
	
};