#include <iostream>

#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;


/*
template <int N > 
struct Factorial {
   enum {
      VAL= N*Factorial<N-1>::VAL
   };
};

template <> 
struct Factorial<1> {
   enum {
      VAL=1
   };
};

*/

/*
template <int N>
struct Factorial {
   static const int VAL=N*Factorial<N-1>::VAL;
};

template <> 
struct Factorial<1> {
   static const int VAL=1;
};

*/



int main() {

   DB( Factorial<1>::VAL );
   DB( Factorial<4>::VAL );
}
