#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

#define numFilosofos 5
#define Tenedores 4
#define Cuchillos 3
#define cupo 4


int filosofos;
int i;

sem_t sillas;
sem_t cuchillos;

void *filosofo(int a){
  printf("%d Esperando... \n", a);
  sem_wait(&sillas);
  printf("%d Esperando cuchillo... \n", a);
  sem_wait(&cuchillos);
  printf("%d Comiendo... \n", a);
  sleep(3);
  sem_post(&cuchillos);
  sem_post(&sillas);
  printf("%d ha terminado y se va \n", a);
  pthread_exit((void *)a);
}


int main ( int argc, char *argv[] ){

  sem_init(&sillas, 0, cupo);
  sem_init(&cuchillos, 0, Cuchillos);
  pthread_t fil[numFilosofos];

  for (i=0;i<numFilosofos;++i){
    printf("Creando filosofo... \n");
    pthread_create(&fil[i], 0, (void*(*)(void*))filosofo, (void*)i);
  }
  pthread_t *aux;
  for (aux = fil; aux < (fil+numFilosofos); ++aux){
    pthread_join(*aux, NULL);
  }
  return 0;
}
