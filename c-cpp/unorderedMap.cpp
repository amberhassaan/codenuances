#include "util.h"

#include <tr1/unordered_map>
#include <utility>

using namespace std;

int main (int argc, char* argv[]) {
  const size_t N = 10;

  unordered_map<size_t, size_t> mymap;

  for (size_t i = 0; i < N; ++i) {
    mymap.insert (make_pair (i, N-i));
  }
}
