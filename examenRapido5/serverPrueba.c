#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define TCP_PORT 8000




int main(int argc, const char * argv[]) {

    struct sockaddr_in direccion;
    char buffer[1000];

    int servidor, cliente;

    int leidos, escritos;

    if (argc != 2) {
        printf("Error. Use: %s A.B.C.D \n", argv[0]);
        exit(-1);
    }

    //Crear el socket
    servidor = socket(PF_INET, SOCK_STREAM, 0);

    // Enlace con el socket
    direccion.sin_port = htons(TCP_PORT);
    direccion.sin_family = AF_INET;
    inet_aton(argv[1], &direccion.sin_addr);

    bind(servidor, (struct sockaddr *) &direccion, sizeof(direccion));

    // Escuchar a los clientes
    listen(servidor, 10);

    // Comunicación
    socklen_t tamano = sizeof(direccion);

    cliente = accept(servidor, (struct sockaddr *) &direccion, &tamano);

    //int fact;
    printf("AAAAAAA");

    if (cliente >= 0) {
        printf("Aceptando conexiones en %s:%d \n",
               inet_ntoa(direccion.sin_addr),
               ntohs(direccion.sin_port));

        // Leer de socket y escribir en pantalla
        while (1) {
            int count;
            int *reads;

            read(cliente, &count, sizeof(int));

            reads = malloc(sizeof(int) * count);

            read(cliente, &reads, sizeof(int) * count);

            int *current;
            int *end = reads + count;

            int mayor=0;
            int menor=0;
            int promedio=0;

            for (current = reads; current != end; ++current) {
                if (*current > mayor){
                  mayor = *current;
                }
                if (*current < menor){
                  menor = *current;
                }
                promedio = promedio + *current;
            }
            promedio = promedio/ count;

        printf("Mayor: %d\nMenor: %d\n Promedio: %d", mayor, menor, promedio);
        //printf("Hola");
        free(reads);

        }
    //    }
    }
    else {
      printf("Error");
    }

    // Cerrar el socket

    close(servidor);
    close(cliente);

    return 0;
}
