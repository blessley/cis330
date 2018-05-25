/*	Author: John Nemeth
	Description: implementation file for image class
	Sources: class material
*/

#include <string.h>
#include <image.h>

// constructor/destructors ///////////////////////////////////////////////////
Image::Image() {
	width = 0;
	height = 0;
	maxColorVal = 0;
	magicNum = NULL;
	pBuffer = NULL;
}

// parameterized constructor (used in halfsize, leftright & topdown combine)
Image::Image(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
	maxColorVal = 0;
	magicNum = new char[CHAR_BUFFER];
	pBuffer = new Pixel[width * height];
}

// copy constructor (essentially copies image)
Image::Image(const Image &anImage) {
	width = anImage.width;
	height = anImage.height;
	maxColorVal = anImage.maxColorVal;
	magicNum = new char[CHAR_BUFFER];
	strcpy(magicNum, anImage.magicNum);
	pBuffer= new Pixel[anImage.width * anImage.height];
	int numPixels = width * height;
	for (int i = 0; i < numPixels; i++) {
		pBuffer[i] = anImage.pBuffer[i];
	}
}

// assignment operator overloader (correctly copies image data to new image)
const Image& Image::operator=(const Image& anImage) {
	if (this == &anImage)
		return *this;
	else
	{
		width = anImage.width;
		height = anImage.height;
		maxColorVal = anImage.maxColorVal;
		if (magicNum)
			delete[] magicNum;
		if (pBuffer)
			delete[] pBuffer;
		magicNum = new char[CHAR_BUFFER];
		strcpy(magicNum, anImage.magicNum);
		pBuffer = new Pixel[anImage.width * anImage.height];
		int numPixels = width * height;
		for (int i = 0; i < numPixels; i++) {
			pBuffer[i] = anImage.pBuffer[i];
		}
	}
}

// destructor
Image::~Image() {
	if (magicNum)
		delete[] magicNum;
	if (pBuffer)
		delete[] pBuffer;
}

void Image::setWidth(int w) {
	width = w;
}

void Image::setHeight(int h) {
	height = h;
}

void Image::setMaxColor(int m) {
	maxColorVal = m;
}

void Image::setMagicNum(char * aMagicNum) {
	if (magicNum)
		delete[] magicNum;
	magicNum = aMagicNum;
}

void Image::setPBuffer(Pixel * aPBuffer) {
	if (pBuffer)
		delete[] pBuffer;
	pBuffer = aPBuffer;
}

int Image::getWidth() {
	return width;
}

int Image::getHeight() {
	return height;
}

int Image::getMaxColor() {
	return maxColorVal;
}

char * Image::getMagicNum() {
	return magicNum;
}

Pixel * Image::getPBuffer() {
	return pBuffer;
}
