/*
	Author: John Nemeth
	Description: header file for sink.c
	Sources: Class material
*/
#ifndef SINK_H
#define SINK_H

#include <image.h>

class Sink
{
	public:
		Sink();
		virtual ~Sink();

		//virtual void Write(char *) = 0; // pure virtual function (forces instantiation
						//	only by derived class)

		void SetInput(Image *);		// sets image pointer to input1
		void SetInput2(Image *);	// sets image pointer to input2
	protected:
		Image * input1;
		Image * input2;
};
#endif
