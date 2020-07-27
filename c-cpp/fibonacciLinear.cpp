#include <iostream>

#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;


// Naive Fibonacci, 2^n instantiations

/*
template <int N> 
struct Fib {
   enum { VAL = Fib<N-1>::VAL + Fib<N-2>::VAL };
};
template <>
struct Fib <1> {
   enum { VAL = 1 };
};

template <>
struct Fib <0> {
   enum { VAL = 1 };
};

*/

// Smart FibHelper, n instantiations

// t = prev
// prev = curr
// curr = t + curr

template < int count, int N, int curr, int prev >
struct FibHelper {
   enum { VAL = FibHelper< count+1, N, curr+prev, curr >::VAL };
};
template < int N, int curr, int prev> 
struct FibHelper <N,N,curr,prev> {
   enum { VAL = curr };
};

template <int N>
struct Fib {
   enum { VAL = FibHelper<0,N,1,0>::VAL };
};

// 0 3 1 0
// 1 3 1 1 
// 2 3 2 1 
// 3 3 3 2 

int main() {
   
   DB( Fib<0>::VAL );
   DB( Fib<1>::VAL );
   DB( Fib<2>::VAL );
   DB( Fib<3>::VAL );
   DB( Fib<4>::VAL );
   DB( Fib<5>::VAL );
   DB( Fib<6>::VAL );
   DB( Fib<7>::VAL );
   DB( Fib<8>::VAL );
   DB( Fib<9>::VAL );
   DB( Fib<10>::VAL );
}
