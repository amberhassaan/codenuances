#include <iostream>
#include <cstdlib>

using namespace std;

// #define DB(s) std::cout << #s << " = " << (s) << std::endl;
#define DB(x) 
// begin README
//
// - There is global new and delete operators, see new header file
// - For classes new and delete are static class memebers
// - non-default constructor cannot be called with new[] array
// - for arrays c++ allocates 4 bytes in the beginning where the size of the array is kept
// - with new first raw storage is allocated, followed by constructor call, overloading
// only changes the raw storage allocation
// - delete first calls the constructor and then calls the delete operator by passing
// the void pointer
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
         return  ::operator new(n); // calling default new
      }

      void operator delete ( void* p ) {
         cout << "A::delete(void*) called with p = " << p << endl;
         ::operator delete(p); // calling default delete
      }

      void* operator new[] ( size_t n ) { return (A::operator new (n)); }

      void operator delete [] ( void* p ) { A::operator delete(p); }



};


// using malloc and free
// putting the number of elements with 
class B {
};

int main() {
   A b(1,2);
   // A* p;
   // p= new A(b);
   // 
   // if( p != &b) {
      // cout << p << " != " << &b << " and *p = " << *p << endl;
   // }
   // 
   // delete p;
   // DB(p);
// 

   A* l = new A[10]();
   DB(l);
   DB( *(reinterpret_cast<int*>(l)-1) ); // trying to see what's in the first location that the compiler keeps
   delete[] l;
   DB(l);

   delete (int*)0;

}
