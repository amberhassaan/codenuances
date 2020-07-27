#include "util.h"

template <typename T>
void OK (T x) {
}

template <typename T>
void notOK (T& x) {
}


class A {
};


template <typename T>
struct Wrap {
  T x;

  Wrap (T x): x (x) {}

  operator const T& () const {
    return x;
  }
};


int main () {


  // Wrap<int> x (0);
  const int x = 0;

  OK<int> (x);

  notOK<int> (x);

  return 0;
}


