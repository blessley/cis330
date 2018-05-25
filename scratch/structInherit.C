#include <cstdio>

struct SimpleID
{
  int id;
  virtual int GetId() = 0;
};

struct ComplexID : SimpleID
{
  int extraId;
  virtual int GetId() { return extraId*128+id; };
};

int main()
{
  printf("%lu\n", sizeof(bool));
  ComplexID cid;
  cid.id = 3;
  cid.extraId = 3;
  SimpleID *sid = &cid;
  printf("ID = %d\n", sid->GetId());
  return 0;
}
