#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

#include <cassert>

#include <mpi.h>
#include <boost/mpi.hpp>

struct Point {
  size_t id;
  double x;
  double y;
  double z;

  Point (size_t id, double x, double y, double z)
    : id (id), x (x), y (y), z (z) {}


  const std::string toString () {
    char buf[1024];
    sprintf (buf, "(id=%zd, x=%g, y=%g, z=%g)", id, x, y, z);
    return std::string (buf);
  }
};

namespace boost {
  namespace serialization {
    template <typename Archive>
    void serialize (Archive& ar, Point& pt, const unsigned version) {
      std::cout << "This function should not be called" << std::endl;
      abort ();
      ar << pt.id;
      ar << pt.x;
      ar << pt.y;
      ar << pt.z;
    }
  }

  namespace mpi {
    template <> struct is_mpi_datatype<Point>: public mpl::true_ {};
  }
}

int main (int argc, char* argv[]) {
  MPI_Init (&argc, &argv);

  boost::mpi::communicator world;

  Point mypt(world.rank (), world.rank (), world.rank (), world.rank ());

  printf ("@ %d, before bcast pt=%s\n", world.rank (), mypt.toString ().c_str ());

  boost::mpi::broadcast (world, mypt, 0);

  printf ("@ %d, after bcast pt=%s\n", world.rank (), mypt.toString ().c_str ());

  MPI_Finalize ();

  return 0;
}

