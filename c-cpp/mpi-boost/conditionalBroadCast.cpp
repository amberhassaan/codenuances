#include <iostream>
#include <mpi.h>
#include <boost/mpi.hpp>

#include "mpiutil.h"

int main (int argc, char* argv[]) {

  MPI_Init (&argc, &argv);
  boost::mpi::communicator world;

  const size_t LIM = 20;
  // proc 0 increments i and then broadcasts it to other guys

  size_t i = 0;
  while (true) {

    mpiOut () << "Before calling broadcast, i = " << i << std::endl;
    if (world.rank () == 0) { 
      ++i;

      if (i >= LIM) {
        boost::mpi::broadcast (world, i , 0);
      }
    }
    else { 
      boost::mpi::broadcast (world, i, 0);
    }

    if (i >= LIM) { 
      break;
    }

    mpiOut () << "After calling broadcast, i = " << i << std::endl;

  }

  mpiOut() << "Ended Loop" << std::endl;

  MPI_Finalize ();

  return 0;

}
