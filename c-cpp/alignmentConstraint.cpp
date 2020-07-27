#include "util.h"

#define ALIGN __attribute ((aligned (64)))

struct A {
  int x ALIGN;
};

struct B {
  A a;
  char y;
};

struct C {
  // int x ALIGN;
  ALIGN char x;
  char y[60];
};

struct D {
  char y[60];
  int x ALIGN;
};

int main () {

  DB (sizeof (A));
  DB (sizeof (B));
  DB (sizeof (C));
  DB (sizeof (D));

  C c;

  DB (&(c.y[0]) - &(c.x)) ;

  return 0;
}

// conclustions:
// - Alignment constraints are not exposed outside the class, e.g., in struct B,
//   a member of type A is seen as size 64 (alignments size)
// - As seen in struct C, Alignment attribute can be used on first member of the
//   class in order to enforce alignment of the whole class, but, save space by
//   minimizing padding,
// - As seen in struct D, extra padding is added to the class to enforce the
//   most stringent alignment constraint of one of its members
// - Also seen in struct D is that compiler does not re-order members of the struct
