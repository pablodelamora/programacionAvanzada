#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>


#define numFumadores 3

int fumando[numFumadores];
int recursos[3];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* agenteT (void* a){
  int enUso = 1;
  int i;

  while (1){
    for (i=0;i<numFumadores; ++i){
      pthread_mutex_lock(&mutex);

      if (!fumando[i]){
        pthread_mutex_unlock(&mutex);
        enUso = 0;
        sleep(15);
        pthread_mutex_lock(&mutex);
        recursos[i]=1;
        if (i==0)
          printf("Cerillos\n");
        else if (i==1)
          printf("Papel\n");
        else if (i==2)
          printf("Cerillos\n");
      }

      pthread_mutex_unlock(&mutex);
    }
    if (enUso){
      printf("Se va a hacer otras cosas el agente");
      sleep(10);
    }
  }
}


void* fumador (void* a){
  int id = (intptr_t) a;
  while (1){
    pthread_mutex_lock(&mutex);
    if (recursos[0] && recursos[1] && recursos[2]) {
			recursos[0] = 0;
      recursos[1] = 0;
      recursos[2] = 0;
			fumando[id] = 1;

			printf("Fumador %d consiguio los materiales y esta fumando\n", id);
			pthread_mutex_unlock(&mutex);
			sleep(10);
			printf("Fumador %d terminó de fumar\n", id);
			pthread_mutex_lock(&mutex);
			fumando[id] = 0;
			pthread_mutex_unlock(&mutex);
			sleep(20);
		}
		else
			pthread_mutex_unlock(&mutex);
	}
}




int main ( int argc, char *argv[] ){

  int i;

  pthread_t agente;
  pthread_create(&agente, NULL, agenteT, NULL);

  pthread_t fumadores[numFumadores];
  for (i = 0; i < numFumadores; ++i){
		pthread_create(&fumadores[i], NULL, fumador, (void*) (intptr_t) i);
  }
  for (i = 0; i < numFumadores; ++i){
    pthread_join(fumadores[i], NULL);
  }

  pthread_join(agente, NULL);

  return 0;
}
