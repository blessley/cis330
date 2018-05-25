#ifndef SOURCE
#define SOURCE

class Image;
class Source{

   protected:
	Image *im;

   public:
		Source(void);
		~Source(void);
	Image *GetOutput(void){return im;};
	virtual void Execute(void) = 0;
	virtual void UpdatePipe();
};
#endif
