#include "util.h"

// notOK should give compiler error
// OK should compile fine
template <typename T>
void OK (T x) {}

template <typename T>
void notOK (T& x) {}

class T {
};

class Wrapper {
  T mem;
public:
  Wrapper () {}
  Wrapper (const T& x) {}
  operator T () const { return mem; }
};

int main () {
  // const T& x = T();
  // `const T x;
  // T x;
  //
  Wrapper x;

  OK<T> (x);

  notOK<T> (x);

  return 0;
}

// solutions
// 1. declare T x as const or const reference
// 2. create a Wrapper with converstion operator of copy type T (not ref type T&)

