#include <stdlib.h>
#include <stdio.h>
#define N 5


typedef struct  {
    char * titulo;
    int paginas;
}Libro;

//typedef void (*iterator) ()
//typedef void (*t_int)(void*);
//typedef void (*arreglo)(void*);


//tipos de funciones
typedef void (*recorre)(void*);

//funciones genericas
void iterator(recorre, void* vector);

void forward(void*);
void backward(void*);
void bidirectional(void*);




Libro* libros;
int* arr;

int main (int argc, const char * argv[]){
    
    libros= (Libro*) malloc(N*sizeof(Libro));
    arr = (int*) malloc(N*sizeof(int));
    
    Libro* aux = libros;
    for(;aux<(libros+N);aux++){
        aux->titulo = (char*) malloc (sizeof(char)*20);
    }
    
    *arr=1;
    *(arr+1)=2;
    *(arr+2)=3;
    *(arr+3)=4;
    *(arr+4)=5;
    
    libros->titulo= "1";
    libros->paginas=10;
    libros->titulo= "2";
    libros->paginas=20;
    libros->titulo= "3";
    libros->paginas=30;
    libros->titulo= "4";
    libros->paginas=40;
    libros->titulo= "5";
    libros->paginas=50;
    
    
    
    iterator(&forward, arr);
    iterator(&backward, arr);
    iterator(&bidirectional, libros);
    
    for(;aux<(libros+N);aux++){
        free(aux->titulo);
    }
    
    free(libros);
    free(arr);
    
    return 0;
}


void iterator(recorre iter,void* vector){
    (*iter)(vector);
}


void forward(void* vector){
    int* aux =  vector;
    int* aux2= aux;
    
    for (;aux<(aux2+N);++aux){
         printf("%d\n", *((int*)aux));
     }
    

} 

void backward(void* vector){
    int* aux =  (vector);
    int* aux2=(aux+N-1);
    
    for (;aux2>=(aux);--aux2){
        printf("%d\n", *((int*)aux2));
    }
}

void bidirectional(void* vector){
    Libro* aux1= vector;
//    Libro* aux1= libros;
    Libro* aux2 = (aux1+N-1);
    
    printf("%s", aux1->titulo);
    printf("%s", aux2->titulo);
    
    aux1++;
    aux2--;
    
    
    printf("%s",aux1->titulo);
    printf("%s",aux2->titulo);
    
    
    
}





