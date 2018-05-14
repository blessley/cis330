#include <iostream> //for cout

#include <cstdlib> //for malloc



using namespace std;



static int alloc = 0; //Number of times we call "new"
static int dealloc = 0; //Number of times we call "delete"



class MyInt
{

  public:
    MyInt() {};
    MyInt(int x) : myInt(x) {};
    int GetValue() const { return myInt; };
    void SetValue(int x) { myInt = x; }

  private:

    int myInt;

};



//Overload the "new" keyword/operator: Count num mallocs

//Should also provide bad_malloc exception handling here...

void* operator new(size_t numBytes)
{
  cout << "Allocating " << numBytes << " bytes." << endl;
  alloc++;
  return malloc(numBytes);
}



//Overload the "delete" keyword/operator: Count num deallocations

void operator delete(void* ptr)
{
  dealloc++;
  free(ptr);
}



//Overload the "<<" cout operator: Custom printing for a MyInt object

ostream& operator<<(ostream &out, const MyInt &myint)
{
  out << "MyInt(" << myint.GetValue() << ")";
  return out;
}



//Overload the "+" operator: Addition of MyInt objects

MyInt operator+(const MyInt &a, const MyInt &b)
{
  return MyInt(a.GetValue() + b.GetValue());
}



int main()
{
  MyInt a(10);
  cout << a << endl; //Using the overloaded "<<" operator



  MyInt *intArray = new MyInt[6]; //Using the overloaded "new" operator
  MyInt *b = new MyInt; //Using the overloaded "new" operator
  b->SetValue(3);


  MyInt c = a + *b; //Using the overloaded "+" operator
  cout << c << endl; //Using the overloaded "<<" operator


  delete b; //Using the overloaded "delete" operator



  //If alloc==dealloc, we have freed all allocated memory...
  cout << "alloc = " << alloc << endl;
  cout << "dealloc = " << dealloc << endl;

  return 0;
}
