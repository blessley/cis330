/*
	Author: John Nemeth
	Description: header file for PNMwriterCPP
	Sources: Class material
*/
#ifndef PNMWRITERCPP_H
#define PNMWRITERCPP_H

#include <sink.h>

// changed class name from proj3C
class PNMwriterCPP : public Sink
{
	public:
		PNMwriterCPP();
		virtual ~PNMwriterCPP();

		// derived function 
		virtual void Write(char *);
};

// typdefing PNMwriterCPP in case of main intentionally keeping PNMreader and PNMwriter class names
typedef PNMwriterCPP PNMwriter;
#endif
