#include <image.h>
#include <source.h>
#include <stdlib.h>
Source::Source(){
	im = new Image;
}
Source::~Source(){
	delete im;
}
void Source::UpdatePipe(){
	this->Execute();
	
}
