#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longitudCadena (char*);

int main(int argc, const char * argv[]) {
    
    char* cadena;
    int longitud;
    
    printf("Dame la longitud: ");
    scanf("%d", &longitud);
    
    cadena = (char*) malloc (sizeof(char)*longitud);
    
    printf("Entra la cadena: ");
     scanf(" %[^\n]", cadena);

    longitudCadena(cadena);
    
    printf("Cadena original: %s \n", cadena);
    
    free (cadena);
    
    return 0;
}



void longitudCadena(char* cadena){
        int cont=0;
	while ((*cadena++)!='\0'){
             cont++;
        }
        printf("Longitud: %d", cont);
}
