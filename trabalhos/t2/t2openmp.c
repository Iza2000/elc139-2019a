#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main(){  

int n,i,t,r, aux=0;
printf("Digite o tamanho dos vetores:\n");
scanf("%d", &n);
float vetorA[n], vetorB[n];	  
printf("Digite a quantidade de threads que você deseja usar:\n");
scanf("%d", &t);
printf("Digite quantas repetiçoes você deseja:\n");
scanf("%d", &r);
for(i=0; i<n; i++)
{
   vetorA[i]=0.01;  
}
for(i=0; i<n; i++){
    vetorB[i]=1.0;  
}

double start_time = omp_get_wtime();
omp_set_num_threads(t);
#pragma omp parallel for private(i)   
for(int j=0; j<r; j++){
for(i=0; i<n; i++)
{	   
   aux += vetorA[i] * vetorB[i];    
}
}
   printf("O produto escalar entre os vetores é: %d\n", aux);	
   printf("Você usou %d threads! \n", t);
   double time = omp_get_wtime() - start_time;
    printf("%fusec\n", time);

system("pause");
}