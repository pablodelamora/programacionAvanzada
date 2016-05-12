#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <time.h>

#define N 8
#define P 1

void gestor_sigusr1 (int senial)
 {
printf("***(%d)*** se mando sigusr1 (señal número %d) \n", getpid(), senial);
sleep(2);
 }


int crearMapa(int arr[N][N]){
  int i;
  int j;
  int res = rand()%N;
  //printf("%d",res);

  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      arr[i][j]=0;
    }
  }

  for (i=0; i<N; i++){
    int rnd = rand()%N;
    int rnd2 = rand()%N;

    arr[rnd][rnd2]=1;
  }

    arr[res][res] = 2;

    for (i=0;i<N;i++){
      for (j=0;j<N;j++){
        printf("%d ",arr[i][j]);
      }
      printf("\n");
    }
    return res;
}


void resuelve(int arr[N][N],int cuadrante){
  int i=0;
  int tamCuadrantes = N/P;
  int inicio = cuadrante*(tamCuadrantes-1);
  printf("%d", inicio);
  int avanza= 0;;
  int actualx = inicio;
  int actualy = actualx;

  while(avanza!=tamCuadrantes){
    arr[inicio][inicio] = 3;
    if(arr[actualx+1][actualy+1]==0){
      actualx = actualx +1;
      actualy = actualy +1;
      arr[actualx][actualy] = 3;
      avanza = avanza+1;
    }
    else if(arr[actualx+1][actualy]==0){
      arr[actualx+1][actualy] == 3;
      actualx= actualx+1;
      arr[actualx+1][actualy] == 3;
      actualx = actualx+1;
      arr[actualx][actualy+1] == 3;
      actualy= actualy+1;
      arr[actualx][actualy+1] == 3;
      actualy= actualy+1;
      avanza = avanza+2;
    }
  }
}



int main() {

  srand ( time(NULL) );
  int arr[N][N];
  int res = crearMapa(arr);
  int tamCuadrantes = N/P;
  int cuadrantesNecesarios = res/tamCuadrantes;

  resuelve(arr, 1);

  printf("\n\n");

  int i,j;
  for (i=0;i<N;i++){
    for (j=0;j<N;j++){
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  //for ()





  return 0;
}
