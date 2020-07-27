#include <typeinfo>
#include "util.h"

// I want to typedef  Graph<SimObj>
// but SimObj needs a template parameter, which will be Graph
// more over SimObj has a function f (), which takes template parameter (Graph in this case)
// as an argument
template <typename T> 
struct Graph {
};

// Solution1: create an empty base class, with all the functions of SimObj 
// declared as pure virtual 
struct baseSimObj {
  virtual void f (const Graph<baseSimObj>& t) const = 0;
};


template <typename T> 
struct SimObj: baseSimObj {
  typedef SimObj<T> myType;

  void f (const T& t) const {
    DB (typeid (t).name ());
  }
};



int main (int argc, char* argv[]) {
  typedef Graph<baseSimObj> GraphType;
  typedef SimObj<GraphType>::myType SimObjType;

  SimObjType x;

  DB (typeid(x).name ());

  x.f(GraphType());

  baseSimObj* p = new SimObj<GraphType> ();
  p->f (GraphType ());
}
