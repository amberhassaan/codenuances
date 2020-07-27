#include <iostream>
#include <algorithm>
#include <iterator>

#include "util.h"

struct A {

  static const size_t N = 4;

  int vec[N];
  int matrix[N][N];

  A (int fillVal) {
    std::fill (vec, vec + N, fillVal);

    for (size_t i = 0; i < N; ++i) {
      std::fill (matrix[i], matrix[i] + N, fillVal);
    }
  }


  void print () const {
    std::cout << "vec = [ ";
    std::copy (vec, vec + N, std::ostream_iterator<int> (std::cout, ", "));
    std::cout << "]" << std::endl;

    std::cout << "matrix = [ "; 
    for (size_t i = 0; i < N; ++i) {
      std::cout << "[ ";
      std::copy (matrix[i], matrix[i] + N, std::ostream_iterator<int> (std::cout, ", "));
      std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
  }

};


int main (int argc, char* argv[]) {
  A a(1);
  
  a.print ();

  DB (sizeof (a));

  A b(2);
  b = a;
  b.print ();

  A c(a);
  c.print ();

}
