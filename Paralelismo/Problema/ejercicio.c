#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define N 5000


int main() {

  int i;
  float *x;
  float *y;
  int *c;

  x = (float*) malloc (sizeof(float)*N);
  y = (float*) malloc (sizeof(float)*N);
  c = (int*) malloc (sizeof(int)*N);

  for (i=0; i<N; ++i){
    *(x+i) = (float)rand()/(float)(RAND_MAX/1);
    if (i%50==0)
      printf("%d\n", *(x+i));
    *(y+i) = (float)rand()/(float)(RAND_MAX/1);
  }



  return 0;
}
