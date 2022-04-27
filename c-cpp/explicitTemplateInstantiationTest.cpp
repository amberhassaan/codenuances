#include "explicitTemplateInstantiation.h"

#include <iostream>

int main() {

  MyClass<int> var0 = MyClass<int>::Make(1);
  MyClass<double> var1 = MyClass<double>::Make(1);
}
