
# T6: Comunicação coletiva em MPI

Nome: Gabriela Luisa Eckel


## Parte 1

+ No código fornecido, são feitas várias chamadas de send/recv que podem ser trocadas por outras funções. Você deve descobrir quais são essas funções, fazer a alteração e testar se o resultado é o mesmo. (O programa gera sempre as mesmas matrizes, então o resultado deve ser sempre o mesmo).
Para essa parte troquei as funçoes de MPI_Send e MPI_Recv para MPI_Gatther E MPI_Scatter, também fiz uso de MPI_Bcast. 
+ MPI_Scatter copiará o elemento apropriado no buffer de recebimento do processo.
MPI_Bcast usa um único elemento de dados no processo raiz (a caixa vermelha) e o copia para todos os outros processos.
MPI_Gather é o inverso do MPI_Scatter . Em vez de espalhar elementos de um processo para muitos processos, o MPI_Gather elementos de vários processos e os reúne em um único processo.

## Parte 2  

+ Leia o artigo Send-receive considered harmful: Myths and realities of message passing e escreva um resumo crítico relacionando os argumentos do autor com sua própria experiência de programação com MPI. Obs: artigo acessível pela rede da UFSM (caso esteja em outra rede, use proxy ou siga instruções aqui).



## Referencias 

- [Scatter, Gatther e Allgather, Wes Kendall](https://translate.google.com/translate?hl=pt-BR&sl=en&u=http://mpitutorial.com/tutorials/mpi-scatter-gather-and-allgather/&prev=search)
- [Different Tag Data Types](http://www.umsl.edu/~siegelj/CS4740_5740/AlgorithmsII/MPI_send_receive.html)
