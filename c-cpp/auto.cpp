#include "util.h"
#include "Promote.h"

// Problem: reduce typing of return type

// Soln 1: using templated type-defs
template <typename T1, typename T2>
using Ret_ty = typename ChooseType<T1, T2>::SType; 

template <typename T1, typename T2>
Ret_ty<T1,T2> add (const T1& x, const T2& y) {
  Ret_ty<T1,T2> z = x + y;
  return z;
}

// Soln 2: using default arguments
namespace hidden {
  template <typename T1, typename T2, typename R=typename ChooseType<T1, T2>::SType>
    R add_v2 (const T1& x, const T2& y) {
      R z = x + y;
      return z;
    }
}

// Soln 3: hiding the ugliness of Soln 2 in a namespace and using auto and decltype
template <typename T1, typename T2>
auto add_v3 (const T1& x, const T2& y) -> decltype (hidden::add_v2(x,y)) {
  return hidden::add_v2 (x, y);
}

int main () {

  DB (add (3, 4.5));

  DB (hidden::add_v2 (3, 4.5));

  DB (add_v3 (3, 4.5));
}
