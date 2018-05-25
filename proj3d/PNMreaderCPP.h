/*
	Author: John Nemeth
	Description: header file for pnm reader
	Sources: class material
*/
#ifndef PNMREADERCCP_H
#define PNMREADERCCP_H

#include <source.h>

// changed name from proj3C
class PNMreaderCPP : public Source
{
	public:
		// constructor/destructors
		PNMreaderCPP();
		PNMreaderCPP(char *);			// parameterized constructor
		virtual ~PNMreaderCPP();		// virtual destructor
	
		// perform primary function
		virtual void Execute();
	private:
		char * fileName;
};

// typedefing PNMreaderCPP class in case main used in grader intentionally kept PNMreader & writer class names
typedef PNMreaderCPP PNMreader;
#endif
