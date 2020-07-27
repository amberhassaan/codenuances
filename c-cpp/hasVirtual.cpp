#include <iostream>

#define DB(x) std::cout << #x << " = " << (x) << endl;

using namespace std;

template <typename T> class My: public T {
   virtual ~My(){}
};


template <typename T> 
bool hasVirtual() {
   return !( sizeof(My<T>) > sizeof(T) );
}

struct Foo {
   virtual void f() {}
   virtual ~Foo(){}
};

int main() {

   DB( hasVirtual<Foo>() );
   DB( hasVirtual<int>() );
}
