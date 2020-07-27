#include <iostream>
#include <vector>

#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;

struct MyEnum {
  enum _Enum {
  ONE, TWO, THREE
  };
};

int main (int argc, char* argv[]) {
  
  vector<MyEnum::_Enum> v;

  v.push_back (MyEnum::ONE);
  v.push_back (MyEnum::TWO);
  v.push_back (MyEnum::THREE);
  v.push_back (THREE);

  for (vector<MyEnum::_Enum>::const_iterator i = v.begin (); i != v.end (); ++i) {
    DB (*i)
  }


  return 0;
}
