#include <complex>
#include <iostream>
#include <omp.h>
#include <sys/time.h>
using namespace std;

int main(){
	int max_row, max_column, max_n;
	cin >> max_row;
	cin >> max_column;
	cin >> max_n;
	int chunk=1;
	char **mat = (char**)malloc(sizeof(char*)*max_row);
  // iniciando tempo
  timeval start, end;
gettimeofday(&start, NULL);
	for (int i=0; i<max_row;i++)
		mat[i]=(char*)malloc(sizeof(char)*max_column);
	#pragma omp_set_num_threads(8)
	#pragma omp parallel for schedule(static, chunk) private(r)
	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c){
			complex<float> z;
			int n = 0;
			while(abs(z) < 2 && ++n < max_n)
				z = pow(z, 2) + decltype(z)(
					(float)c * 2 / max_column - 1.5,
					(float)r * 2 / max_row - 1
				);
			mat[r][c]=(n == max_n ? '#' : '.');
		}
	}
	#pragma omp_set_num_threads(8)
	#pragma omp parallel for private(r)
	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << mat[r][c];
		cout << '\n';
	}	
	  gettimeofday(&end, NULL);
  double runtime = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
printf("compute time: %.4f s\n", runtime);
}


