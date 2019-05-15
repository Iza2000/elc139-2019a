
# T6: Comunicação coletiva em MPI

#### Nome: Gabriela Luisa Eckel

## Parte 1

+ No código fornecido, são feitas várias chamadas de send/recv que podem ser trocadas por outras funções. Você deve descobrir quais são essas funções, fazer a alteração e testar se o resultado é o mesmo. (O programa gera sempre as mesmas matrizes, então o resultado deve ser sempre o mesmo).
+ Para essa parte troquei as funçoes de MPI_Send e MPI_Recv para MPI_Gatther E MPI_Scatter, também fiz uso de MPI_Bcast. Apaguei o if que não seria necessario pois as outras funçoes já fariam seu trabalho. 
MPI_Scatter copiará o elemento apropriado no buffer de recebimento do processo.
MPI_Bcast usa um único elemento de dados no processo raiz (a caixa vermelha) e o copia para todos os outros processos.
MPI_Gather é o inverso do MPI_Scatter . Em vez de espalhar elementos de um processo para muitos processos, o MPI_Gather une elementos de vários processos e os reúne em um único processo.

[Link códígo modificado](codigo.c)

## Parte 2  

+ Leia o artigo Send-receive considered harmful: Myths and realities of message passing e escreva um resumo crítico relacionando os argumentos do autor com sua própria experiência de programação com MPI. Obs: artigo acessível pela rede da UFSM (caso esteja em outra rede, use proxy ou siga instruções aqui).

### **<center> Send-receive considered harmful: Myths and realities of message passing </center>**

**<center>Tema: Send-Recive</center>**

**<center>Palavras-Chave:** send/recv/gatther/allgather/scatter</center>

**<center>ASSUNTO DISCUTIDO:** As diversas situações citadas no artigo comprovam que o desenvolvimento de programas para sistemas  paralelos e distribuídos continua sendo um desafio difícil.
&nbsp;
Demonstra-se fatos de que o uso do método send/recv não é o melhor, comparando o com o método MPI_Bcast onde o uso é muito mais simples e assim usa menos linhas de código e poupa serviço. No artigo o autor cita os vários desafios de programar em paralelo utilizando send e recive.
&nbsp;
Podemos perceber que o uso de outras combinações de comunicação são mais efetivas que o uso de send e recive, e devemos evita-las.
&nbsp;
Como por exemplo no nosso t6, onde substitui o uso do send e recive, por gatther, scatter e bcast, poupando assim muitas linhas de codigo e melhorando a legibilidade do código. 
&nbsp;
Ao meu entendimento sobre mpi, percebi que para cada caso há uma combinação diferente e que pode ser melhor utilizada. Concordo com o autor do artigo em muitas partes e acredito que devemos explorar todas as formas e averiguar qual a melhor em cada caso. </center>

## Referencias 

- [Scatter, Gatther e Allgather, Wes Kendall](https://translate.google.com/translate?hl=pt-BR&sl=en&u=http://mpitutorial.com/tutorials/mpi-scatter-gather-and-allgather/&prev=search)
- [Different Tag Data Types](http://www.umsl.edu/~siegelj/CS4740_5740/AlgorithmsII/MPI_send_receive.html)
