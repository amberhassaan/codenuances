#include <iostream>
#include <string>
#include <sstream>

#include "util.h"

using namespace std;

struct Base {
  static int counter;

  int b;

  Base () {
    cout << "Base constructor" << endl;
    b = counter;
    ++counter;
    DB (this->toStr ());
  }

  Base (const Base& that): b(that.b) {
    cout << "Base copy-constructor" << endl;
    DB (this->toStr ());
    DB (that.toStr ());
  }

  Base& operator = (const Base& that) {
    cout << "Base assignment operator = " << endl;
    b = that.b;
    DB (this->toStr ());
    DB (that.toStr ());
    return (*this);
  }

  virtual const string toStr () const {
    stringstream ss;
    ss << "Base::this = " << this << " b = " << b << endl;
    return ss.str();
  }
};

int Base::counter = 0;

struct DerivedA: public Base {

  DerivedA () {
    cout << "DerivedA constructor" << endl;
    DB (this->toStr ());
  }

  DerivedA (const DerivedA& that) {
    cout << "DerivedA copy-constructor" << endl;
    DB (this->toStr ());
    DB (that.toStr ());
    
  }

  DerivedA& operator = (const DerivedA& that) {
    cout << "DerivedA assignment operator = " << endl;
    DB (this->toStr ());
    DB (that.toStr ());
  }

  virtual const string toStr () const {
    return "DerivedA " + Base::toStr ();
  }
};

// this test shows that when we define copy-constructor and assignment operator in
// DerivedA , DerivedA class does not automatically call the Base 
// class copy-constructor or assignment operator. The default Base constructor 
// is called during construction.
void testDerivedA () {
  cout << "<<< testDerivedA: no explicit calls to copy constructor or assignment operator >>>" << endl;

  Base b0;
  cout << "===================" << endl;

  DerivedA d0;
  cout << "===================" << endl;

  DerivedA d1(d0);
  cout << "===================" << endl;
  
  DerivedA d2;
  cout << "===================" << endl;

  d2 = d0;
  cout << "===================" << endl;

  b0 = d0;
  cout << "===================" << endl;

  // following does not compile
  // unless we define an assignment operator in Derived that takes
  // as argument a reference to Base
  // d1 = b0;
  
  // Similarly the following is a compile error
  // because no constructor of the form Derived (const Base&) has been defined
  // DerivedA d3(b0);
}


// now we don't define copy-constructor
// and assignment operator in order to see the
// default behavior of C++
struct FA {
  static int counter;

  int t;

  FA(): t(counter) {
    ++counter;
    cout << "FA constructor" << endl;
  }

  FA (const FA& that): t(that.t) {
    cout << "FA copy-constructor" << endl;
  }

  FA& operator = (const FA& that) {
    t = that.t;
    cout << "FA assignment operator" << endl;
    return *this;
  }

  const string toStr () const {
    stringstream ss;
    ss << "FA::this = " << this << ", t = " << t << endl;
    return ss.str ();
  }

};
int FA::counter = 0;

struct DerivedB: public Base {

  FA f;
  DerivedB (): f() {
    cout << "DerivedB constructor" << endl;
    DB (this->toStr ());
  }

  virtual const string toStr () const {
    stringstream ss;
    ss << "DerivedB::this = " << this << ", f = " << f.toStr () << endl;
    return Base::toStr () + ss.str () ;
  }
  
};

// this test shows that C++ by default defines copy-constructor and assignment operators
// for Derived class that understand inheritance
// - Base class copy-constructor is called before Derived class copy-constructor. The default
// implementation of copy constructor performs shallow copy
// - Base class assignment operator is called before Derived class assignment operator. The
// default implementation of assignment operator performs shallow assignment
//
// 
void testDerivedB () {
  cout << "<<< testDerivedB: copy-constructor and assignment operator in DerivedB are not defined by user >>>" << endl;

  Base b0;
  DB (b0.toStr ());
  cout << "===================" << endl;

  DerivedB d0;
  DB (d0.toStr ());
  cout << "===================" << endl;

  DerivedB d1(d0);
  cout << ">>> after calling copy constructor of DerivedB d1(d0)" << endl;
  DB (d1.toStr ());
  cout << "===================" << endl;
  
  DerivedB d2;
  DB (d2.toStr ());
  cout << "===================" << endl;

  cout << ">>> before calling assignment operator d2 = d0" << endl;
  DB (d0.toStr ());
  DB (d2.toStr ());
  d2 = d0;
  cout << ">>> after calling assignment operator d2 = d0" << endl;
  DB (d0.toStr ());
  DB (d2.toStr ());
  cout << "===================" << endl;

  cout << ">>> before calling assignment operator b0 = d0" << endl;
  DB (d0.toStr ());
  DB (b0.toStr ());
  b0 = d0;
  cout << ">>> after calling assignment operator b0 = d0" << endl;
  DB (d0.toStr ());
  DB (b0.toStr ());
  cout << "===================" << endl;

}

// now we make explicit calls to Base copy-constructor
// and assignment operators

struct DerivedC: public Base {
  static int counter;

  int c;

  DerivedC (): Base(), c(counter) {
    ++counter;
    cout << "DerivedC constructor" << endl;
    DB (this->toStr ());
  }

  DerivedC (const DerivedC& that): Base(that), c(that.c) {
    cout << "DerivedC copy-constructor" << endl;
    DB (this->toStr ());
    DB (that.toStr ());
  }

  DerivedC& operator = (const DerivedC& that) {
    Base& b = Base::operator = (that);
    // default behavior is to return a reference to 'this', which is the lvalue of the assignment
    DB (&b == this);
    c = that.c;

    cout << "DerivedC assignment operator" << endl;
    DB (this->toStr ());
    DB (that.toStr ());
    
    return (*this);
  }

  virtual const string toStr () const {
    stringstream ss;
    ss << "DerivedB::this = " << this << ", c = " << c << endl;
    return Base::toStr () + ss.str () ;
  }

};

int DerivedC::counter = 0;

void testDerivedC () {
  cout << "<<< testDerivedC: copy-constructor and assignment operator in DerivedC (almost correctly)" <<
    "defined by user >>>" << endl;

  Base b0;
  DB (b0.toStr ());
  cout << "===================" << endl;

  DerivedC d0;
  DB (d0.toStr ());
  cout << "===================" << endl;

  DerivedC d1(d0);
  cout << ">>> after calling copy constructor of DerivedC d1(d0)" << endl;
  DB (d1.toStr ());
  cout << "===================" << endl;
  
  DerivedC d2;
  DB (d2.toStr ());
  cout << "===================" << endl;

  cout << ">>> before calling assignment operator d2 = d0" << endl;
  DB (d0.toStr ());
  DB (d2.toStr ());
  d2 = d0;
  cout << ">>> after calling assignment operator d2 = d0" << endl;
  DB (d0.toStr ());
  DB (d2.toStr ());
  cout << "===================" << endl;

  cout << ">>> before calling assignment operator b0 = d0" << endl;
  DB (d0.toStr ());
  DB (b0.toStr ());
  b0 = d0;
  cout << ">>> after calling assignment operator b0 = d0" << endl;
  DB (d0.toStr ());
  DB (b0.toStr ());
  cout << "===================" << endl;

}

int main (int argc, char* argv[]) {
  testDerivedA ();
  testDerivedB ();
  testDerivedC ();
  return 0;
}
