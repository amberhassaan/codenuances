#include "util.h"

struct Base {
  int a;

  virtual size_t getSize () const { return sizeof (Base); }
};

struct Derived: public Base {
  int b;
  int c;

  virtual size_t getSize () const { return sizeof (Derived); }
};


int main () {
  Base b;
  Derived d;
  Base* p = new Derived ();

  DB (sizeof (b));

  DB (sizeof (d)); 

  DB (sizeof (*p));

  DB (p->getSize ());

  return 0;
}

// sizeof returns size based on the declared type, and at compile time, of course

