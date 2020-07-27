#include <stdio.h>

struct _pair {
  int x;
  int y;
};

typedef struct _pair pair;

pair makePair (int a, int b) {
  pair p;
  p.x = a;
  p.y = b;
  return p;
}

void printPair (pair p) {
  // printf ("&p=%p\n", &p);
  printf ("p=(%d,%d)\n", p.x, p.y);
}


int main () {
  pair p0 = makePair (8,8);
  // printf ("&p0=%p\n", &p0);
  printPair (p0);
  pair p1 = makePair (5,5);

  p1 = p0;
  // printf ("&p1=%p\n", &p1);
  printPair (p1);
  return 0;
}

