#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void crearProceso(int nivelActual, int totalNiveles, int numProcesos);

int main(int argc, char *argv[]) {

  //char * nvalue;
  //char * pvalue;
  int nvalue;
  int pvalue;
  //char * pvalue=NULL;
  int c;

  while ((c = getopt(argc, argv, "n:p:")) != -1) {
        switch (c) {
            case 'n':
                nvalue = atoi(optarg);
                break;
            case 'p':
                pvalue = atoi(optarg);
                break;
            default:
                abort();
        }
  }



  int nivelActual=1;
  //totalNiveles = nvalue;
  //numProcesos = pvalue;

    crearProceso(nivelActual,nvalue, pvalue);
  //printf("La suma es: %d", (pvalue+nvalue));

    return 0;
}


void crearProceso(int nivelActual, int totalNiveles, int numProcesos) {
    if (totalNiveles+1 == nivelActual) exit(0);

    int i;
    int j;
    for (i = 0; i < numProcesos; ++i) {
        if (fork() == 0) {

          for(j=0;j<nivelActual;++j){
            printf("----");
          }
          printf("%d\n", getpid());

            crearProceso(nivelActual+1,totalNiveles, numProcesos);
            exit(0);
        } else {
            wait(NULL);
        }
    }
}
