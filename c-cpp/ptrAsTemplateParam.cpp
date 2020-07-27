#include "util.h"

#include <vector>

struct AType {
  friend std::ostream& operator << (std::ostream& out, const AType& a) {
    out << "AType";
    return out;
  }
};

template <const AType* const& ptrA>
struct BType {
  const AType& getAType () {
    return *ptrA;
  }
};

struct CType {
  static const AType* const A; // = new AType();
};
const AType* const CType::A = new AType ();


template <const std::vector<int>* const& V>
struct DType {
  const std::vector<int>& getVec () const {
    return *V;
  }
};

std::vector<int> makeVec (int N) {
  std::vector<int> v;
  for (int i = 0; i < 10; ++i) {
    v.push_back (i);
  }
  return v;
}

int main (int argc, char* argv[]) {
  BType<CType::A> b;
  DB (b.getAType ());


  std::vector<int> v = makeVec (10);
  const std::vector<int>* const vptr = &v;
  DType<vptr> d;
}
