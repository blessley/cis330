/*
	Author: John Nemeth
	Description: implementation file for sink.h
	Sources: Class material
*/

#include <sink.h>
#include <stdlib.h>

Sink::Sink() {
	input1 = NULL;
	input2 = NULL;
}

Sink::~Sink() {
	// since input1 and input2 only ever stay pointers, no need to deallocate anything
}

void Sink::SetInput(Image * anInput) {
	input1 = anInput;
}

void Sink::SetInput2(Image * anInput) {
	input2 = anInput;
}
