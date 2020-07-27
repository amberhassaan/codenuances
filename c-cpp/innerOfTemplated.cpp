#include <iostream>

template <typename T>
struct Outer {
  T x;

  struct Inner;

};

template <typename T>
struct Outer<T>::Inner {
  T y;
};

template <typename T>
void printInner (typename Outer<T>::Inner& inner) {
  std::cout << "inner.y ==" << inner.y << std::endl;
}
;

template <typename T>
void printOuter (Outer<T>& outer) {
  std::cout << "outer.x ==" << outer.x << std::endl;
}
;

int main (int argc, char* argv[]) {
  
  Outer<int> o;
  o.x = 3;

  printOuter (o);

  Outer<int>::Inner i;
  i.y = 4;


  // does not compile: 'no matching function for call to printInner'
  // printInner (i); // 

  printInner <int> (i);

  return 0;
}


