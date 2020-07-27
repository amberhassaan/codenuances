#include "Derived.h"

template <int N>
int Derived1<N>::f () const { return AbsBase<N>::g (); }
