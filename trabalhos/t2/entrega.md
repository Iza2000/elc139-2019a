##### Gabriela Luisa Eckel - Programação Paralela   
[Especificações](specs.txt)
[Código em OPENMP](t2openmp.c)
[Resultados](results.csv)

## parte 1: PTHREAD

##### 1-Explique como se encontram implementadas as 4 etapas de projeto: particionamento, comunicação, aglomeração, mapeamento (use trechos de código para ilustrar a explicação).
###### Particionamento:   
O particionamento está sendo feito por estas linhas, pois esta dividindo o serviço das threads. 

```
for (i = 0; i < nthreads; i++) {
   pthread_create(&threads[i], &attr, dotprod_worker, (void *) i);
}

void *dotprod_worker(void *arg){
   int i, k;
   long offset = (long) arg;
   double *a = dotdata.a;
   double *b = dotdata.b;
   int wsize = dotdata.wsize;
   int start = offset*wsize;
   int end = start + wsize;
   double mysum;
```

###### Comunicação:
Faz a ligação da soma de cada thread.
pthread_mutex_lock (&mutexsum);
   dotdata.c += mysum;
   pthread_mutex_unlock (&mutexsum);

###### Aglomeração:
 Esta parte do codigo está aglomerando os valores, pois está fazendo a multiplicação e fazendo a soma parcial.

```
for (k = 0; k < dotdata.repeat; k++) {
    mysum = 0.0;
    for (i = start; i < end ; i++)  {
        mysum += (a[i] * b[i]);
    }
}
```

###### Mapeamento: 
Essa parte está fazendo o mapemento, pois está dividindo o trabalho entre as threads;
```
for (i = 0; i < nthreads; i++) {
   pthread_create(&threads[i], &attr, dotprod_worker, (void *) i);
}
```

##### 2- Considerando o tempo (em microssegundos) mostrado na saída do programa, qual foi a aceleração (speedup) com o uso de threads?

 S(p)=6584183(p) / 3495807(2)= 1.88

##### 3- A aceleração se sustenta para outros tamanhos de vetores, números de threads e repetições? Para responder a essa questão, você terá que realizar diversas execuções, variando o tamanho do problema (tamanho dos vetores e número de repetições) e o número de threads (1, 2, 4, 8..., dependendo do número de núcleos). Cada caso deve ser executado várias vezes, para depois calcular-se um tempo de processamento médio para cada caso. Atenção aos fatores que podem interferir na confiabilidade da medição: uso compartilhado do computador, tempos muito pequenos, etc.

|NT| size    |repetitions |usec   |
|--|---------|------------|-------|
| 1|1000000  |2000        |5537308|
| 2|500000   |2000        |2767771|
| 4|25000    |2000        |154494 |
| 1|100000   |2000        |551736 |
| 2|50000    |2000        |283245 |
| 4|25000    |2000        |144914 |
| 1|137001   |0,99    |------------|
| 2|14168045 |0,96    |------------|
| 4|14953767 |0,91    |------------|
| 1|37007(2) |1,78    |------------|
| 2|65040(3) |1,01    |------------|
| 4|48863(4) |1,35    |------------|

Fiz diversas execuçôes com variadas threads, vetores e repetições e concluí que onde as repetiçoes variam o uso do paralelismo é mais eficaz, e quando sao numeros muito pequenos e aumentam as threads o speedup diminui;
Na comparação 1a, podemos notar que o o paralelismo ajudou, pois comparando o uso de duas threads o resultado foi melhor.
Já o uso de threads nos outros dois "A" não ajudou, pois diminuiu o desempenho e o demorou mais tempo de execução.
Nas comparações B, o mesmo caso se repete, só  valeu a pena usar paralelismo no caso 1b, porem o caso 2b não teve uma grande diferença de desempenho.
Nos casos C, nenhuma das opçoes valeram a pena.
E nos casos C, onde eu mudei as repetiçoes e não somente as threads, todos os casos valeriam a pena o uso do paralelismo, pois todas obtiveram um desempenho melhor com uso de +1 thread;

##### 4-Elabore um gráfico/tabela de aceleração a partir dos dados obtidos no exercício anterior.

|Tempo Sequencial|Tempo Paralelo| SpeedUP|
|-------------|--------------|------------|
| 6584183(1)  |6534451(2)    |1,00    |
| 6584183(1)  |7868565(3)    |0,83    |
| 6584183(1)  |8596610(4)    |0,76    |
| 3513795(1)  |2795428(2)    |1,25    |
| 3513795(1)  |4265054(3)    |1,02    |
| 3513795(1)  |3417622(4)    |0,82    |
| 13647068(1) |13700158(2)   |0,99    |
| 13647068(1) |14168045(3)   |0,96    |
| 13647068(1) |14953767(4)   |0,91    |
| 66057(1)    |37007(2)      |1,78    |
| 66057(1)    |65040(3)      |1,01    |
| 66057(1)    |48863(4)      |1,35    |

##### 5-Explique as diferenças entre pthreads_dotprod.c e pthreads_dotprod2.c. Com as linhas removidas, o programa está correto?

O programa pthreads_dotprod.c usa mutex para exclusão mútua no acesso à váriavel dotdata.c, tirando essas linhas torna o pthreads_dotprod2.c com possíveis resultados inconsistentes.

## parte 2: OPENMP

##### 1- Implemente um programa equivalente a pthreads_dotprod.c usando OpenMP.

```
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
```
##### 2-Avalie o desempenho do programa em OpenMP, usando os mesmos dados/argumentos do programa com threads POSIX.
|Repeat/Vetor| uso 1 thread| uso 2 thread |uso 3 thread| uso 4 thread|
|------------|-------------|--------------|------------|-------------|
|[1000000] 200 repeat| 23.96309|1.558433  |1.432752    |4.282288     |
|[500000] 2000 repeat|11.947379|7.817410  |7.497743    |18.324958    |
|[1000000] 2000 repeat|23.89170|31.501426 |43.662947   |38.03580     |
|[10000]100 repeat| 0.012052   |0.020493  |0.009931    |0.010526     |



### Referencias

- [Programação Paralela e Distribuída Métricas de Desempenho - DCC](https://www.dcc.fc.up.pt/~ricroc/aulas/0708/ppd/apontamentos/metricas.pdf)
- [Programação com OpenMP. Andrea Schwertner Charão.](https://docs.google.com/presentation/d/1Wim7xC-X4qAo0jYCm3A4yzRpaHBl_z7yIlvzPUgT0x0/export/pdf)
- [Intel Modern Code Partner OpenMP. UFGRS, INTEL, GPPD](http://inf.ufrgs.br/gppd/intel-modern-code/slides/workshop-1/MCP_Pt2_Pratica.pdf?fbclid=IwAR3U8G8cni2kYT87oiTfWWcWIeMbajRRwW91EW4gcyUwOEhgLefruBirzvo)
- [OpenMP. Blaise Barney, Lawrence Livermore National Laboratory](https://computing.llnl.gov/tutorials/openMP/#ProgrammingModel)




