#include <filter.h>
#include <image.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Filter::UpdatePipe(){
	if (im1 != NULL && (im1->getUP()!= NULL)){
		im1->getUP()->UpdatePipe();
	}
	if (im2 != NULL && (im2->getUP()!= NULL)){
		im2->getUP()->UpdatePipe();
	}
	this->Execute();
	
}
Shrinker::Shrinker(){
	this->im->setUP(this);
}

void Shrinker::Execute(void){
	int w, j = 0, h =0;
	int width  = this->im1->getW();
	int height = this->im1->getH();
	this->im->ResetSize((width/2), (height/2));
	for (; h<height; h+=2){
		for (w=0; w<width; w+=2){
			this->im->getPixels()[j] = this->im1->getPixels()[(h*width)+w];
			j++;
		}
	}
}

LRCombine::LRCombine(){
	this->im->setUP(this);
}
void LRCombine::Execute(void){
	int i =0;
	int width   = this->im1->getW();
	int width2  = this->im2->getW();
	int height  = this->im1->getH();
	int height2 = this->im2->getH();
	Pixel *rightPicPtr = this->im->getPixels() + width;	
	this->im->ResetSize((width+width2), height2);
	int outWidth = this->im->getW();
	for(; i < this->im->getH(); i++){
		memcpy(this->im->getPixels()+(i*outWidth), this->im1->getPixels()+(i*width), (width * sizeof(Pixel)));
		memcpy(this->im->getPixels()+(i*outWidth)+width, this->im2->getPixels()+(i*width2), (width2 * sizeof(Pixel)));
	}
}

TBCombine::TBCombine(){
	this->im->setUP(this);
}
void TBCombine::Execute(void){
	int width   = this->im1->getW();
	int width2  = this->im2->getW();
	int height  = this->im1->getH();
	int height2 = this->im2->getH();
	this->im->ResetSize(width, (height + height2));
	int topPicSize = width*height;
		memcpy(this->im->getPixels(), this->im1->getPixels(), (width*height * sizeof(Pixel)));
		memcpy(this->im->getPixels()+topPicSize, this->im2->getPixels(), (width2*height2 * sizeof(Pixel)));	
}

Blender::Blender(){
	this->im->setUP(this);
}
void Blender::Execute(void){
	Pixel *in1Pixels = this->im1->getPixels();
	Pixel *in2Pixels = this->im2->getPixels();
	int i =0;
	this->im->ResetSize(this->im1->getW(), this->im2->getH());
	Pixel *outPixels = this->im->getPixels();
	for(; i < this->im->getH()*this->im->getW(); i++){
		outPixels[i].setR(factor*(in1Pixels[i].getR()) + remainder*(in2Pixels[i].getR()));
		outPixels[i].setG(factor*(in1Pixels[i].getG()) + remainder*(in2Pixels[i].getG()));
		outPixels[i].setB(factor*(in1Pixels[i].getB()) + remainder*(in2Pixels[i].getB()));
	}
}
