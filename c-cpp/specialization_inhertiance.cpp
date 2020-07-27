#include <typeinfo>

#include "util.h"

template <typename T>
struct  BaseImpl {
  T val;

  explicit BaseImpl (const T& _val): val (_val) {}

  void print () { 
    std::cout << "Type: " << typeid (*this).name () << std:: endl;
  }
};

template <typename T>
struct Base: public BaseImpl<T> {
  explicit Base (const T& _val): BaseImpl<T> (_val) {}
};

template <typename T>
struct Base<T*>: public BaseImpl<T*> {
  explicit Base (T* _val): BaseImpl<T*> (_val) {}
};

template <typename T>
struct Base<const T*>: public BaseImpl<const T*> {
  explicit Base (const T* _val): BaseImpl<const T*> (_val) {}
};

int main () { 

  Base<int> x (1);
  x.print ();

  Base<int*> px (&(x.val));
  px.print ();


  return 0;
}
