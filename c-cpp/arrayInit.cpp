struct Integer {
  int x;

  explicit Integer (int x): x(x) {}
};

int main (int argc, const char* argv[]) {
  Integer i(10);
  // Integer* v0 = new Integer(0)[10];
  Integer* v1 = new Integer(i)[10];
}
