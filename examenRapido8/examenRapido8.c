#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define cajerosGenerales 5
#define cajerosEmpresariales 3
#define numClientes 150
#define turnosMax 5


typedef struct{
  int id;
  int claseCliente;
} Cliente;

sem_t cajGeneral;
sem_t cajEmpresarial;

pthread_mutex_t mutex;

int contGeneral=0;
int contEmpresarial=0;

void * procesoGeneral(void*);
void * procesoEmpresarial(void*);

int main(int argc, const char * argv[]) {
  srand (time(NULL));

  sem_init(&cajGeneral, 0, 5);
  sem_init(&cajEmpresarial, 0, 3);

  pthread_t * hilos = (pthread_t *)malloc(sizeof(pthread_t)*numClientes);

  int clientesGenerales=101;
  int clientesEmpresariales=51;

  pthread_mutex_init(&mutex, NULL);

  Cliente* param;
  int i=0;
  for (i=0; i< numClientes; ++i){
    param = malloc (sizeof(Cliente));
    param->id = i;
    param->claseCliente = (rand()%2)+1;

    if (clientesGenerales == 0 && param->claseCliente == 1){
      param->claseCliente == 2;
    }

    if (clientesEmpresariales == 0 && param->claseCliente == 2){
      param->claseCliente == 1;
    }

    if ((param->claseCliente)==1){
        pthread_create((hilos+i),NULL, procesoGeneral,  (void *) param);
        clientesGenerales--;
    }
    else if((param->claseCliente)==2){
      pthread_create((hilos+i),NULL, procesoEmpresarial,  (void *) param);
      clientesEmpresariales--;
    }
  }

  for (i = 0; i < numClientes; ++i) {

    pthread_join(*(hilos+i), NULL);

    printf("--- Terminando el hilo %d ...\n", i);
  }
  sem_destroy(&cajGeneral);
  sem_destroy(&cajEmpresarial);
  free(hilos);
  free (param);

  return 0;
}


void * procesoGeneral(void* param){
  int tiempoLlegada, tiempoEspera;
  tiempoLlegada = (rand()%171)+50;
  printf("%d", tiempoLlegada);
  sleep(tiempoLlegada); //crea el numero aleatorio y espera a que lleguen los clientes
  int numCajero;

  if (contGeneral<=turnosMax){
    sem_wait(&cajGeneral);
    sem_getvalue(&cajGeneral, &numCajero);
    printf("El cajero General #%d atiende al id %d en una operacion de tipo %d", numCajero,((Cliente*)param)->id,((Cliente*)param)->claseCliente);
    tiempoEspera = (rand()%4)+2;
    sleep(tiempoEspera);
    pthread_mutex_lock(&mutex);
    contGeneral++;
    pthread_mutex_unlock(&mutex);
    sem_post(&cajGeneral);
  }
  else{
    sem_getvalue(&cajGeneral, &numCajero);
    sleep(3);
    pthread_mutex_lock(&mutex);
    contGeneral=0;
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

///////////////////////////////////////////////////////////////////////////////
void * procesoEmpresarial(void* param){
  int tiempoLlegada, tiempoEspera;
  tiempoLlegada = (rand()%251)+90;
  printf("%d", tiempoLlegada);
  sleep (tiempoLlegada);
  int numCajero;

  if(contEmpresarial<=turnosMax){
    sem_wait(&cajEmpresarial);
    sem_getvalue(&cajEmpresarial, &numCajero);
    printf("El cajero Empresarial #%d atiende al id %d en una operacion de tipo %d", numCajero,((Cliente*)param)->id,((Cliente*)param)->claseCliente);
    tiempoEspera = 1;
    sleep(tiempoEspera);
    pthread_mutex_lock(&mutex);
    contEmpresarial++;
    pthread_mutex_unlock(&mutex);
    sem_post(&cajEmpresarial);
  }
  else{
    sem_getvalue(&cajEmpresarial, &numCajero);
    sleep(3);
    pthread_mutex_lock(&mutex);
    contEmpresarial=0;
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}
