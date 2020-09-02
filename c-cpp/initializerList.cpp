#include <initializer_list>
#include <iostream>
#include <vector>

template <typename V = std::initializer_list<int> >
void func(const V& vec) {
  for (const auto& i: vec) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}

int main () {

  func({1, 2, 3, 4, 5});

  std::vector<char> v1 = { 'a', 'b', 'c' };

  func(v1);

  return 0;
}

