#include <vector>
#include <iostream>

#define disp(x) std::cout << #x << " = " << (x) << std::endl

template < typename T > 
const T& min ( const T& x, const T& y ) {
   if( y < x ) { return y; }
   else { return x; }
}


template <template <typename E> class V> //  template <typename U> class V>
void vecprint (V<int>) {
  V<int> x;
  x.push_back (0);

  disp (x[0]);
}
;

// specialization on non argument
// full specialization allowed but partial specialization not allowed
template <bool X>
void whichVersion () {
  std::cout << "Calling true version" << std::endl;
}

template <>
void whichVersion<false> () {
  std::cout << "Calling false version" << std::endl;
}

// template <typename T, bool X>
// void partialSpecial (const T& x) {
  // std::cout << "Calling the general version" << std::endl;
// }
// 
// template <typename T>
// void partialSpecial <T, false> (const T& x) {
  // std::cout << "Calling the partially specialized version" << std::endl;
// }


template <typename T1, typename T2>
void typeArgDeduce (const std::vector<T1>& v1, const std::vector<T2>& v2) {
}



int main () {

   // disp( min ( "hello", "WorldOfPain" ) ) ; // does not compile, why?
   disp( min<char*>("hello", "World") );
   disp( min<const char*>("hello", "World") );
   disp( min<const char* const >("hello", "World") );


   disp( min(2,3) );
   disp( min<int>( 2, 3) );

   // disp( min( 2, 3.14159) ); // does not compile
   disp( min<double>(2,3.14159) ); 

   disp( min('a', 'c') );

   // anyvector< int, std::vector<int> > (0);
   // vecprint (std::vector<int> ());
   
   whichVersion<true> ();
   whichVersion<false> ();


   std::vector<int> v1 (10);
   std::vector<double> v2 (10, 1.1);

   typeArgDeduce (v1, v2);


}
