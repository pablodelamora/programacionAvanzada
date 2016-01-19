#include<stdio.h>
#include<stdlib.h>

#define N 3

typedef void (* menu_t)();

void opcion1();
void opcion2();
void opcion3();

int main (int argc, const char * argv[]){
    
    int opcion = -1;
    
    menu_t* opciones = (menu_t *) malloc(N * sizeof(menu_t));
    
    *opciones = opcion1;
    *(opciones+1) = opcion2;
    *(opciones+2)= opcion3;
    
    while (opcion!=0) {
        printf("1-Opcion 1\n1-Opcion 2\n1-Opcion 3\n");
        
        printf("Selecciona tu opcion: ");
        scanf("%d", &opcion);
        
        (*(opciones[opcion-1]))();
        
        /*switch(opcion){
            case 1: 
                opcion1();
                break;
            case 2:
                opcion2();
                break;
            case 3:
                opcion3;
                break;
            default:
                break;
        }*/
    }
    free(opciones);
    
    return 0;
}


void opcion1(){
    printf("Selecionaste la opcion 1\n");
}

void opcion2(){
    printf("Selecionaste la opcion 2\n");
}

void opcion3(){
    printf("Selecionaste la opcion 3\n");
}