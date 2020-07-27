#include "util.h"
#include "Base.h"
#include "Derived.h"


int main (int argc, const char* argv[]) {
  Derived1<3> d;
  DB (d.f ());
}
