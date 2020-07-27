#include "util.h"
#include <string>
#include <utility>
#include <functional>

int dummy (double, double) { 
  return 1;
}

struct DummyFunctor {

  int operator () (double, double) {
    return 2;
  }
};



int main () {

  // compiles with c++ 98
  typedef int (*OldFunPtr) (double, double);

  // compiles with c++ 98
  // can remove parentheses here but not in the pointer typedef above (due to
  // ambiguity with int* f(double, double) )
  typedef int OldFun (double, double);

  OldFunPtr p0 = &dummy;

  OldFun* p1 = &dummy;

  // doesn't compile
  // OldFun f = funObj;

  
  using NewFun = int (double, double);
 
  using NewFunPtr = int (*) (double, double);

  NewFunPtr p2 = &dummy;

  NewFun* f0 = &dummy;

  // doesn't compile
  // NewFun f0 = dummy;

  DummyFunctor funObj;

  // doesn't compile
  // NewFun* d0 = &funObj;

  std::function<NewFun> sf0 = dummy;
  std::function<NewFun> sf1 = funObj;
  std::function<NewFun> sf2 = &dummy;

  DB (sf0 (0.0, 0.0));
  DB (sf1 (0.0, 0.0));
  DB (sf2 (0.0, 0.0));

  return 0;
}
