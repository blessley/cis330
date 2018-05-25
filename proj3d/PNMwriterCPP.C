/*
	Author: John Nemeth
	Description: implementation file for PNMwriterCPP.h
	Sources: Class material
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <PNMwriterCPP.h>

PNMwriterCPP::PNMwriterCPP() {}

PNMwriterCPP::~PNMwriterCPP() {}

void PNMwriterCPP::Write(char * filename) {
	if (!filename) {
		cerr << "Error! No filename passed as 2nd argument!" << endl;
		exit(1);
	}
	int width = input1->getWidth();
	int height = input1->getHeight();
	int numPixels = width * height;
	int maxVal = input1->getMaxColor();
	char * magicNum = input1->getMagicNum();

	ofstream output;
	output.open(filename);

	Pixel * pBuff = input1->getPBuffer();

	output << magicNum << "\n" << width << " " << height << "\n" << maxVal << "\n";
	char * buffPtr = (char*)pBuff;
	for (int i = 0; i < (numPixels * 3); i++) {
		output.put(*buffPtr);
		buffPtr++;
	}
	output.close();
}
