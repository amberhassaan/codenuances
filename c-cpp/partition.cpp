#include "util.h"
#include <functional>
#include <iterator>
#include <utility>
#include <type_traits>

template <typename I>
void partition_forward (const I beg, const I end) {
  std::cout << "Partition called on range: ";
  printIter (beg, end);
  std::cout << std::endl;

  if (std::distance (beg, end) < 2) {
    return;

  } else {
    I b = beg;
    I e = end;
    using T = typename std::remove_reference<decltype (*b)>::type;
    // auto pivot = *b;
    T pivot = *b;
    std::less<decltype (pivot)> l;

    std::cout << "pivot: " << pivot << std::endl;

    I i = b;
    while (b != end) {
      while (l (*b, pivot)) {
        ++b;
      }

      // find the next position smaller than pivot
      ++i;
      while (i != e && l (pivot, *i)) {
        ++i;
      }

      if (i != e) {
        std::swap (*b, *i);

      } else {
        break;
      }

    }

    partition_forward (beg, b);
    partition_forward (++b, end);
  }
}



template <typename I>
void partition_recursive (const I beg, const I end) {

  std::cout << "Partition called on range: ";
  printIter (beg, end);
  std::cout << std::endl;

  if (std::distance (beg, end) < 2) {
    return;

  } else {
    I b = beg;
    I e = end;
    using T = typename std::remove_reference<decltype (*b)>::type;
    T pivot = *(b + std::distance (b, e) / 2);
    std::less<int> l;

    std::cout << "pivot: " << pivot << std::endl;

    --e;
    while (b != e) {

      while (l (*b, pivot)) {
        ++b;
      }

      while (l (pivot, *e)) {
        --e;
      }

      std::swap (*b, *e);
      // assert (l (*b, pivot));
      // assert (l (pivot, *e));
      // ++b;
      // --e;

    }

    partition_recursive (beg, b);
    partition_recursive (e, end);

  }

}

template <typename I, typename T>
I partition_reverse (const I beg, const I end, const T& pivot) {

  I b = beg;
  I e = end;

  --e;

  std::less<T> cmp;
  while (b != e) {
    while (b != e && cmp (pivot, *b)) {
      ++b;
    }

    while (b != e && cmp (*e, pivot)) {
      --e;
    }

    if (b != e) {
      std::swap (*b, *e);
      std::cout << "Range after swap: "; printIter (beg, end); std::cout << std::endl;
    }
  }

  return b;
}

int main () {

  // int x[] = {5, 9, 14, 2, 15, 1, 13, 3 };

  // partition_recursive (&x[0], &x[0] + sizeof (x) / sizeof (x[0]));
  // partition_forward (&x[0], &x[0] + sizeof (x) / sizeof (x[0]));

  // std::cout << "Range after sorting: ";
  // printIter (x, x+8);
  // std::cout << std::endl;


  int x[] = {5, 9, 14, 2, 15, 1, 13, 3 };
  auto b = &x[0];
  auto e = &x[0] + sizeof (x) / sizeof (x[0]);

  std::cout << "Input range: "; printIter (b, e); std::cout << std::endl;

  auto s = partition_reverse (b, e, 9);

  std::cout << "First range: "; printIter (b, s); std::cout << std::endl;
  std::cout << "2nd range: "; printIter (s, e); std::cout << std::endl;

}

