#include <iostream>

#include "Base.h"

using namespace std;

struct Derived: public Base {
   void doit() {
      cout << "Derived::doit()"<<endl;
   }

   ~Derived() {
      cout << "Derived destructor" << endl;
   }
};

int main() {
   Base* b = new Base;
   Base* d = new Derived;

   b->doit();
   d->doit();

   delete b;
   delete d;
}
