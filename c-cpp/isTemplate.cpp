
#include <iostream>
#include <string>
#include <vector>
#include <complex>


using namespace std;

#define DB(x) std::cout << #x << " = " << (x) << std::endl;

template< typename X>
struct IsTemplate {
   enum {ANSWER = false };
};

template< typename X, template <typename> class T >
struct IsTemplate< T<X> > {
   enum { ANSWER = true };
};

template <typename X>
struct IsTemplate2 {
   enum {ANSWER = false };
};

template <typename X, typename Y, template <typename,typename> class T >
struct IsTemplate2< T<X,Y> > {
   enum {ANSWER = true };
};


int main() {
   /*
   cout << IsTemplate<string,string>::ANSWER  << endl;;
   cout << IsTemplate<int,int>::ANSWER  << endl;
   cout << IsTemplate< vector<int>, int >::ANSWER << endl ;
   cout << IsTemplate< int, vector<int> >::ANSWER  << endl;
   */

   DB( IsTemplate<int>::ANSWER );
   DB( IsTemplate< vector<int> >::ANSWER );
   DB( IsTemplate< vector< complex<int> > >::ANSWER );
   DB( IsTemplate< string >::ANSWER );
}

