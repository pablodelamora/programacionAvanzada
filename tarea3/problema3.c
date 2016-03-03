#include	<stdlib.h>
#include    <stdio.h>
#include    <signal.h>
#include    <sys/types.h>
#include    <unistd.h>
#include    <string.h>

void gestor(int);

int aux=0;

int main(int argc, char** argv){
  if (argc != 2){
  		printf("Numero de argumentos no valido\n");
  		abort();
  	}
    else {
      int num = atoi(argv[1]);

      if (num<5 || num>9){
        printf("Numero no valido\n");
        return 0;
      }
      signal(SIGALRM, gestor);
      signal(SIGINT, SIG_IGN);

      int * arr = (int *)malloc(num*sizeof(int));

      alarm(3);
      int i;
      for(i=0; i<num;++i){
        if (!aux){
          printf("Dato %d: ", i);
        }
        else {
          printf("Date prisa. Dato %d: ", i);
        }
        scanf("%d", (arr+i));
      }

      int * a;
      a= arr;

      for(;a<arr+num;a++){
        printf("%d ", *a);
      }
      free(arr);

    }

  return 0;
}

void gestor (int senial){
  aux = 1;
}
