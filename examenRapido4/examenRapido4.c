#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
        int num = atoi(argv[1]);
        int i;
        int aux1, aux2;

        int ** arrPipe = (int**)malloc(num*sizeof(int*));
        char token = 'A';

        for(i = 0; i < num; ++i) {
            *(arrPipe+i) = (int*)malloc(2*sizeof(int));
            pipe(*(arrPipe+i));
        }




        pid_t pid;
        for(i = 0; i < num-1; ++i) {
            pid = fork();
            if(pid == -1)
            {
                printf("Error al crear hijo\n");
                break;
            }
            else if(pid == 0) {
                if(i == num-2) {
                    aux1 = i+1;
                    aux2 = i;
                    close((*(arrPipe+aux1))[0]);
                    write((*(arrPipe+aux1))[1], &token, sizeof(char));
                    break;
                }
            }
            else {
                aux1 = i;
                if(i == 0){
                    aux2 = num-1;
                }
                else{
                    aux2 = i-1;
                }
                break;
            }
        }

        char tokenLeido;


        int loop=1;
        while(loop) {
            close((*(arrPipe+aux2))[1]);
            read((*(arrPipe+aux2))[0], &tokenLeido, sizeof(char));
            printf("Soy el proceso con PID %d y recibi el testigo %c el cual tendre por 5 segundos\n", getpid(), tokenLeido);
            sleep(5);

            close((*(arrPipe+aux1))[0]);
            write((*(arrPipe+aux1))[1], &tokenLeido, sizeof(char));
            printf("Soy el proceso con PID %d y acabo de enviar el testigo %c\n\n", getpid(), token);
        }




        for(i = 0; i < num; ++i) {
            free(*(arrPipe+i));
        }
        free(arrPipe);

        return 0;

}
