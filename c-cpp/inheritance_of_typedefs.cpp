#include "util.h"


// templated Base class
template <typename T>
struct Base {

  typedef T value_type;

  value_type x;

  Base (T _x): x (_x) {}
};





// Non-templated derived class inheriting from templated Base
// class (but bound to non-template parameter). The public typedefs become visible automatically due to inheritance.
struct DerivedA: public Base<int> {

  typedef Base<int> Super_ty;

  value_type y;

  DerivedA (value_type _x): Super_ty (_x) {};
};



// Templated Derived class inheriting from templated base class bound to
// non-template parameter.
// The public typedefs, again, become visible automatically through inheritance.
template <typename T>
struct DerivedB: public Base<int> {
  T y;

  DerivedB (value_type _x): Base<int> (_x), y () {};
};


// Templated derived and base classes. Base class bound to a template parameter of
// derived class. typedefs are not automatically visible
// and we need to specifity full path i.e. base class to access the typedefs.

template <typename T>
struct DerivedC: public Base<T> {

  typedef Base<T> Super_ty;

  typename Super_ty::value_type y;

  DerivedC (typename Super_ty::value_type _x): Super_ty (_x) {};

};



// Another example where derived has two template arguments. Again, full name 
// needs to be specified. 
template <typename T, typename U>
struct DerivedD: public Base<T> {

  typedef Base<T> Super_ty;

  U y;

  DerivedD (typename Super_ty::value_type _x): Super_ty (_x) {};
  // DerivedD (value_type _x): Super_ty (_x) {};

};

int main () {


  DerivedA da (0);

  DerivedB<int> db (0);

  DerivedC<int> dc (0);

  DerivedD<int, double> dd (0);

  return 0;
}

// IN CONCLUSION, typedefs are not automatically visible through inheritance in
// cases where base class is bound to a template parameter of derived class. If
// base class is bound to a non-template parameter (regardless of whether derived
// is templated or not), the typedefs are visible through inheritance. 
