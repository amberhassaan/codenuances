#include <iostream>

const double A = 1.123;
const double B = A + 1.01;

int main () {

  const double C = A + B;

  std::cout << "C = " << C << std::endl;

  return 0;
};
