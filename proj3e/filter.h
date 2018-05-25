#ifndef FILTER
#define FILTER
#include <sink.h>
#include <source.h>
class Filter : public Source, public Sink{
   protected:
	virtual void UpdatePipe(void);
};

class Shrinker : public Filter{
   public:
		Shrinker();
	void Execute(void);
};
class LRCombine : public Filter{
   public:
	   	LRCombine();
	void Execute(void);
};
class TBCombine : public Filter{
   public:
	   	TBCombine();
	void Execute(void);
};
class Blender : public Filter{
   	double factor;
	double remainder;
   public:
		Blender();
	void SetFactor(double f){factor = f; remainder =(1-f);};
	void Execute(void);
};
#endif
