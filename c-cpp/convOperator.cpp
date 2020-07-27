#include <iostream>

using namespace std;



template < typename T >
struct Wrapper {
   T val;
   Wrapper( const T& t ) : val(t) {}


   static int X;


   operator T () {
      return val;
   }

   /*
   template <typename OTH>
      operator OTH () {
         return static_cast<OTH>(val);
      }
      */

   void showX() {
      cout << "X=" << X << endl;
   }
};

template <typename T> 
int Wrapper<T>::X = 10;

template <>
int Wrapper<double>::X = 17;



int main() {

   Wrapper<int> a(3);

   int x = a;

   cout << a << endl;
   cout << x << endl;


   Wrapper<double> b(3.141);

   double d(b);

   cout << d << endl;

   int y = b;
   cout << y << endl;
   

   double d1 = a;
   cout << d1 << endl;


   b.showX();

   a.showX();

}
