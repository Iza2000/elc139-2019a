
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int rank, p, msg;

    MPI_Init(&argc, &argv); 
    MPI_Comm_size(MPI_COMM_WORLD, &p); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 

    if (rank == 0) {
        printf("start \n"); 
        msg = 0;
        printf("p[%d] -> p[%d]\n", rank, rank+1);
        MPI_Send(&msg, 1, MPI_INT, (rank+1), 0, MPI_COMM_WORLD); //envia mensagem para rank+1 = 1
    } else if ( rank == (p - 1) ) {
        MPI_Recv(&msg, 1, MPI_INT, (rank-1), 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);  //recebe mensagem do rank - 1 = 0
        printf("p[%d] <- p[%d]\n", rank, rank-1);
        printf("[FIM] Process %d got the result: %d\n\n", rank, msg);
    } else {
        printf("p[%d] -> p[%d]\n", rank, rank+1);
        MPI_Send(&msg, 1, MPI_INT, (rank+1), 0, MPI_COMM_WORLD); // envia mensagem para o rank + 1 = 1
    }

    MPI_Finalize(); 
    return EXIT_SUCCESS;

}
