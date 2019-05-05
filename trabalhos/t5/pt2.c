/*
 *  Exemplo de programa para calculo de produto escalar em paralelo, usando MPI.
 *  andrea@inf.ufsm.br
 *  mpi -> gleckel@inf.ufsm.br
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mpi.h"

typedef struct {
    double *a;
    double *b;
    int wsize;
    int repeat; 
} dotdata_t;

dotdata_t dotdata;

double calculaEscalar(int wsize, int repeat);
void criaVetor(int wsize, int repeat);
void fill(double *a, int size, double value);
long wtime();
void mostraResultado(double total_dotprod, int wsize, int p, long start_time, long end_time, double start_time_mpi, double end_time_mpi);
void checaResultado(double total_dotprod, int wsize, int qtd_proc);


int main(int argc, char **argv) {
    int rank, p, source, dest = 0, tag = 0, wsize, repeat;
    
    double result;     
    MPI_Status status;  
    
    long start_time, end_time;
    double start_time_mpi, end_time_mpi;

    
    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    
    start_time = wtime(); 
    start_time_mpi = MPI_Wtime(); 
    
    if (rank != 0) { 	
        result = calculaEscalar(wsize, repeat);
        MPI_Send(&result, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD); //envia msg
    } else {            
        double total_dotprod = calculaEscalar(wsize, repeat); 
        for(source = 1; source < p; source++) {
            MPI_Recv(&result, 1, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &status); 
            total_dotprod += result;
        }
        end_time = wtime();
        end_time_mpi = MPI_Wtime();
        mostraResultado(total_dotprod, wsize, p, start_time, end_time, start_time_mpi, end_time_mpi);
    }
    
    MPI_Finalize(); 

    return EXIT_SUCCESS;
}


double calculaEscalar(int wsize, int repeat) {
    criaVetor(wsize, repeat);
    double *a = dotdata.a;
    double *b = dotdata.b;  
    double mysum;
q    for (int k = 0; k < repeat; k++) {
    	mysum = 0.0;
    	for (int i = 0; i < wsize; i++) {
            mysum += (a[i] * b[i]);
    	}
    }
    free(dotdata.a);
    free(dotdata.b);
    return mysum; 
}

void criaVetor(int wsize, int repeat) {
    dotdata.a = (double*) malloc(wsize * sizeof(double));
    fill(dotdata.a, wsize, 0.01);
    dotdata.b = (double*) malloc(wsize * sizeof(double));
    fill(dotdata.b, wsize, 1.0);
    dotdata.wsize = wsize;
    dotdata.repeat = repeat;
}

void fill(double *a, int size, double value) {  
    for (int i = 0; i < size; i++)
        a[i] = value;
}

long wtime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec * 1000000 + t.tv_usec;
}

void mostraResultado(double total_dotprod, int wsize, int p, long start_time, long end_time, double start_time_mpi, double end_time_mpi) {
    printf("Produto: %f\n", total_dotprod);
    printf("Numero de Processos: %d ", p);
    printf("Tempo de exec: %f usec\n", (end_time_mpi - start_time_mpi) * 1000000),
    fflush(stdout);
}

