// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include "../../SharedCode/ImageFile.h" 
#include "../../SharedCode/TextFile.h" 
#include "../../SharedCode/SimpleFileSystem.h" 
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/touchCommand.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/AbstractParsingStrategy.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/GrepCommand.h"


using namespace std;

class AbastractFile;
class SimpleFileSystem;
class ImageFile;
class TextFile;
class MetadataDisplayVisitor;
class SimpleFileFactory;

int main()

{
	
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	CommandPrompt* cp = new CommandPrompt;

	AbstractFile* img	= new TextFile("File.txt");
	AbstractFile* txt	= new ImageFile("Image.img");
	AbstractFile* img1	= new TextFile("File2.txt");
	AbstractFile* txt1	= new ImageFile("Image2.img");
	AbstractFile* txt2	= new ImageFile("other.img");
	AbstractFile* txt3	= new ImageFile("other1.img");

	sfs->addFile(img->getName(),   img);
	sfs->addFile(txt->getName(),   txt);
	sfs->addFile(img1->getName(), img1);
	sfs->addFile(txt1->getName(), txt1);
	sfs->addFile(txt2->getName(), txt2);
	sfs->addFile(txt3->getName(), txt3);
	
	
	cp->setFileSystem(sfs);
	cp->setFileFactory(sff);
	// ADD COMMAND
	AbstractCommand* ct = new TouchCommand(sfs, sff);
	AbstractCommand* ct1 = new LSCommand(sfs);
	AbstractCommand* ct2 = new RemoveCommand(sfs);
	AbstractCommand* ct3 = new CatCommand(sfs);
	AbstractCommand* ct4 = new DisplayCommand(sfs);
	AbstractCommand* ct5 = new CopyCommand(sfs);
	AbstractCommand* ct9 = new GrepCommand(sfs);

	MacroCommand* ct6 = new MacroCommand(sfs);
	AbstractParsingStrategy* ct7 = new RenameParsingStrategy();
	ct6->setParseStrategy(ct7);
	ct6->addCommand(ct5);
	ct6->addCommand(ct2);


	string grep			= "grep";
	string macroCommand = "rn";
	string copy         = "copy";
	string display      = "ds";
	string cat          = "cat";
	string remove		= "rm";
	string list			= "ls";
	string touch		= "touch";

	cp->addCommand(touch, ct);
	cp->addCommand(list, ct1);
	cp->addCommand(remove, ct2);
	cp->addCommand(cat, ct3);
	cp->addCommand(display, ct4);
	cp->addCommand(copy, ct5);
	cp->addCommand(grep, ct9);
	cp->addCommand(macroCommand, ct6);
	
	cp->run();
	


	return 0;







}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
