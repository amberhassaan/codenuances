#include <iostream>
#include <string>

#define DB(x) std::cout << #x << " = " << (x) << endl;

using namespace std;



template <typename T> 
bool isClassInt(T) {
   return false;
}

template <typename T>
bool isClassInt( void (T::*)(void) ) { 
   return true;
}

template <typename T> 
bool isClass() {
   return isClassInt<T>(0); // isClassInt(0) does not work, why?
}



template<typename T> 
struct HasVirtualHelper : public T {
   static bool flag;

   ~HasVirtualHelper() {
      flag = true;
   }
};

template <typename T>
bool HasVirtualHelper<T>::flag = false;


template <typename T>
bool hasVirtualInt( void (T::*)(void) ) {
   T* t = new HasVirtualHelper<T>;
   delete t;

   bool ans = false;

   if( HasVirtualHelper<T>::flag ) {
      ans = true;
      HasVirtualHelper<T>::flag = false;
   }
   return ans;
}

template <typename T>
bool hasVirtualInt(T) {
   return false;
}


template <typename T> 
bool hasVirtualDestructor() {
   return hasVirtualInt<T>(0);
}

struct Foo {
   virtual void f() {}
   virtual ~Foo(){}
};

int main() {

   DB( hasVirtualDestructor<string>() );
   DB( hasVirtualDestructor<Foo>() );
   DB( hasVirtualDestructor<int>() );
}
