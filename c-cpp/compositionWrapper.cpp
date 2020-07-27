#include "util.h"

#include <vector>
#include <algorithm>

template <typename T> 
struct Wrapper {
  T m_val;

  explicit Wrapper (const T& val): m_val (val) {}

  operator T& () { return m_val; }
  // operator T () { return m_val; }

  operator const T& () const { return m_val; }
  // operator const T () const { return 10 + m_val; }
};


int main () {

  std::vector<Wrapper<int> > v;

  for (int i = 0; i < 100; ++i) {
    v.push_back (Wrapper<int> (100 - i));
  }

  std::cout << "Before sorting" << std::endl;
  printIter (v.begin (), v.end ());

  std::sort (v.begin (), v.end (), std::less<int> ());

  std::cout << "After sorting" << std::endl;
  printIter (v.begin (), v.end ());

  DB (&v[0]);
  DB (v[0]);

  int& x = v[0];

  DB (&x);
  DB (x);

  int y = v[1];
  DB (&y);

  return 0;
}


