/*
	Author: John Nemeth
	Description: header file for source.c
	Sources: class material
*/
#ifndef SOURCE_H
#define SOURCE_H

#include <image.h>

class Source
{
	public:
		// constructor/destructors
		Source();
		virtual ~Source();
		
		virtual void Execute(void) = 0;	// pure virtual function (forces instantiation
						// 	only by derived classes)
		Image * GetOutput();		// method to return image pointer

	protected:
		Image aImage;			// public data member image
};
#endif
