#ifndef PNM_READER
#define PNM_READER
#include <image.h>
#include <source.h>
class PNMreader : public Source{
	char *buffer;
   public:
		PNMreader(char *filename);
		virtual	~PNMreader(void);
	virtual void Execute();
};
#endif
