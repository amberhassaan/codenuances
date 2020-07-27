#include <iostream>

template <typename T>
void fimpl (T args, int t1) {
  std::cout << "Calling First implementation " << std::endl;
}

template <typename T>
void fimpl (T args, char t2) {
  // implementation 2;
  std::cout << "Calling Second implementation " << std::endl;
}


template <typename T>
void f (T args) {
  typedef typename T::trait MyTrait;

  fimpl (args, MyTrait ());
}


class A {
public:
  typedef int trait;
};

class B {
public:
  typedef char trait;
};


int main () {

  A a;

  B b;

  f (a);
  f (b);

  return 0;
}
