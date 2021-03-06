# T7: Avaliação de desempenho de programas MPI

#### Nome: Gabriela Luisa Eckel
#### Disciplina: Programação Paralela

## Parte 1

+ Implementar um programa para comparar a implementação do broadcast com send e receive (fornecida) com a função MPI_Bcast nativa do MPI;
+ Conforme solicitado, implementei um programinha que utiliza a função nativa do MPI, MPI_Bcast. E aqui esta o [LINK](teste.c) para o código. 

+ Coletar e comparar (em forma de gráfico) os tempos de execução de cada uma das implementações do broadcast, variando o número de processos;
+  Considerando que na linha horizontal estão o numero de processos e na linha diagonal o tempo de execução em milissegundos; Todas as execuções do primeiro gráfico foram feitas com o tamanho do vetor 1000; e as do segundo gráfico com o vetor de tamanho 2000;

<img src = comparativo1000.png>
<img src = comparativo2000.png>


## Parte 2 

Utilizando o simulador SMPI com os arquivos cluster_crossbar.xml e cluster_hostfile.txt como parâmetros, realize execuções variando as configurações que descrevem as características do ambiente distribuido simulado. 
Para as medições de tempo no arquivo [avg.c](avg.c) utilizei a biblioteca time.h do C. E as incrementei nas seguintes linhas de código.

```
63.  start_time_mpi = MPI_Wtime();

95. end_time_mpi = MPI_Wtime();
96.   printf("%f\n", (end_time_mpi - start_time_mpi) * 1000);
97.     printf("Avg of all elements is %f\n", avg);
```
 
+ Realize execuções variando os valores de "bw" (largura de banda) e "lat" (latência) no arquivo cluster_crossbar.xml;
+ Realizei várias variações de latencia e largura de banda, que estão sendo demonstradas no gráfico a seguir; Para essas execuções utilizei um vetor de 3000.
  <img src = comparativox.png>

+ Realize execuções variando o tamanho do vetor;
+  Utilizei como variação de tamanho do vetor, 2000 e 3000; Na linha horizontal encontra-se o numero de  processos, e na linha vertical o tempo das execuções.

  <img src = comparativovetores.png>


## Referencias 
 
- [INPE, Celso L. Mendes](http://www.lac.inpe.br/~celso/cap315/aula27/tsld006.htm)
- [A Comprehensive MPI Tutorial Resource](http://mpitutorial.com/)  
- [Tutorial MPI](https://computing.llnl.gov/tutorials/mpi/)  
- [SMPI CourseWare](https://simgrid.github.io/SMPI_CourseWare/)
