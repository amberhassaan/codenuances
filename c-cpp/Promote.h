#ifndef _Promote_tpp
#define _Promote_tpp

#include <iostream>
#include <complex>
#include <vector>

// dummy declaration
template <typename T, typename R=std::vector<T> >
struct Valarray {};

template <typename T> 
struct SRank;

template <>
struct SRank<int> {
  static const int RET = 0;
};

template <>
struct SRank<float> {
  static const int RET = 1;
};

template <>
struct SRank<double> {
  static const int RET = 2;
};

template <typename T>
struct SRank<std::complex<T> > {
  static const int RET = SRank<T>::RET;
};

template <typename T, typename R>
struct SRank<Valarray<T, R> > {
  static const int RET = SRank<T>::RET;
};

template <typename T>
struct SRank<const T> {
  static const int RET = SRank<T>::RET;
};


template <int x>
struct SType {
  typedef void RET; // undefined for arbitrary SRANK
};


template <>
struct SType<0> {
  typedef int RET;
};

template <>
struct SType<1> {
  typedef float RET;
};

template <>
struct SType<2> {
  typedef double RET;
};

template <typename T>
struct CRank {
  static const bool RET = false;
};

template <typename T>
struct CRank<std::complex<T> > {
  static const bool RET = true;
};

template <typename T, typename R>
struct CRank<Valarray<T, R> > {
  static const bool RET = CRank<T>::RET;
};

template <typename T>
struct CRank<const T> {
  static const bool RET = CRank<T>::RET;
};

template <bool rank, typename Base>
struct CType {
  typedef std::complex<Base> RET;
};

template<typename Base>
struct CType<false, Base> {
  typedef Base RET;
};

template <typename T>
struct VRank {
  static const bool RET = false;
};

template <typename T, typename R>
struct VRank<Valarray<T, R> > {
  static const bool RET = true;
};

template <typename T>
struct VRank<const T> {
  static const bool RET = VRank<T>::RET;
};

template <bool rank, typename T>
struct VType;

template <typename T>
struct VType<true, T> {
  typedef Valarray<T> RET;
};

template <typename T>
struct VType<false, T> {
  typedef T RET;
};


template <typename X, typename Y>
struct ChooseType { 
  static const int xrank = SRank<X>::RET;
  static const int yrank = SRank<Y>::RET;
  static const int maxrank = xrank < yrank ? yrank : xrank;

  typedef typename SType<maxrank>::RET SType;

  static const bool xcomp = CRank<X>::RET;
  static const bool ycomp = CRank<Y>::RET;
  static const bool ourcomp = xcomp || ycomp;

  typedef typename CType<ourcomp, SType>::RET CType;

  
  static const bool xvec = VRank<X>::RET;
  static const bool yvec = VRank<Y>::RET;
  static const bool ourvec = xvec || yvec;

  typedef typename VType<ourvec, CType>::RET RET;
};

template <typename NewType>
struct PromoteTo {
  NewType val;

  PromoteTo(const NewType& x) : val(x) {}

  template <typename OrigType>
  PromoteTo(const OrigType& x) {
    val = x;
  }

  operator NewType() { return val; }
};

template <typename NewType>
struct PromoteTo<Valarray<NewType> > {
  Valarray<NewType> val;

  PromoteTo(const Valarray<NewType>& x) : val(x) {}

  template <typename OrigType, typename OrigRep>
  PromoteTo(const Valarray<OrigType, OrigRep>& x) : val(x.size()) {
    for (int k = 0; k < (int) x.size(); k += 1) {
      val[k] = (NewType) PromoteTo<NewType>(x[k]);
    }
  }

  operator Valarray<NewType>() { return val; }
};


#endif /* _Promote_tpp */
