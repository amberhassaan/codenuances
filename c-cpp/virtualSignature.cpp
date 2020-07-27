#include "util.h"
#include <cstdio>

struct A {
};

struct B: public A {
};


struct S {
};

struct T: public S {
};


struct Base {
  virtual S doit (const A& x) {
    std::cout << "Base(A)" << std::endl;
    return S();
  }

};

struct Derived: public Base {
  virtual S doit (const B& x) {
    std::cout << "Derived(B)" << std::endl;
    return T();
  }
};


int main () {

  typedef S (Base::*BaseFunc) (const A&);
  typedef S (Derived::*DerivedFunc) (const B&);

  BaseFunc fb = &Base::doit;

  DerivedFunc fd = &Derived::doit;

  printf ("Base::doit == %x\n", fb);
  printf ("Derived::doit == %x\n", fd);

  Base* b0 = new Base ();
  Base* b1 = new Derived ();
  Derived* d0 = new Derived ();

  int** b0_vptr = reinterpret_cast<int**> (b0);
  int** b1_vptr = reinterpret_cast<int**> (b1);
  int** d0_vptr = reinterpret_cast<int**> (d0);

  printf ("Base::doit == %x\n", **b0_vptr);
  printf ("Derived::doit == %x\n", **b1_vptr);
  printf ("Derived::doit == %x\n", **d0_vptr);


  S s0 = b0->doit (A ());

  S s1 = b1->doit (B ());


  // T* t0 = b1->doit (B ());

  S s2 = d0->doit (B ());



  delete b0;
  delete b1;
  delete d0;

  return 0;
}


// 1. The return type of virtual function in derived should be a sub-type of
// the return type of virtual function in Base. But this works only for pointers
// and references. Not for returning copy
