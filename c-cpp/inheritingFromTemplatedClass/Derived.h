#ifndef _DERIVED_H
#define  _DERIVED_H

#include "Base.h"

template <int N>
struct Derived1: public AbsBase<N> {
  virtual int f () const;

};

#endif //  _DERIVED_H
