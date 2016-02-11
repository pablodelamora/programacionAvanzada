#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main ( int argc, char *argv[] ){
    int num;
    pid_t pid;
    pid_t pid2;
    int status;

    printf("Dame la cantidad de hijos a crear: ");
    scanf("%d", &num);

    //srand((int) time(NULL));

int i;
 for (i = 0; i < num; ++i) {
    int status;
    pid2 = fork();
    srand(time(NULL) ^ (getpid()<<1));

    if (pid2 == -1){
      printf("Error");
    }
    if (pid2== 0){
        sleep(rand() % 20);
        exit(0);
    }
 }

 printf("El orden en que los procesos terminaron fue: \n\n");
 while ((pid = wait(&status)) > 0) {
     printf("Pid: %d\n", pid);
 }

    return 0;
}
