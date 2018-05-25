/*
	Author: John Nemeth
	Description: implementation file for source.C
	Sources: Class material
*/

#include <source.h>

// primary constructor
Source::Source() {}

// destructor
Source::~Source() {}

// returns pointer to aImage data memver
Image * Source::GetOutput() {
	return &aImage;
}
