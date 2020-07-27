#include <iostream>
#include <string>

using namespace std;

#define DB(x) std::cout << #x << " = " << (x) << std::endl;



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


struct Foo {
};

int main() {
   DB( isClass<int>() );
   DB( isClass<Foo>() );
   DB( isClass<string>() );
   DB( isClass<float>() );
}
