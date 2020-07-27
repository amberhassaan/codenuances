#include<iostream>
#include <string>
#include <algorithm>


#include "util.h"

std::string toLower (std::string in) {
  std::transform (in.begin (), in.end (), in.begin (), ::tolower);
  return in;
}

int main (int argc, char* argv[]) {
  DB (toLower (std::string ("HeLLo")));
}
