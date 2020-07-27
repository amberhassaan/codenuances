#include <vector>
#include <algorithm>
#include <iterator>

#include <cassert>

#include <mpi/mpi.h>
#include <boost/mpi.hpp>

int main (int argc, char* argv[]) {

  MPI_Init (&argc, &argv);

  boost::mpi::communicator world;

  int myid = world.rank ();

  std::vector<int> v (3);

  std::fill (v.begin (), v.end (), myid);

  std::vector< std::vector<int> > result;

  boost::mpi::all_gather (world, v, result);

  assert (result.size () == world.size ());

  std::vector<int> u;
  for (std::vector< std::vector<int> >::const_iterator i = result.begin (), ei = result.end (); i != ei; ++i) {
    u.insert (u.end (), i->begin (), i->end ());
  }


  std::cout << "Result is : ";
  std::copy (u.begin (), u.end (), std::ostream_iterator<int> (std::cout, ", "));
  std::cout << std::endl;


  MPI_Finalize ();

  return 0;
}
