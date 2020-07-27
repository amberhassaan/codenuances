#include <vector>
#include <iostream>
#include <string>

#include "util.h"

template <typename T, size_t N, bool small> 
class SmallVecImpl {
  T data[N];

public:
  std::string name () const { return "Array"; }
};

template <typename T, size_t N>
class SmallVecImpl<T, N, false> : public std::vector<T> {
public:
  std::string name () const { return "std::vector"; }
};

template <typename T, size_t N, size_t LIM=32>
class SmallVec: public SmallVecImpl<T, N, N <= LIM> {
};

int main (int argc, char* argv[]) {
  SmallVec<int, 24> small;

  DB (small.name ());

  SmallVec<int, 1024> big;


  DB (big.name ());
}
