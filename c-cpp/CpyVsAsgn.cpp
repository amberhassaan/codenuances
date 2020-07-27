#include <iostream>

using namespace std;

class A{
   private:
      int id;
      int x;
      static int count;
   public:
      A(){
         id=count++;
         x = id;
         cout << "Default constructor called, id = " << id << ", x = " << x <<  std::endl;
      }

      explicit A(int _x){
         id = count++;
         x = _x;
         cout << "NON-Default constructor called, id = " << id << ", x = " << x <<  std::endl;
      }

      A( const A& that) {
         id = count++;
         x = that.x;
         cout << "Copy constructor called, id = " << id << ", x = " << x <<  std::endl;
         cout << "that.id = " << that.id << ", that.x = " << that.x <<  std::endl;
      }

      A& operator= ( const A& that) {
         cout << "Assignment operator called, id = " << id << ", x = " << x <<  std::endl;
         cout << "that.id = " << that.id << ", that.x = " << that.x <<  std::endl;
         if( this != &that ) {
            x = that.x;
         }
         return *this;
      }

      ~A() {
         cout << "Destructor called, id = " << id << ", x = " << x <<  std::endl;
      }

      A& operator++(int x) {
         cout << "++ operator called, id = " << id << ", x = " << x <<  std::endl;
         x++;
         return *this;
      }

};

int A::count = 0; // initialization allowed though private

int main(){

   // A::count = 0; // not allowed
   A a(0);
   A b;
   A c(a);
   A d = b; // always same as A d(b)
   c = b = a;

   int x(1);
   int y = 1;

   // A e = 1; // does not work if explicit constructor
   A e = A(1); // same as A e(0)


}
