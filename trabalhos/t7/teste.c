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
 
  //Difusão dos processos usando broadcast
  MPI_Bcast(&data, count, datatype , 0 ,MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD);
  
  start_time_mpi = MPI_Wtime();
  if (myrank == root) {         

    // Se for o rank root, enviar o dado para cada um dos demais
    int i;
    for (i = 0; i < p; i++) {
      if (i != myrank) {
        MPI_Send(&data, count, datatype, i, 0, MPI_COMM_WORLD);
      }
    }
  } else {
    // Se não for o rank root, recebe o dade envidado pelo rank root
    MPI_Recv(&data, count, datatype, root, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Processo %d recebendo dado %d do processo root\n", myrank, data); // Exemplo de saída
  }

  MPI_Finalize();

  end_time_mpi = MPI_Wtime();
  time_total = end_time_mpi - start_time_mpi;
  printf("\nEsse é o tempo de execução em segundos: %f ", time_total);

  return 0;
}
