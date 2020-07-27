#include <vector>
#include <algorithm>


#include "util.h"

struct IntPtrCmp {
  bool operator () (const int* x, const int* y) const {
    return (*x) < (*y);
  }
};

int main (int argc, const char* argv[]) {

  
  int x[] = { 0, 9, 5, 8, 4, 6, 2, 1, 3, 7 };

  std::vector<int*> v;

  for (size_t i = 0; i < 10; ++i) {
    v.push_back (&x[i]);
  }

  std::sort (v.begin (), v.end (), IntPtrCmp ());

  for (size_t i = 0; i < v.size (); ++i) {
    std::cout << *v[i] << ", ";
  }
  std::cout << std::endl;

}
