#include <iostream>
#include <vector>
#include <complex>


struct BaseVarray {

   // virtual int& operator [] (int k ) = 0;
   virtual const int operator [] (size_t k) const = 0;
   virtual size_t size() const = 0;

   virtual ~BaseVarray() {
   }
};


struct Valarray : public BaseVarray {
   std::vector<int> v;

   Valarray( int sz = 0, int val = 0 ) : v(sz,val) {
   }

   Valarray( const Valarray& that ) : v( that.v ) {
   }

   Valarray( const BaseVarray* that ) {
      for( int i = 0; i < std::min( this->size(), that->size() ) ; ++i ) {
         v[i] = that->operator[](i);
      }
   }

   Valarray& operator=( const Valarray& that ) {
      if( this != &that ) {
         v = that.v;
      }
      return *this;
   }
   
   Valarray& operator=( const BaseVarray* that ) {
      for( int i = 0; i < std::min( this->size(), that->size() ); ++i ) {
         v[i] = that->operator[](i);
      }
   }

   void push_back( const int& t) {
      v.push_back(t);
   }

   virtual const int operator[]( size_t k ) const {
      return v[k];
   }

   virtual size_t size() const {
      return v.size();
   }
   
};


struct Expr : public BaseVarray {
   const BaseVarray* left;
   const BaseVarray* right;

   Expr( const BaseVarray* l, const BaseVarray* r ) : left(l), right(r) {
   }

}
