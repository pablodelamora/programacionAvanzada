#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
    
    pid_t pid;
    
    int estado;
    
    
    int num2;
    printf("Dame el numero de procesos que se desea crear: \n");
     scanf("%d", &num2);
     
    // printf("%d", num2);
    
    //printf("%d", num);
    int i;
    for (i=0; i<num2; ++i){
        pid = fork();
        
        /* De aquí en adelante lo ejecutan los dos procesos */
        if (pid == -1)
        {
            printf("Error al crear el proceso hijo, solo se pudieron crear %d procesos \n", i);
        }
        else if (pid == 0)
        {
            // Estamos en el hijo
            float prom = (getppid() + getpid()) /  (double)2;
            printf("Estamos en el proceso hijo con PID = %d y su padre es PPID = %d y el promedio es: %f\n\n", \
            getpid(), getppid(), prom);
            exit(0);
        }
        else {
            // Estamos en el padre
            // printf("Estamos en el proceso padre con PID = %d y su padre es PPID = %d \n", \
            getpid(), getppid());
            
            // Poner al padre a esperar que el hijo termine
            if (waitpid(pid, &estado, 0) != -1)
            {
                if (WIFEXITED(estado))
                    printf("Ya terminó el hijo con PID %d con valor de retorno %d \n", pid, WEXITSTATUS(estado));
            }
            
            //printf("Después del wait\n");
            
        }
        
    }
    
    /* Lo van a imprimir los dos procesos */
    printf("Ya se terminaron de crear los %d procesos. Estamos en el proceso con PID = %d y su padre es PPID = %d \n", \
    num2, getpid(), getppid());
  
    
    return 0;
}
