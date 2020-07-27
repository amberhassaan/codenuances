#include "util.h"

#include <typeinfo>


template <typename T> 
struct GiveType {
  typedef T Type;
};

template <typename T>
class TypeB {
  friend class GiveType<T>::Type;
  typedef T FrndTy;
};

class TypeA {
public:
  typedef TypeB<TypeA>::FrndTy FrndTy;
};




int main (int argc, char* argv[]) {
  TypeB<TypeA> b;
  TypeA a;

  DB (typeid (TypeA::FrndTy ()).name ());

}
