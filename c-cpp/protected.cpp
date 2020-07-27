#include "util.h"

class Derived0;

class Base {
protected: 
  int baseField0;
  double baseField1;

protected:
  void baseFunc0(void) {}

public:
  void baseFunc1 (Base& b) {
    b.baseField1 = 0.0;
  }

  void baseFunc2 (Derived0& d);


};

class Derived0: public Base {

protected:
  int derivedField0;


public:

  // can't access protected fields of b, because
  // b could actually be a reference to Derived1 instead of Derived0
  void derivedFunc0 (Base& b) {
    b.baseField0 = 0;
  }

  void derivedFunc1 (Derived0& d) {
    d.baseField0 = 1;
    d.derivedField0 = 1;
  }
};

class Derived1: public Base {
};

void Base::baseFunc2 (Derived0& d) {
  // can access base fields inherited by derived
  d.baseField0 = 0;
  // but can't access protected field of derived
  // d.derivedField0 = 1; // can't 
}

int main () {

  Base b0;

  Derived0 d0;

  Derived1 d1;

  return 0;
}

// -- base class methods can access *its* protected fields in arguments of base and
// derived
// -- derived class methods cannot access protected fields of base class in
// arguments of base type or other derived types
