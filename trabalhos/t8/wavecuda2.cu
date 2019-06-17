
#include <stdio.h>
#include <stdlib.h>


__global__ void kernel(void){
    
    printf("Hello World!");
}

int main(void){
    
    kernel<<<1,1>>>();
    printf("Fim!");
    return 0;    
}