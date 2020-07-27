#include "util.h"

// Compiler calls const and non-const versions of the same function 
// depending on the type of the calling object rather than the calling
// context

struct TypeA {
  int m_x;

  TypeA (int x): m_x (x) {};

  int& getX () { 
    std::cout << "Calling non-const" << std::endl;
    return m_x; 
  }

  const int& getX() const {
    std::cout << "Calling const" << std::endl;
    return m_x;
  }
};


int main (int argc, char* argv[]) {
  const TypeA a(4);

  // a.getX () += 3;

  int y = a.getX ();

  std::cout << "a.m_x = " << a.getX () << std::endl;

  return 0;

}
