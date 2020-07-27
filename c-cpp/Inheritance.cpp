#include <iostream>
#include <string>
#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;

/*
 * private.protected inheritance: public members of base become private/protected members in derived, derived can privately access them,
 * but not outside derived's scope. An object of Base still has public access to the public members, but not the D1 object
 *
 * protected members: derived can access its own members inherited from Base inside the class, if inside D1 scope. they cannot be
 * accessed outside D1's scope
 *
 * overriding a member variable of function hides all the overloead versions of the function in Base
 */

class Base {
   protected:
      int x;
   public:
      Base(int _x=0) {
         x = _x;
         cout << this << " Base Constructor called , x = " << x << endl;
         
      }

      Base( const Base& that ) : x(that.x) {
         cout << this << " Base Copy Constructor called , &that = " << &that << endl;
      }

      Base& operator=( const Base& that) {
         cout << this << " Base Assignment operator called , &that = " << &that << endl;
         if( this != &that) {
            x = that.x;
         }
         return *this;
      }

      // const string toString() {
         // return string(x);
      // }

      ~Base() {
         cout << this << " Base Destructor called, x = " << x << endl;
      }

      int getX() const { 
         cout << this << " Base::getX() " << endl;
         return x;
      }

      void print() {
         cout << "Base::print , x = " << x << endl;
      }

      void print(int) {
         cout << this << " Base::print(int) , x = " << x << endl;
      }


};


class D1: public Base {
   private:
   int y;

   public:
      D1(int _y=0) : Base(_y) {
         y = _y;
         cout << this << " D1 Constructor called , y = " << y << endl;
         
      }

      D1( const D1& that ) :Base(that.y), y(that.y) {
         cout << this << " D1 Copy Constructor called , &that = " << &that << endl;
      }

      D1& operator=( const D1& that) {
         Base::operator=(that);
         cout << this << " D1 Assignment operator called , &that = " << &that << endl;
         if( this != &that) {
            y = that.y;
         }
         return *this;
      }

      ~D1() {
         cout << this << " D1 Destructor called, x = " << x << endl;
      }

   public:
     void  assignY() {
        y = getX();
     }

     void assign ( const Base& b ) {
        cout << " this = " << this << " &b = " << &b << endl;
        y = b.getX();
        y = getX();
        // y = b.x;
        x = b.getX();
     }

     void assign ( const D1& that ) {

        y = that.y;
        x = that.x;
     }

     void print() {
        Base::print();
        cout << this << " D1::print " << endl;
     }

     void print(int) {
        cout << this << " D1::print " << endl;
     }


};

int main() {

   D1 d;

   DB( sizeof( Base ) );

   DB( sizeof( D1 ) );

   d.print();
   d.print(1);

   Base b(3);

   // DB( d.x ) ;

   // d.assign(b);
// 
   // d.assign(d);

}
