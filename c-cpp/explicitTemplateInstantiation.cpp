#include "explicitTemplateInstantiation.h"

template <typename T>
MyClass<T> MyClass<T>::Make(const T& v) {
  return MyClass<T>{v};
}

template class MyClass<int>;
template class MyClass<double>;
