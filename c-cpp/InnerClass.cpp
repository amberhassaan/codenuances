#include <iostream>

#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;

struct A {

   int x;

   struct B {
      int y;

      int getX() { return x; }
   };

   B makeB() {
      return B();
   }

};


int main() {
   A a;
   a.x = 10;

   A::B b = a.makeB();

   DB( b.getX() );


}
