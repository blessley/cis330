#include <iostream>
#include <string>

using namespace std;

class MyInt
{
  public:
    //MyInt(int x) { myInt = x};
    MyInt(int x) : myInt(x) {}; 

    int GetValue() { return myInt; };

    string operator++();

    void print

  private:
    int myInt;
};


string MyInt::operator++()
{
  myInt++;
  return "Hello";
}

/*
MyInt& operator+(const MyInt &a, const MyInt &b)
{
  //Obtain and add the actual int values of a and b
  //Use the getter methods
  cout << "Adding two ints" << endl;
  return MyInt(a.GetValue() & b.GetValue());
}
*/

void* operator new(size_t numBytes)
{
  cout << "Allocating " << numBytes << " bytes." << endl;
  alloc++;
  return malloc(numBytes);
}

int main()
{
  
  //Valgrind: number of mallocs, number of frees

  MyInt *a = new MyInt;
  MyInt *b = new MyInt[4]; 

  delete a;
  delete b;
  MyInt mi(6);
  string s(++mi);
  cout << "result: " << s << endl;
  ++mi;
  cout << "mi = " << mi.GetValue() << endl;

  //MyInt other(1);
  //(++mi) + (++other);

  return 0;
}


