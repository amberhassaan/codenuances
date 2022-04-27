#include <iostream>

template <typename T>
class MyClass {
  T mVar;

  explicit MyClass(const T& v) noexcept:
    mVar(v)
  {}

public:
  const T& var() const { return mVar; }

  static MyClass Make(const T& v);
};
