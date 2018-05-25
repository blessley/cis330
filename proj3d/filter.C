/*
	Author: John Nemeth
	Description: Implementation file for filter.h
	Sources: Class material
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <filter.h>

// utility functions /////////////////////////////////////////////////////////
void Filter::checkInputs() {
	if(!input1) {
		fprintf(stderr, "input1 in sink is null!\n");
		exit(1);
	}
	if(!input2) {
		fprintf(stderr, "input2 in sink is null!\n");
		exit(1);
	}
}

// sets image of base (source) class
void Filter::setImage(int nW, int nH, int nM, char * nMN, Pixel * nPB) {
	aImage.setWidth(nW);
	aImage.setHeight(nH);
	aImage.setMaxColor(nM);
	aImage.setMagicNum(nMN);
	aImage.setPBuffer(nPB);
}

// shrinker method //////////////////////////////////////////////////////////
void Shrinker::Execute() {
	if (!input1) {
		fprintf(stderr, "Input1 in sink is null! exiting...\n");
		exit(1);
	}
	int newWidth = input1->getWidth() / 2, newHeight = input1->getHeight() / 2;
	Pixel * in1Buff = input1->getPBuffer();
	Pixel * newBuff = new Pixel[newWidth * newHeight];

	int newBIndex = 0, in1Index = 0, in1WidthMult = input1->getWidth() * 2;
	for (int i = 0; i < newHeight; i++) {
		in1Index = i * in1WidthMult;
		for (int j = 0; j < newWidth; j++) {
			newBuff[newBIndex] = in1Buff[in1Index + (j * 2)];
			newBIndex++;
		}
	}
	char * newMagicNum = new char[CHAR_BUFFER];
	strcpy(newMagicNum, input1->getMagicNum());

	setImage(newWidth, newHeight, input1->getMaxColor(), newMagicNum, newBuff);
	
}

// lrcombine method ///////////////////////////////////////////////////////////
void LRCombine::Execute() {
	checkInputs();
	if(input1->getHeight() != input2->getHeight()) {
		fprintf(stderr, "Error! Image heights must be equal to left-right combine!\n");
		exit(1);
	}
	int in1Width = input1->getWidth(), in2Width = input2->getWidth();
	int newHeight = input1->getHeight();
	Pixel * in1Buff = input1->getPBuffer();
	Pixel * in2Buff = input2->getPBuffer();
	Pixel * newPBuff = new Pixel[(in1Width + in2Width) * newHeight];
	int in1Ind = 0, in2Ind = 0, newBuffInd = 0, j;
	for (int i = 0; i < newHeight; i++) {
		for (j = 0; j < in1Width; j++) {
			newPBuff[newBuffInd] = in1Buff[in1Ind];
			newBuffInd++;
			in1Ind++;
		}
		for (j = 0; j < in2Width; j++) {
			newPBuff[newBuffInd] = in2Buff[in2Ind];
			newBuffInd++;
			in2Ind++;
		}
	}
	char * newMagicNum = new char[CHAR_BUFFER];
	strcpy(newMagicNum, input1->getMagicNum());
	setImage((in1Width + in2Width), newHeight, input1->getMaxColor(), newMagicNum, newPBuff);
}

// tbcombine class methods /////////////////////////////////////////////////
void TBCombine::Execute() {
	checkInputs();			// error checking for null input pointers
	if (input1->getWidth() != input2->getWidth()) {
		fprintf(stderr, "Error! Image widths must be equal to top-bottom combine!\n");
		exit(1);
	}
	int topPixels = input1->getWidth() * input1->getHeight();
	int botPixels = input2->getWidth() * input2->getHeight();

	Pixel * in1Buff = input1->getPBuffer();
	Pixel * in2Buff = input2->getPBuffer();
	Pixel * newPBuff = new Pixel[topPixels + botPixels];
	int outIndex = 0, i;
	for (i = 0; i < topPixels; i++) {
		newPBuff[outIndex] = in1Buff[i];
		outIndex++;
	}
	for (i = 0; i < botPixels; i++) {
		newPBuff[outIndex] = in2Buff[i];
		outIndex++;
	}
	char * newMagicNum = new char[CHAR_BUFFER];
	strcpy(newMagicNum, input1->getMagicNum());

	setImage(input1->getWidth(), (input1->getHeight() * 2), input1->getMaxColor(), newMagicNum, newPBuff);
}


// blender class methods ///////////////////////////////////////////////////
Blender::Blender() {
	factor = 0.0;
}

Blender::Blender(double aFactor) {
	factor = aFactor;
}

Blender::~Blender() {}

void Blender::SetFactor(double aFactor) {
	factor = aFactor;
}

void Blender::Execute() {
	checkInputs();

	if ((input1->getHeight() != input2->getHeight()) || (input1->getWidth() != input2->getWidth())) {
		fprintf(stderr, "Error! Height and Width must be equal to blend!\n");
		exit(2);
	}

	double rFactor = 1 - factor;
	int numPixels = input1->getHeight() * input1->getWidth();

	Pixel * oldBuff1 = input1->getPBuffer();
	Pixel * oldBuff2 = input2->getPBuffer();

	Pixel * newBuff = new Pixel[numPixels];

	for (int i = 0; i < numPixels; i++) {
		newBuff[i].red = (factor * oldBuff1[i].red) + (rFactor * oldBuff2[i].red);
		newBuff[i].green = (factor * oldBuff1[i].green) + (rFactor * oldBuff2[i].green);
		newBuff[i].blue = (factor * oldBuff1[i].blue) + (rFactor * oldBuff2[i].blue);
	}

	char * newMagicNum = new char[CHAR_BUFFER];
	strcpy(newMagicNum, input1->getMagicNum());

	setImage(input1->getWidth(), input1->getHeight(), input1->getMaxColor(), newMagicNum, newBuff);
}
