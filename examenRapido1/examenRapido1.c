//Pablo de la Mora
//Examen Rapido uno

#include <stdio.h>
#include <stdlib.h>
#define N 4

void ordena(char*, int *, int (*)(int, int));
int asc(int, int);
int desc(int, int);


int numPers=0;


int main(int argc, const char * argv[])
{
    char *letras;
    char * cadena;
    int *count;
    int longitud;
    
    printf("Dame la longitud máxima: ");
    scanf("%d", &longitud);
    
    cadena = (char *) malloc(sizeof(char) * longitud);
    letras = (char*) malloc (sizeof(char)*26);
    count = (int*) malloc (sizeof(int)*26);
    
    char* ayuda = letras;
    for (;ayuda<(letras+26);ayuda++){
     
        *ayuda=(ayuda-letras)+'a';
        printf("%c",*ayuda);
    }
    
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
    
    
    ordena(letras,count,asc);
    
    
    int* c= count;
    for (;c<(count+26);c++){
        if (*c != 0){
            printf("%c occurs %d times ", (*letras),  (*c));
        //printf("%c occurs %d times ", ((c-count)+'a'),  (*c));
        int i=0;
        for (i=0; i<*c;i++){
            printf("*");
        }
        printf("\n");
//        cadena++;
        }
        letras++;
    }
    
    
    free(letras);
    free (count);
    free(cadena);
    return 0;
}//Cierre de main






//////
void ordena(char * letras,int * numeros, int criterio(int, int))
{
    int i, j, temp;
    char temp1;
    
    for(i = 0; i < N; ++i)
    {
        for(j = N-1; j > i; --j)
        {
            if (criterio(numeros[j],numeros[j-1])) {
                
                printf("%d",numeros[j-1]);
                temp = numeros[j-1];
                temp1=letras[j-1];
                
                numeros[j-1] = numeros[j];
                letras[j-1] = letras[j];
                
                numeros[j] = temp;
                letras[j]=temp1;
                printf("-- %d\n",numeros[j-1]);
            }
        }
    }
}

int asc(int a, int b)
{
    return a < b;
}

int desc(int a, int b)
{
    return b < a;
}


