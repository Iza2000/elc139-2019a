# T7: Avaliação de desempenho de programas MPI

#### Nome: Gabriela Luisa Eckel

## Parte 1

+ Implementar um programa para comparar a implementação do broadcast com send e receive (fornecida) com a função MPI_Bcast nativa do MPI;
    Conforme solicitado, implementei um programinha que utiliza a função nativa do MPI, MPI_Bcast. E aqui esta o [LINK](teste.c) para o código. 

+ Coletar e comparar (em forma de gráfico) os tempos de execução de cada uma das implementações do broadcast, variando o número de processos;
+  Considerando que na linha horizontal estão o numero de processos e na linha diagonal o tempo de execução no padrão de 0.0000xx; Todas as execuções foram feitas com o tamanho do vetor 1000;

<img src = srbcast.png>
<img src = teste.png>

+ Considerando que na linha horizontal estão o numero de processos e na linha diagonal o tempo de execução no padrão de 0.0000xx; Todas as execuções foram feitas com o tamanho do vetor 2000;

<img src = srbcast2.png>
<img src = teste2.png>

## Parte 2 

Utilizando o simulador SMPI com os arquivos cluster_crossbar.xml e cluster_hostfile.txt como parâmetros, realize execuções variando as configurações que descrevem as características do ambiente distribuido simulado.

    
+ Realize execuções variando os valores de "bw" (largura de banda) e "lat" (latência) no arquivo cluster_crossbar.xml;

+ Realize execuções variando o tamanho do vetor (passado por argumento para o executável);

+ Compare os tempos de execução (em forma de gráfico);

## Referencias 
 
- [INPE, Celso L. Mendes](http://www.lac.inpe.br/~celso/cap315/aula27/tsld006.htm)
- [A Comprehensive MPI Tutorial Resource](http://mpitutorial.com/)  
- [Tutorial MPI](https://computing.llnl.gov/tutorials/mpi/)  
- [SMPI CourseWare](https://simgrid.github.io/SMPI_CourseWare/)
