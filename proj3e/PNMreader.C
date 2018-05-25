#include <PNMreader.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
PNMreader::PNMreader(char *filename){
	int i = 0;
	int len = strlen(filename);
	buffer = new char[len+1];	
	for(; i<len; i++){
		buffer[i] = filename[i];
	}
	buffer[i] = '\0';
	this->im->setUP(this);
}

PNMreader::~PNMreader(void){
	delete [] buffer;

}

void PNMreader::Execute(void){
	char *magicNum = new char[8];
	int width, height, maxval, i;
	FILE *f_in=fopen(this->buffer, "r");
	if (f_in == NULL){	
		fprintf(stderr, "could not open input file\n");
		exit(1);
	}
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);  
 	Pixel * pix=(Pixel *) new Pixel[width*height];
	this->im->setPixels(pix);
	this->im->setW(width);
	this->im->setH(height);
	fread(this->im->getPixels(), sizeof(Pixel), width*height, f_in);
	fclose(f_in);
}

