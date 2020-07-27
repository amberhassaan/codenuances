#include <iostream>


#include "ValarrayPoly.h"

using namespace std;

ostream& operator<<( ostream& out, const Valarray& v ) {
   char* sep = "";
   out << "Valarray : [";
   for( int i = 0; i < v.size() ; ++i ) {
      out << sep << v[i];
      sep = ", ";
   }
   out << "]" << endl;
}

int main() {
   Valarray v(5,10);

   cout << v ;
   
}
