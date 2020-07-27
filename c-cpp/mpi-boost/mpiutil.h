#ifndef MPI_UTIL_H
#define MPI_UTIL_H

#include <iostream>
#include <mpi.h>

std::ostream& mpiOut (std::ostream& out=std::cout) {
  int id;
  MPI_Comm_rank (MPI_COMM_WORLD, &id);
  out << "@proc " << id << " ";
  return out;
}

#endif //  MPI_UTIL_H
