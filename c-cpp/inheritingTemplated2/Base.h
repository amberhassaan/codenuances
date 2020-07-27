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

template <int N>
struct Derived1: public AbsBase<N> {
  virtual int f () const;

};

template <int N>
int AbsBase<N>::g () const { return N; }

template <int N>
int Derived1<N>::f () const { return AbsBase<N>::g (); }

#endif // _BASE_H
