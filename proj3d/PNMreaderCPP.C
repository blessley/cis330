/*
	Author: John Nemeth
	Description: implementation file for PNMreaderCPP.h
	Sources: class material
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <PNMreaderCPP.h>

// primary constructor
PNMreaderCPP::PNMreaderCPP() {
	fileName = NULL;
}

// parameterized constructor
PNMreaderCPP::PNMreaderCPP(char * filename) {
	fileName = new char[CHAR_BUFFER];
	strcpy(fileName, filename);
}

// destructor
PNMreaderCPP::~PNMreaderCPP() {
	if (fileName)
		delete[] fileName;
}

// using pure virtual function
void PNMreaderCPP::Execute() {
	int aWidth, aHeight, maxVal, streamLength, curStreamPtrPos;
	ifstream input;

	if (!fileName) {
		cerr << "Error! Filename not defined in PNMreaderCPP object!" << endl;
		exit(1);
	}
	input.open(fileName);
	if (!input) {
		cerr << "Error! Filename file '" << fileName << "' not found!" << endl;
		exit(1);
	}

	// finding length of stream
	input.seekg(0, input.end);
	streamLength = input.tellg();
	input.seekg(0, input.beg);

	char * aMagicNum;
	aMagicNum = new char[CHAR_BUFFER];

	// getting char and integer inputs
	input.get(aMagicNum, 3, '\n');
	input >> aWidth >> aHeight >> maxVal;
	input.ignore();

	// get current pointer position in input stream
	curStreamPtrPos = input.tellg();

	// reading in image data from beginning of pixel buffer
	Pixel * aPBuffer = new Pixel[(aWidth * aHeight)];
	input.read((char*)aPBuffer, (streamLength - curStreamPtrPos));

	aImage.setMagicNum(aMagicNum);
	aImage.setWidth(aWidth);
	aImage.setHeight(aHeight);
	aImage.setMaxColor(maxVal);
	aImage.setPBuffer(aPBuffer);

	input.close();
}
