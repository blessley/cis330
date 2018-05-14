
class Sink
{
  private:
    int *data;

  public:
    Sink() : data(NULL) {};
    Sink(int *d) : data(d) {};
    Sink(const int *);
    int * GetData();





}
