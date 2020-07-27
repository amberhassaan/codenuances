#include "util.h"

#include <vector>


class A {

public:

  int x; // does not call default constructor automatically
  int y;

  A (): y(2) {}
};


struct B {

  int z;
  A a; // always calls default constructor

  B(): z(4) {}
};

int main () {

  std::vector<double> v (10);

  // for (size_t i = 0; i < 10; ++i) {
    // std::cout << "v[i] = " << v[i] << std::endl;
  // }

  A a;

  std::cout << "a.x = " << a.x << std::endl;


  int y;

  std::cout << "y = " << y << std::endl;


  A* b = new A();

  std::cout << "b.x = " << b->x << std::endl;

  B b2;

  std::cout << "b2.a.x = " << b2.a.x << std::endl;
  std::cout << "b2.a.y = " << b2.a.y << std::endl;


  B b3;

  DB (b3.z);
  DB (b3.a.x);
  DB (b3.a.y);

  A* array = new A[10];
  for (unsigned i = 0; i < 10; ++i) {
    array[i].x = i;
    DB (array[i].x);
  }
  delete[] array;

  A* arrayB = new A[10];
  for (unsigned i = 0; i < 10; ++i) {
    DB (arrayB[i].x);
  }

  return 0;
}

// conclusion
// - Default constructor is automatically called for non-primitive types, but must 
// be called explicitly for primitive types.
// - This behavior holds true for both stack resident and heap resident objects
