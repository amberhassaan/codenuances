#include "util.h"


struct Foo {
  int x;

  explicit Foo (int _x): x (_x) {}

  Foo (const Foo& that): x(that.x) { 
    std::cout << "Foo::copy constructor = " << std::endl;

    this->str ();
    that.str ();
  }

  Foo& operator = (const Foo& that) { 
    std::cout << "Foo::operator = " << std::endl;

    this->str ();
    that.str ();

    this->x = that.x;
  }

  std::string str () const { 
    std::stringstream ss;
    DBOUT_N (ss, this);
    DBOUT_N (ss, x);
    return ss.str ();
  }
};

void doswap (Foo& x, Foo& y) {
  Foo tmp = x; // Foo tmp (x);
  x = y;
  y = tmp;

}


struct Bar {
  int& x;

  explicit Bar (int& _x): x(_x) {}

  Bar (const Bar& that): x(that.x) {
    this->str ();
    that.str ();
    std::cout << FUNC << " after: "; DB_N (this->str ()); DB (that.str ());
  }

  Bar& operator = (const Bar& that) {
    std::cout << FUNC << " before: "; DB_N (this->str ()); DB (that.str ());

    this->x = that.x;

    std::cout << FUNC << " after: "; DB_N (this->str ()); DB (that.str ());
    return *this;
  }

  std::string str () const { 
    std::stringstream ss;
    DBOUT_N (ss, this);
    DBOUT_N (ss, x);
    return ss.str ();
  }

};

int main () {

  Foo f1 (1);

  Foo f2 (2);

  doswap (f1, f2);

  // f1.str ();
// 
  // f2.str ();
// 
// 
  // Foo& rf1 = f1; // Foo* rf1 = &f1;
// 
  // rf1 = f2; // (*rf1) = f2;
// 
  // f1.str ();
  // f2.str ();
  // rf1.str ();
// 
  // rf1 = Foo (3); // (*rf1) = Foo (3);
  //


  int i = 1;
  int j = 2;

  DB (i);
  DB (j);

  Bar b0 (i);
  Bar b1 (j);
  Bar b2 (b0);
  b0 = b1;

  DB (i);
  DB (j);

  return 0;
}

// -- Reference must be initialized/bound at the time when it's declared. For
// member references, binding must happen in the initialization list
// -- At initialization time, a statement of type T& x = y translates to T* x = &y;
// -- At use time, e.g. T& x = y; x = z translates to (*&y) = z;
// -- Once bound, it cannot be unbound. i.e. T& x = y; x = z implies y = z;
// -- If Reference is non-const then it must refer to an lvalue (something that has
//  a valid address)
// -- If class has a member that is a const reference, then it can have a copy
// constructor, but 

