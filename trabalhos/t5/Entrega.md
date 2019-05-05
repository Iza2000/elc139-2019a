
# T5: Primeiros passos com MPI

Nome: Gabriela Luisa Eckel


## Parte 1

+ Implemente uma versão em MPI do programa do trabalho t2, que calcula repetidas vezes o produto escalar entre 2 vetores. Os argumentos do programa devem ser: o número de elementos para cada processo e o número de repetições.
O programa em questão está implementado aqui: [Programa](pt2.c).
+ Avalie o desempenho do programa conforme as instruções do trabalho t2, mas variando o número de processos (-np) ao invés de threads.


## Parte 2

+ Implemente um programa MPI que transporte uma mensagem em um pipeline formado por processos de 0 a NP-1 (processo 0 envia para 1, processo 1 envia para 2, ..., processo NP-1 mostra o resultado). A mensagem é um número inteiro que é incrementado antes de ser passado adiante.
O programa em questão está implementado aqui: [Programa](pipeline.c).

## Parte 3

+ O programa [mpi_errado1.c](mpi_errado1.c) estava recebendo a tag = rank nos dois ifs, no primeiro if iria funcionar pois o rank era 0, porem no segundo if a tag deveria receber 0 e estava recendo o rank que era igual a 1.
+ O programa [mpi_errado2.c](mpi_errado2.c) não havia sido finalizado.


## Referencias 

- [Introdução a Computação Paralela com o Open MPI, Sandro Athaide Coelho](http://www.ufjf.br/getcomp/files/2013/03/Introdu%C3%A7%C3%A3o-a-Computa%C3%A7%C3%A3o-Paralela-com-o-OpenMPI.pdf)
