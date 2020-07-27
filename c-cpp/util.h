#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <sstream>
#include <cassert>

#define DB(x) std::cout << "(" <<  #x << " = " << (x) << ")" << std::endl;

#define DB_N(x) std::cout << "(" <<  #x << " = " << (x) << ")";

#define DBOUT(out,x) out << "(" <<  #x << " = " << (x) << ")" << std::endl;

#define DBOUT_N(out,x) out << "(" << #x << " = " << (x) << ")"; 

#define FUNC __PRETTY_FUNCTION__

template <typename IterTp>
void printIter (IterTp b, IterTp e, std::ostream& out=std::cout) {
  out << "[ ";

  if (b != e) {
    out << (*b);
    ++b;
  }

  for (; b != e; ++b) {
    out << ", " << (*b);
  }

  out << " ]" << std::endl;

}

#endif // UTIL_H
