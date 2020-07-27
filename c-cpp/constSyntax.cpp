#include "util.h"

typedef char* CharPtr;

int main (int argc, char* argv[]) {

  char a = 'c';

  const CharPtr x = &a;
  x = NULL; // does not compile

  // const T and T const are the same
  CharPtr const y = &a;
  y = NULL; // does not compile

  const char* z = &a;
  z = NULL;

  const char* const w = &a;
  w = NULL;


  return 0;
};
