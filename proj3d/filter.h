/*
	Author: John Nemeth
	Description: header file for image manipulator classes
*/
#ifndef FILTER_H
#define FILTER_H

#include <source.h>
#include <sink.h>

class Filter : public Source, public Sink
{
	protected:
		void checkInputs();
		void setImage(int, int, int, char *, Pixel *);
};

class Shrinker : public Filter
{
	public:
		virtual void Execute();
};

class LRCombine : public Filter
{
	public:
		virtual void Execute();
};

class TBCombine : public Filter
{
	public:
		virtual void Execute();
};

class Blender : public Filter
{
	public:
		// constructor/destructors
		Blender();
		Blender(double);		// parameterized constructor
		virtual ~Blender();

		// methods
		void SetFactor(double);
		virtual void Execute();
	private:
		double factor;
};
#endif
