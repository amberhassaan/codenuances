
#include <cstdio>
#include <cstdlib>
#include <iostream>

#define DB(s) std::cout << #s << " = " << (s) << std::endl;

using namespace std;

void arrayDynamic (int*** a, int x, int y, int z) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      for (int k = 0; k < z; ++k) {
        a[i][j][k] = i * x * y + j * z + k;
      }
    }
  }

}

void arrayStatic (int a[][3][4], int x, int y, int z) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      for (int k = 0; k < z; ++k) {
        a[i][j][k] = i * x * y + j * z + k;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "Wrong number of cmd line arguments, provide 3 numbers" << endl;
    exit (-1);
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  int z = atoi(argv[3]);

  cout << "Array dimensions are: " << x << ", " << y << ", " << z << endl;

  DB (sizeof(int));
  
  int* t = new int[x*y*z];

  int*** a = new int**[x];

  // for (int i = 0; i < x; ++i) {
    // a[i] = (int **) &t[i*x*y];
    // for (int j = 0; j < y; ++j) {
      // a[i][j] = &t[i*x*y + j*z];
    // }
  // }

  arrayDynamic (a, x, y, z);

  int b[2][3][4];
  arrayStatic (b, 2, 3, 4);

  // for (int i = 0; i < x; ++i) {
    // DB (a[i]);
    // for (int j = 0; j < y; ++j) {
      // DB (a[i][j]);
      // for (int k = 0; k < z; ++k) {
        // DB (a[i][j][k]);
      // }
    // }
  // }

 // delete[] a;
 delete[] t;
}
