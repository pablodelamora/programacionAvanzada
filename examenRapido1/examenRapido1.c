//Pablo de la Mora
//Examen Rapido uno

#include <stdio.h>
#include <stdlib.h>
#define N 4




int numPers=0;


int main(int argc, const char * argv[])
{
    char * cadena;
    int *count;
    int longitud;
    
    printf("Dame la longitud máxima: ");
    scanf("%d", &longitud);
    
    cadena = (char *) malloc(sizeof(char) * longitud);
    count = (int*) malloc (sizeof(int)*26);
    
    printf("Entre una cadena: ");
    //scanf("%s", cadena);
    scanf(" %[^\n]",cadena);
    
//    printf("%d", *count);
    
    char*copia = cadena;
    while (*copia != '\0'){
    
    
    if(*copia>='a' && *copia<='z'){
          count[*copia-'a']++;
    }
    copia++;
    }
    
    int* c= count;
    for (;c<(count+26);c++){
        if (*c != 0){
        printf("%c occurs %d times ", ((c-count)+'a'),  (*c));
        int i=0;
        for (i=0; i<*c;i++){
            printf("*");
        }
        printf("\n");
        cadena++;
        }
    }
    
    
    
    
    
  //  free (count);
  //  free(cadena);
    return 0;
}//Cierre de main



