//gleckel- programação paralela- t7 

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv) {

  int myrank;    // "rank" do processo
  int p;         // numero de processos
  int root = 0;      // rank do processo root
  int count; 
  int data = 100;  // atribui um valor para ser enviado
  float start_time_mpi, end_time_mpi, time_total;
  MPI_Datatype datatype; //datatype

  // MPI_Init deve ser invocado antes de qualquer outra chamada MPI
  MPI_Init(&argc, &argv);
  // Descobre o "rank" do processo
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  // Descobre o numero de processos
  MPI_Comm_size(MPI_COMM_WORLD, &p);

  count = 1;

  datatype = MPI_INT;
 start_time_mpi = MPI_Wtime();
  //Difusão dos processos usando broadcast
  MPI_Bcast(&data, count, datatype , 0 ,MPI_COMM_WORLD);

  end_time_mpi = MPI_Wtime();
  time_total = end_time_mpi - start_time_mpi;
  printf("\nEsse é o tempo de execução em segundos: %f ", time_total);
  
  MPI_Finalize();
  return 0;
}
