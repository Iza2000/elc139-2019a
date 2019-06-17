
# T8: Geração de Imagem em Paralelo com CUDA

#### Nome: Gabriela Luisa Eckel
#### Disciplina: Programação Paralela

## Parte 1

+ Implemente um programa nomeado wavecuda1.cu, em que cada frame seja computado em paralelo por uma thread diferente.
Para essa parte foi implementado o seguinte [Código](wavecuda1.cu).
+ Analise o desempenho do programa, começando pela medição dos tempos de execução sequencial e paralela para pelo menos 4 diferentes entradas do programa, sendo: a) 1024 100, b) 1024 200 e outras 2 entradas à sua escolha. Compare os tempos obtidos. Use nvprof para analisar o perfil de execução em GPU. Explique seus resultados.

s/p| 1024 100 | 1024 200 | 2048 100 | 2048 200 
---|---------|----------|----------|-----------
paralelo|9,4128ms|17.29366ms|34.42861ms|65.34582ms
sequencial| 53.53100ms|105.340000ms |210.847000ms | 421.674000ms


## Parte 2 

+ Implemente um programa nomeado wavecuda2.cu, que aproveite melhor o paralelismo da GPU.
  Para essa parte foi desenvolvido o seguinte [Código](wavecuda2.cu).

+ Analise o desempenho do segundo programa.



## Referencias 
 
- [Introdução​​ ao​​ CUDA, Davi Conte](https://edisciplinas.usp.br/pluginfile.php/4146828/mod_resource/content/1/MaterialCUDA.pdf)

