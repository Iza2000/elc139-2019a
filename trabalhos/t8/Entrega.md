
# T8: Geração de Imagem em Paralelo com CUDA

#### Nome: Gabriela Luisa Eckel
#### Disciplina: Programação Paralela

## Parte 1

Para paralelizar criei uma função kernel no for, que utiliza o numero de frames para criar o numero de threads. 
~~~java
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
E para medir seu tempo utilizei a biblioteca sys/time.h na função assim. 
Para a analise, comparei o programa sequencial [wave.c](wave.c), com a sua versão paralelizada[wavecuda1.cu](wavecuda1.cu).

Tempo em MS| 1024 100 | 1024 200 | 2048 100 | 2048 200 
---|---------|----------|----------|-----------
Paralelo|9,4128ms|17.29366ms|34.42861ms|65.34582ms
Sequencial| 53.53100ms|105.340000ms |210.847000ms | 421.674000ms
 
Acredito que o resultado é o esperado pois os tempos vão subindo de acordo com a quantidade de frames, e diminuiram com  a paralelização. Pelos resultados, nota-se que CUDA é uma otima ferramenta, pois o tempo utilizando CUDA foram bem menores, praticamente a metade. 

## Parte 2 


xxxxx|    524   |    1024    |   2048   |    4068  
-----|----------|------------|----------|----------
32   |3.251136ms|3.395616ms  |12.61853ms|185.2839ms
64   |9.784736ms|6.874368ms  |24.14803ms|317.3417ms

Analisando os resultados, percebi que os tempos variam bastante, mas normalmente crescem quando se trata de numeros grandes, o que era esperado. Me surpreendi um pouco com o resultado da execução 1024 x 64 pois o resultado foi melhor que o esperado.

## Referencias 
 
- [Introdução​​ ao​​ CUDA, Davi Conte](https://edisciplinas.usp.br/pluginfile.php/4146828/mod_resource/content/1/MaterialCUDA.pdf)
- [O que é cuda?, Pedro Cipoli](https://canaltech.com.br/hardware/O-que-e-a-CUDA/)
- [Cuda em ação](https://www.nvidia.com.br/object/cuda_in_action_br.html)
- [O que são nucleos CUDA?](https://www.techtudo.com.br/noticias/noticia/2017/04/o-que-sao-nucleos-cuda-nas-placas-da-nvidia.html)
