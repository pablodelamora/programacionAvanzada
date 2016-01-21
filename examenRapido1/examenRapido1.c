#include <stdio.h>
#include <stdlib.h>

typedef void(* opcion_t) (int); 

struct persona {
    char *nombreComp;
    char nombreComp3[10];
    int edad;
};

#define N 4
void listarlos(int);
void agregarPersona(int);
void ordenarPorEdad(int);
void copiarABC(int);
void ordena(struct persona *, int (*)(int, int));
int asc(int, int);
int desc(int, int);


int numPers=0;
struct persona* lista;

int main(int argc, const char * argv[])
{
    
    
    //void(*)(int) *menu =();
    opcion_t * menu=((opcion_t*) malloc(N * sizeof(opcion_t)));
    
    *(menu)=listarlos;
    *(menu+1)=agregarPersona;
    *(menu+2)=ordenarPorEdad;
    *(menu+3)=copiarABC;
    

    
    int opcion=0;
    
    while (opcion != 4){
        printf("\n---Opciones---\n1-Lista\n2-Agregar Persona\n3-Ordenar\n4-Salir\nEscoge tu opción:  ");
    
    scanf("%d", &opcion);
    
    /*Apuntadores a funciones*/
    
    (*(menu+opcion-1))(opcion);
    }
    
    
    struct persona* copia = lista;
    for(;copia<(lista+numPers);++copia){
        free((lista+numPers-1)->nombreComp);
    }
    
    free(lista);
    free(menu);
    return 0;
}//Cierre de main


void listarlos(int opcion)
{
    printf("-------------------Listar------------------------\n");
    struct persona* p = lista;clea
    for (;p<(lista+numPers);++p){
        printf("Nombre: %s\nEdad: %d\n\n", p->nombreComp, p->edad);
    }
}


void agregarPersona(int opcion)
{
    numPers++;
    lista = (struct persona*) realloc(lista, numPers*sizeof(struct persona));
    (lista+numPers-1)->nombreComp= malloc(sizeof(char)*30);
    
    printf("\n Dame el nombre de la persona: ");
    scanf(" %[^\n]",(lista+numPers-1)->nombreComp);
    printf("\n Dame la edad de la persona: ");
    scanf("%d",&(lista+numPers-1)->edad);
    
}


void ordenarPorEdad(int opcion)
{
    int op=0;
    printf("1. Ordenar de menor a mayor\n2. Ordenar de mayor a menor\n");
    scanf("%d", &op);
    if (op==1){
        ordena(lista, asc);
    }
    if (op==2){
        ordena(lista, desc);
    }
}



void copiarABC(int opcion)
{
    printf("Saliendo\n");
}





void ordena(struct persona * lista, int criterio(int, int))
{
    int i, j, temp;
    char * temp2;
    temp2 = (char *) malloc(sizeof(char) * 30);
    struct persona* temp1;
    for(i = 0; i < numPers; ++i)
    {
        for(j = numPers-1; j > i; --j)
        {
            if (criterio((lista+j)->edad,(lista+j-1)->edad)) {
                temp = (lista+j-1)->edad;
                temp2 = (lista+j-1)->nombreComp;
                (lista+j-1)->edad = (lista+j)->edad;
                (lista+j-1)->nombreComp = (lista+j)->nombreComp;
                (lista+j)->edad = temp;
                (lista+j)->nombreComp = temp2;
            }
        }
    }
    free(temp2);
}


int asc(int a, int b)
{
    return a < b;
}

int desc(int a, int b)
{
    return b < a;
}



