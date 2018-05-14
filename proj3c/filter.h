#include <sink.h>
#include <source.h>

#ifndef FILTER330
#define FILTER330

class Filter : public Sink, public Source
{
    public:
    virtual void Execute(void) = 0;
};

class Shrinker : public Filter
{
    public:
    virtual void Execute(void);
};

class LRCombine : public Filter
{
    public:
    virtual void Execute(void);
};

class TBCombine : public Filter
{
    public:
    virtual void Execute(void);
};

class Blender : public Filter
{
    private:
    double factor;

    public:
    virtual void Execute(void);
    void SetFactor(double fact) { factor = fact; };
    double getFactor() { return factor; };
};


#endif
