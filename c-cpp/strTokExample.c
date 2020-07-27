#include <string.h>
#include <stdio.h>
#include <assert.h>

int main (int argc, char* argv[]) {
  char str[] = "Abra cadabra Abra Abra Cadabra";
  // char* str = "Abra cadabra Abra Abra Cadabra";
  const char* delim = " ";

  // testing to see what happens when reading using NULL
  // initially
  char* p = strtok (NULL, delim);
  assert (p == NULL);
  

  p = strtok (str, delim);

  while (p != NULL) {
    printf ("%s\n", p);
    p = strtok (NULL, delim);
  }
}
