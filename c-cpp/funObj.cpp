#include <iostream>
#include <functional>

#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;



template < typename BinFunc > 

struct A1st {

   typedef typename BinFunc::first_argument_type first_arg_t;
   typedef typename BinFunc::second_argument_type second_arg_t;
   typedef typename BinFunc::result_type result_t;

   first_arg_t fixed;

   BinFunc bf;

   A1st(  const first_arg_t& fixme, const BinFunc& _bf ) : fixed( fixme ),bf(_bf) {
   }

   result_t operator () ( const second_arg_t& t ) {
      return bf( fixed, t );
   }
};


template < typename BinFunc >
A1st<BinFunc>  makeA1st( const typename BinFunc::first_argument_type& tofix, const BinFunc& bf ) {
   return A1st<BinFunc>( tofix, bf );
}



int main() {

   negate<int> n;

   DB( n(15) );

   A1st<std::plus<int> > a0(5, std::plus<int>() );

   A1st<std::minus<double> > a1(11.11,  std::minus<double>() );

   DB( a0(6) );
   DB( a1(55.55) );
   std::plus<int> p;
   DB( makeA1st(6, p)(11) );

}
