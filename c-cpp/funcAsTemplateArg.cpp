#include <iostream>
#include <vector>
#include <algorithm>

template <typename I, typename F>
void do_all(I beg, I end, const F& f) {
  for (auto i = beg; i != end; ++i) {
    f(*i);
  }
}

template <typename I, typename F, typename L>
void run(I beg, I end, const F& f, const L& l) {
  l(beg, end);
}

int main() {
  std::vector<int> vec(10, 1);

  int sum = 0;

  auto f = [&] (int i) { sum += 1; };
  run(vec.begin(), vec.end(), f, do_all<decltype(vec.begin()), decltype(f)>);
}
