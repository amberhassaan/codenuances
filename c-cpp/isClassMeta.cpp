#include <iostream>
#include <string>


using namespace std;

#define DB(x) std::cout << #x << " = " << (x) << std::endl;

struct TrueType {  int x; };
struct FalseType {};


template <typename X, typename Y >
struct IsSameType {
   enum { ANSWER= false };
};

template <typename X>
struct IsSameType<X,X> {
   enum { ANSWER= true };
};



template <typename T> 
TrueType  isClassDecide( void (T::*p)(void) );

template <typename T> 
// FalseType isClassDecide(...);
FalseType isClassDecide(T);

template <typename T> 
struct IsClass {
   enum {ANSWER = sizeof(isClassDecide<T>(0)) == sizeof(TrueType) };
};


template <bool isClassT , typename T >
struct IsVirtualHelper {
};

template <typename T>
struct IsVirtualHelper<true, T> : public T {
   virtual ~IsVirtualHelper();
};

template <typename T> 
struct HasVirtual {
   enum { ANSWER = ( IsClass<T>::ANSWER ) ? sizeof( IsVirtualHelper< IsClass<T>::ANSWER, T >) == sizeof(T): false  };
};

struct Foo {
};


template <typename T>
struct IsArray {
   enum {ANSWER = false };
};

template <typename T>
struct IsArray< T[] > {
   enum {ANSWER = true };
};

template< typename T, int N>
bool isArray(T[N]) {
   return IsArray<T>::ANSWER;
};



struct Bar {
   virtual void f();
   virtual ~Bar();
};

int main() {
   DB( IsClass<int>::ANSWER );
   DB( IsClass<Foo>::ANSWER );
   DB( IsClass<string>::ANSWER );
   DB( IsClass<float>::ANSWER );



   DB( HasVirtual<Foo>::ANSWER );
   DB( HasVirtual<Bar>::ANSWER );
   DB( HasVirtual<int>::ANSWER );
   DB( HasVirtual<char>::ANSWER );
   DB( HasVirtual<string>::ANSWER );
   
   int x[10];
   DB( isArray(x) );
}


