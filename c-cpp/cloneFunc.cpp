#include <iostream>
#include <string>


#include "util.h"


using namespace std;

// Normally (e.g. in Java), the Base class declares a function
// clone, which returns a pointer to Base type. All derived classes
// override/implement the clone function keeping the same return type (i.e. Base*)
//
//
// In this hierarchy we change the return type of clone
// to be the class type implementing clone e.g. Base* in Base and Derived* in Derived.
// There is a slight advantage to this approach: when clone is called through a pointer 
// of Derived type (pointing to a Derived object of course) the return type is Derived*
// instead of Base* and can be assigned to a Derived* pointer automatically without any
// dynamic_cast 
//
struct BaseA {
  BaseA () {
    cout << "BaseA constructor" << endl;
  }

  virtual BaseA* clone() const {
    return new BaseA();
  }

  virtual const string name() const {
    return "BaseA";
  }

};

struct DerivedA: public BaseA {
  DerivedA () {
    cout << "DerivedA constructor" << endl;
  }

  virtual DerivedA* clone() const {
    return new DerivedA();
  }

  virtual const string name () const {
    return "DerivedA";
  }

};

struct DoubleDerivedA: public DerivedA {
  DoubleDerivedA () {
    cout << "DoubleDerivedA constructor" << endl;
  }

  virtual DoubleDerivedA* clone() const {
    return new DoubleDerivedA();
  }

  virtual const string name () const {
    return "DoubleDerivedA";
  }
};

// this test shows that if the declared type of calling
// pointer is Base* then return type of clone() is what was
// defined in Base class i.e. Base*, and the result of clone
// cannot be automatically assigned to Derived*
void testBaseA () {
  cout << "<<< declared type to store result of clone is base type >>>" << endl;
  BaseA* b0 = new BaseA ();
  cout << "==============" << endl;

  BaseA* b1 = new DerivedA ();
  cout << "==============" << endl;

  BaseA* b2 = new DoubleDerivedA ();
  cout << "==============" << endl;

  BaseA* b3 = b0->clone ();
  DB (b3->name ());
  cout << "==============" << endl;
  
  // The following generates a compile error
  // DerivedA* b4 = b1->clone ();
  // DB (b4->name ());

  // The following generates a compile error
  // DoubleDerivedA* b5 = b2->clone ();
  // DB (b5->name ());

  BaseA* b6 = b1->clone ();
  DB (b6->name ());
  cout << "==============" << endl;

  BaseA* b7 = b2->clone ();
  DB (b7->name ());
  cout << "==============" << endl;
  
}

// if the declared type of calling pointer is Derived* then
// return type of clone() is the same as what was defined in Derived 
// i.e. Derived*. It can be assigned automatically to Derived* or Base*
// The function called depends on the type of object the pointer is pointing to
// i.e. the type that was created using new inside clone();
void testDerived () {
  cout << "<<< declared type to store result of clone is derived type >>>" << endl;

  DerivedA* d0 = new DerivedA ();
  cout << "==============" << endl;
  DoubleDerivedA* d1 = new DoubleDerivedA();
  cout << "==============" << endl;

  DerivedA* d2 = d0->clone ();
  DB (d2->name ());
  cout << "==============" << endl;

  DoubleDerivedA* d3 = d1->clone ();
  DB (d3->name ());
  cout << "==============" << endl;

  BaseA* b0 = d0->clone();
  DB (b0->name ());
  cout << "==============" << endl;

  BaseA* b1 = d1->clone();
  DB (b1->name ());
  cout << "==============" << endl;
}

int main (int argc, char* argv[]) {
  testBaseA ();
  testDerived ();
  return 0;
}
