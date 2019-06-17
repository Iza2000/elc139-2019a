
# T8: Geração de Imagem em Paralelo com CUDA

#### Nome: Gabriela Luisa Eckel
#### Disciplina: Programação Paralela

## Parte 1

+ Implemente um programa nomeado wavecuda1.cu, em que cada frame seja computado em paralelo por uma thread diferente.
Para essa parte foi implementado o seguinte [Código](wavecuda1.cu).
+ Analise o desempenho do programa, começando pela medição dos tempos de execução sequencial e paralela para pelo menos 4 diferentes entradas do programa, sendo: a) 1024 100, b) 1024 200 e outras 2 entradas à sua escolha. Compare os tempos obtidos. Use nvprof para analisar o perfil de execução em GPU. Explique seus resultados.
Para paralelizar criei uma função kernel. Mostrada a seguir 
~~~javascript
__global__
void fazPixel(int width, int frames, unsigned char* pic)
{
  int ix = threadIdx.x;
  int of = blockDim.x;
  for (int frame = ix; frame < frames; frame += of) {
  //for (int frame = 0; frame < frames; frame++) {
    for (int row = 0; row < width; row++) {
      for (int col = 0; col < width; col++) {
        float fx = col - 1024/2;
        float fy = row - 1024/2;
        float d = sqrtf( fx * fx + fy * fy );
        unsigned char color = (unsigned char) (160.0f + 127.0f *
                                          cos(d/10.0f - frame/7.0f) /
                                          (d/50.0f + 1.0f));

        pic[frame * width * width + row * width + col] = (unsigned char) color;
      }
    }
  }
}
~~~
Para a analise, comparei o programa sequencial [wave.c](wave.c), com a sua versão paralelizada[wavecuda1.cu](wavecuda1.cu).

Tempo em MS| 1024 100 | 1024 200 | 2048 100 | 2048 200 
---|---------|----------|----------|-----------
Paralelo|9,4128ms|17.29366ms|34.42861ms|65.34582ms
Sequencial| 53.53100ms|105.340000ms |210.847000ms | 421.674000ms
 
Acredito que o resultado é o esperado pois os tempos vão subindo de acordo com a quantidade de frames, e diminuiram com  a paralelização. Pelos resultados, nota-se que CUDA é uma otima ferramenta, pois o tempo utilizando CUDA foram bem menores, praticamente a metade. 

## Parte 2 

+ Implemente um programa nomeado wavecuda2.cu, que aproveite melhor o paralelismo da GPU.
  Para essa parte foi desenvolvido o seguinte [Código](wavecuda2.cu).

+ Analise o desempenho do segundo programa.



## Referencias 
 
- [Introdução​​ ao​​ CUDA, Davi Conte](https://edisciplinas.usp.br/pluginfile.php/4146828/mod_resource/content/1/MaterialCUDA.pdf)

