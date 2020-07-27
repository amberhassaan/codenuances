#include <iostream>
#include <list>

#include "util.h"



int main () {

  typedef std::list<int> ListTy;

  ListTy l;
  ListTy m;
  
  for (int i = 0; i < 3; ++i) {
    l.push_back (i);
  }

  for (int j = 10; j < 15; ++j) {
    m.push_back (j);
  }

  printIter (l.begin (), l.end ());

  ListTy::iterator it = l.begin ();
  ++it;
  ++it;

  l.splice (l.begin (), l, it);


  printIter (l.begin (), l.end ());


  m.splice (m.end (), l);
  printIter (m.begin (), m.end ());


  return 0;
}
