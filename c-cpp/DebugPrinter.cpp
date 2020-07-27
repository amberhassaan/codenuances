#include <iostream>

using namespace std;



struct DBStream {
   ostream& out;
   bool isEnabled;

   DBStream( ostream& _out, bool _isEnabled ): out(_out), isEnabled(_isEnabled) {
   }

   friend DBStream& operator<<( DBStream& s, const int t ) {
         if( s.isEnabled ) {
            s.out << t ;
         }
         return s;
      }
};



struct DB {
   DBStream s;
   int debugLevel;

   DB( ostream& o, int db = 0 ) : s(o,true), debugLevel(db) {
   }

   DBStream& operator () ( int level ) {
      if( level < debugLevel ) {
         s.isEnabled = false;
      }
      else {
         s.isEnabled = true;
      }
      return s;
   }

};


// struct StarMaker {
   // int n;
   // 
   // ostream& operator<<(ostream& o) const;
// };
// 
// StarMaker stars(int n ) {
   // StarMaker s;
   // s.n = n;
   // return s;
// 
   // 
// }
// 
// ostream& operator << ( ostream& out, const StarMaker& s ) {
   // for ( int i = 0; i < s.n; ++i ) {
      // out << "*";
   // }
   // return out;
// }


int main() {

   DB db(cout);
   DBStream s(cout, true);
   s << 1000 << endl;


   // db(-1) << "Don't print" << endl;


   // cout << " Hello " << stars(5) << " World" << endl;




}
