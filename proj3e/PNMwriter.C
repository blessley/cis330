#include <PNMwriter.h>
#include <stdlib.h>
#include <stdio.h>
void PNMwriter::Write(char *filename){
	FILE *f_out = fopen(filename, "w");
	if (f_out == NULL){
		fprintf(stderr, "could not open output file\n");
		exit(1);
	}
	fprintf(f_out, "P6\n%d %d\n255\n", this->getIm1()->getW(), this->getIm1()->getH());
	fwrite(this->getIm1()->getPixels(), sizeof(char), 3*this->getIm1()->getW()*this->getIm1()->getH(), f_out);
	fclose(f_out);
}
