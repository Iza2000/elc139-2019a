

#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include "wave.h"

//função kernel que faz as frames
__global__
void fazPixel(int width, int frames, unsigned char* pic)
{
  int ix = threadIdx.x;
  int of = blockDim.x;
  for (int frame = ix; frame < frames; frame += ofs) {
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

int main(int argc, char *argv[])
{

  if (argc != 3) {fprintf(stderr, "usage: %s frame_width num_frames\n", argv[0]); exit(-1);}
  int width = atoi(argv[1]);
  if (width < 100) {fprintf(stderr, "error: frame_width must be at least 100\n"); exit(-1);}
  int frames = atoi(argv[2]);
  if (frames < 1) {fprintf(stderr, "error: num_frames must be at least 1\n"); exit(-1);}
  printf("computing %d frames of %d by %d picture\n", frames, width, width);
  
  unsigned char* pic;
  cudaMallocManaged(&pic, frames*width*width*sizeof(unsigned char));
    
  // iniciando tempo
  timeval start, end;
  gettimeofday(&start, NULL);

  fazPixel<<<1, frames>>>(width, frames, pic);

  cudaDeviceSynchronize();

  // terminando contagem de tempo
  gettimeofday(&end, NULL);
  double runtime = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
  printf("compute time: %.4f s\n", runtime);

  if ((width <= 256) && (frames <= 100)) {
    for (int frame = 0; frame < frames; frame++) {
      char name[32];
      sprintf(name, "wave%d.bmp", frame + 1000);
      writeBMP(width, width, &pic[frame * width * width], name);
    }
  }

  cudaFree(pic);
  return 0;
}