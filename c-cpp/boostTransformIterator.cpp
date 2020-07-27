#include "util.h"

#include <vector>
#include <iterator>
#include <utility>

#include <boost/iterator/transform_iterator.hpp>
#include <boost/iterator/counting_iterator.hpp>

template <typename V>
struct Indexer: public std::unary_function<size_t, typename V::value_type> {
  V& v;

  Indexer (V& _v): v (_v) {}

  typename V::value_type operator () (size_t i) const {
    return v[i];
  }
};



int main () {

  typedef std::vector<std::pair<int, int> > Vec;
  Vec v;

  for (size_t i = 0; i < 10; ++i) {
    v.push_back (std::make_pair (i, -i));
  }

  typedef Indexer<Vec> F;

  typedef boost::transform_iterator<F, boost::counting_iterator<size_t> > Iter;

  Iter beg = boost::make_transform_iterator (boost::counting_iterator<size_t> (0), F (v));
  Iter end = boost::make_transform_iterator (boost::counting_iterator<size_t> (v.size ()), F (v));

  printIter (beg, end);


};
