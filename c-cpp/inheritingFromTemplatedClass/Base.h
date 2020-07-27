#ifndef _BASE_H
#define _BASE_H

struct Base {
  virtual ~Base () {}
  virtual int f () const = 0;
};

template <int N>
struct AbsBase: public Base {

  int g () const;
};

#endif // _BASE_H
