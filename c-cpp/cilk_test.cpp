// #include <cilk.h>
#include <cilk/cilk.h>

#include <cstdio>

int fib (int N) {
  if (N <= 2) { return N; }

  // int x = _Cilk_spawn fib (N-1);
  // int y = _Cilk_spawn fib (N-2);
  int a[2];
  _Cilk_for (int i = 0; i < 2; ++i) {
    a[i] = fib (N-i-1);
  }
  // _Cilk_sync;
  // return (x+y);
  int sum = 0;
  for (int i = 0; i < 2; ++i) {
    sum += a[i];
  }
  return sum;
}

int main () {

  int r = fib (22);

  std::printf ("fib(22)=%d\n", r);

  return 0;
}
