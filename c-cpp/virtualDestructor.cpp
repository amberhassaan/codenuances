#include "util.h"

using namespace std;

// we construct a class hierarchy
// base class does not declare destructor virtual
// derived class does not call base class constructor/destructor explicitly
struct BaseA {
  BaseA () {
    cout << "BaseA constructor" << endl;
  }

  ~BaseA () {
    cout << "BaseA destructor" << endl;
  }

};


// don't call any base constructor destructor explicitly
struct DerivedA: public BaseA {
  DerivedA () {
    cout << "DerivedA constructor" << endl;
  }

  ~DerivedA () {
    cout << "DerivedA destructor" << endl;
  }
};


// test to see when BaseA destructor gets called
// expected: BaseA constructor gets called automatically
// DerivedA destructor gets called only when declared type is 
// DerivedA, while BaseA destructor always gets called
void testDerivedA () {
  cout << "<<< testDerivedA >>>" << endl;
  BaseA* b = new BaseA();
  cout << "==============" << endl;

  BaseA* d0 = new DerivedA();
  cout << "==============" << endl;

  DerivedA* d1 = new DerivedA();
  cout << "==============" << endl;

  delete b;
  cout << "==============" << endl;

  delete d0;
  cout << "==============" << endl;

  delete d1;
  cout << "==============" << endl;
}

struct DerivedB: public BaseA {
  DerivedB () {
    cout << "DerivedB constructor" << endl;
  }
  virtual ~DerivedB () {
    cout << "DerivedB destructor" << endl;
  }
};

// test to see if declaring DerivedB destructor 
// virtual makes BaseA destructor virtual
// result: BaseA destructor does not become virtual
// and DerivedA destructor does not get called at all
void testDerivedB () {
  cout << "<<< testDerivedB >>>" << endl;

  BaseA* b = new BaseA();
  cout << "==============" << endl;

  BaseA* d0 = new DerivedB();
  cout << "==============" << endl;

  delete b;
  cout << "==============" << endl;

  delete d0;
  cout << "==============" << endl;
}


struct BaseC {
  BaseC () {
    cout << "BaseC constructor" << endl;
  }

  virtual ~BaseC () {
    cout << "BaseC destructor" << endl;
  }

};


struct DerivedC: public BaseC {
  DerivedC () {
    cout << "DerivedC constructor" << endl;
  }

  ~DerivedC () {
    cout << "DerivedC destructor" << endl;
  }
};

struct DoubleDerivedC: public DerivedC {
  DoubleDerivedC () {
    cout << "DoubleDerivedC constructor" << endl;
  }

  ~DoubleDerivedC () {
    cout << "DoubleDerivedC destructor" << endl;
  }
};
// now BaseC has a virtual destructor and
// every class e.g. DerivedC inheriting BaseC 
// will get a virtual Destructor whether it 
// declares its destructor as virtual or not
// e.g. look how DoubleDerivedC is constructed and destroyed
// and declared pointer type for DoubleDerivedC does not matter in 
// this case
void testDerivedC () {
  cout << "<<< testDerivedC >>>" << endl;

  BaseC* b = new BaseC();
  cout << "==============" << endl;

  BaseC* d0 = new DerivedC();
  cout << "==============" << endl;

  BaseC* d1 = new DoubleDerivedC();
  cout << "==============" << endl;

  DerivedC* d2 = new DoubleDerivedC();
  cout << "==============" << endl;

  delete b;
  cout << "==============" << endl;

  delete d0;
  cout << "==============" << endl;

  delete d1;
  cout << "==============" << endl;

  delete d2;
  cout << "==============" << endl;
}


int main (int argc, char* argv[]) {
  testDerivedA ();
  testDerivedB ();
  testDerivedC ();
  return 0;
}
