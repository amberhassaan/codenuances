#include <iostream>

template <typename... A>
void print(const A&... args) {
  __attribute__((unused)) int tmp[] = { (std::cout << args, 0)...};
}

int main() {
  int x = (std::cout << "xyz", 1);
  int y = ("xyz", 1);
  std::cout << " " << x << std::endl;

  print("abc", 1);
}
