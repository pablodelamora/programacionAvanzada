#include <stdlib.h>
#include <stdio.h>
#define N 5


typedef struct  {
    
    char * titulo;
    
    int paginas;
    
}Libro;

//typedef void (*iterator) ()
//typedef void (*t_int)(void*)
;
typedef void (*arreglo)(void*);

void recorre(void*, size_t);



void iterator(recorre, void* vector, size_t size);




// void forward(void*);
// void backward(void*)
// void bidirectional(void*);



Libro* libros;
int* arr;

int main (int argc, const char * argv[]){
    
    libros= (Libro*) malloc(N*sizeof(Libro));
    arr = (int*) malloc(N*sizeof(int));
    
    
    
    
    
    
    
    return 0;
}


void 



