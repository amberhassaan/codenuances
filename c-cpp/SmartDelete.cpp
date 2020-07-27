#include <iostream>
#include <cstdlib>

using namespace std;

#define DB(s) std::cout << #s << " = " << (s) << std::endl;
// #define DB(x) 
// begin README
// 
// - Idea is to always put the number of objects allocated in a 4 byte header just before the 
// allocated space returned to the user. For new[] this is done automatically, in case of
// new() we put number=1 manually 
//
// - to free, you always call delete[], the compiler will look at the size in the header and call
// destructor size number of times for you.
//
// - finally we can use #define delete delete[]  and use delete everywhere instead of delete[]
// end README

// overloading operator new and delete for 
// using default new and delete inside the class
// class A
class A {
   private:
      int x;
      int y;
   public:

      A(): x(0), y(0) {
         cout << this << " Default Constructor called: " << x << ", " << y << endl;
      }

      A( int _x, int y ) {
         x=_x;
         this->y=y;
         cout << this << " Non-default Constructor called: " << x << ", " << y << endl;
      }

      friend ostream& operator << ( ostream& out, const A& a ) {
         out << &a << " A: (" << a.x << ", " << a.y << " )" << endl;
         return out;
      }
      A(const A& that ) : x(that.x), y(that.y) {
         cout << this << " Copy Constructor called, that = "  << &that << " (x,y) = " << x << ", " << y << endl;
      }

      ~A() {
         cout << this << " Destructor called "  << endl;
      }

      void* operator new (size_t n) { 
         cout << "A::new called with size = " << n << endl;
         void* p = A::operator new[]( 4+n);
         int* q = reinterpret_cast<int*>(p);
         *q=1;
         cout << " size stored as 1 at " << q << endl;
         ++q;
         cout << " returning the pointer to the user " << q << endl;
         return ( reinterpret_cast<void*>(q) );
      }

      void operator delete ( void* p ) {
         cout << "A::delete(void*) called with p = " << p << endl;
         A::operator delete(p);
      }

      void* operator new[] ( size_t n ) { 
         cout << "A::new[] called with size = " << n << endl;
         void* p = malloc(n);
         return p;
      }

      void operator delete [] ( void* p ) { 
         cout << "A::delete[] (void*) called with p = " << p << endl;
         free(p);
      }


};


int main() {
   A b(1,2);
   A* p;
   p= new A(b);
   DB(p);
   delete[] p;

   cout << "#######################################" << endl;

   A* l = new A[10]();
   DB(l);
   DB( *(reinterpret_cast<int*>(l)-1) ); // trying to see what's in the first location that the compiler keeps
   delete[] l;
   DB(l);

   cout << "#######################################" << endl;
   for( int i = 0; i < 10; ++i ) {
      A* q = new A;
      DB(q);
      delete[] q;
      cout << "#######################################" << endl;
   }

}
