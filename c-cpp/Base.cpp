
#include <iostream>

#include "Base.h"

using namespace std;
void Base::doit() {
   cout << "Base::doit()" << endl;
}

Base::~Base() {
   cout << "Base destructor" << endl;
}
