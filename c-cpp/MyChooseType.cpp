
#include <iostream>
#include <typeinfo>
#include <complex>

#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;

template <typename T > 
struct Valarray {
};


template <typename X, typename Y>
struct ChooseType {
};

template < typename X, typename Y > 

struct ChooseType< const X, const Y >  {
   typedef const typename ChooseType<X,Y>::RET RET;
};

template < typename X > 
struct ChooseType<X,X> {
   typedef X RET;
};

template<> struct ChooseType<int,float> {
   typedef float RET;
};
template <> struct ChooseType<float,int> {
   typedef float RET;
};

template <> struct ChooseType<int,double> {
   typedef double RET;
};

template <> struct ChooseType<double,int> {
   typedef double RET;
};

template <> struct ChooseType<double,float> {
   typedef double RET;
};

template <> struct ChooseType<float,double> {
   typedef double RET;
};


template< typename T1, typename T2, template <typename> class X > 
struct ChooseType< X<T1> , T2 > {
   typedef X< typename ChooseType<T1,T2>::RET > RET;
};

template< typename T1, typename T2, template <typename> class X > 
struct ChooseType< T1, X<T2> > {
   typedef X< typename ChooseType<T1,T2>::RET > RET;
};

template< typename T1, typename T2, template <typename> class X > 
struct ChooseType< X<T1>, X<T2> > {
   typedef X< typename ChooseType<T1,T2>::RET > RET;
};

template< typename T, template <typename> class X > 
struct ChooseType< X<T>, X<T> > {
   typedef X< typename ChooseType<T,T>::RET > RET;
};

template < typename T1, typename T2 > 
struct ChooseType< Valarray<T1>, complex<T2> > {
   typedef Valarray< complex< typename ChooseType<T1,T2>::RET  > >  RET;
};

template < typename T1, typename T2 > 
struct ChooseType< complex<T1>, Valarray<T2> > {
   typedef Valarray< complex< typename ChooseType<T1,T2>::RET  > >  RET;
};

/*
template <typename T1, typename T2> 
struct ChooseType< T1, complex<T2> > {
   typedef complex< typename ChooseType<T1,T2>::RET >  RET;
};

template <typename T1, typename T2> 
struct ChooseType< complex<T1>, T2 > {
   typedef complex< typename ChooseType<T1,T2>::RET >  RET;
};
   
template <typename T1, typename T2> 
struct ChooseType< complex<T1>, complex<T2> > {

   typedef complex< typename ChooseType<T1,T2>::RET >  RET;
};


template <typename T>
struct ChooseType< complex<T>, complex<T> > {
   typedef complex< T >  RET;
};

template < typename T1, typename T2 > 
struct ChooseType< T1, Valarray<T2> > {
   typedef Valarray< typename ChooseType<T1,T2>::RET > RET;
};

template < typename T1, typename T2 > 
struct ChooseType< Valarray<T1> , T2 > {
   typedef Valarray< typename ChooseType<T1,T2>::RET > RET;
};

template < typename T1, typename T2 > 
struct ChooseType< Valarray<T1>, Valarray<T2> > {
   typedef Valarray< typename ChooseType<T1,T2>::RET > RET;
};

template < typename T > 
struct ChooseType< Valarray<T> , Valarray<T> > {
   typedef Valarray<T> RET;
};

*/

int main() {
   DB( typeid(ChooseType<int,int>::RET).name() );
   DB( typeid(ChooseType<int,double>::RET).name() );
   DB( typeid(ChooseType<float,double>::RET).name() );
   DB( typeid(ChooseType<const float,const double>::RET).name() );

   DB( typeid(ChooseType< complex<int> , int >::RET).name() );
   DB( typeid(ChooseType< complex<int> , double >::RET).name() );

   DB( typeid(ChooseType< complex<double> , complex<int> >::RET).name() );
   DB( typeid(ChooseType< complex<int> , complex<int> >::RET).name() );

   DB( typeid( ChooseType< int , Valarray<int> >::RET ).name() );
   DB( typeid( ChooseType< float , Valarray<int> >::RET ).name() );
   DB( typeid( ChooseType< Valarray<complex<int> > , Valarray<int> >::RET ).name() );
   DB( typeid( ChooseType< Valarray<complex<int> > , Valarray<complex<int> > >::RET ).name() );
   DB( typeid( ChooseType< Valarray<complex<double> > , Valarray<complex<int> > >::RET ).name() );
   DB( typeid( ChooseType< Valarray<complex<double> > , complex<int>  >::RET ).name() );
   
   DB( typeid( ChooseType< Valarray<complex<double> > , complex<double>  >::RET ).name() );
   DB( typeid( ChooseType< Valarray<double > , complex<double>  >::RET ).name() );
   
}
