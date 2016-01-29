#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 7
#define P 10
#define R 7

typedef void (* menu_t)();


typedef struct {
    int p1;
    int p2;
    int p3;
    int p4;
    int p5;
    int p6;
    int p7;
    int p8;
    int p9;
    int p10;   
} respPersona; 


typedef struct {
    char* pregunta;
    //respuestas* resp;
    char* res1;
    char* res2;
    char* res3;
    char* res4;
    char* res5;
    char* res6;
    
    int* contResps;
}pregCompleta;



typedef struct {
    int edad;
    char * nombre;
    respPersona* respuestas;
} persona; 


void agregarPersona();
void crearEncuesta();
void imprimirPreguntas();
void imprimirPersonas();
void generarEncuesta();
void infograma();
void salir();

int numPers=0;
int numPregs=0;
time_t t;
int frequencia[10][6];

//srand((unsigned) time(&t));

persona* listaPersonas;
pregCompleta* encuestaFinal;





int main (int argc, const char * argv[]){
    
    srand (time(NULL));
   // printf("%d\n", rand() % 6);
    
    int opcion = -1;
    menu_t* opciones = (menu_t *) malloc(N * sizeof(menu_t));
    
    *opciones = agregarPersona;
    *(opciones+1) = crearEncuesta;
    *(opciones+2)= imprimirPreguntas;
    *(opciones+3)= imprimirPersonas;
    *(opciones+4)= generarEncuesta;
    *(opciones+5)= infograma;
    *(opciones+6)= salir;
    
    while (opcion!=7) {
        printf("\n1-Agregar Persona \n2-Crear Encuesta 2\n3-Imprimir Encuesta\n4- Imprimir Personas\n5- Realizar Encuesta\n6- Imprimir Resultados\n7- Salir\n");
        
        printf("Selecciona tu opcion: ");
        
        scanf("%d", &opcion);
                
        (*(opciones[opcion-1]))();
    }
    free(listaPersonas);
    free(encuestaFinal);
    free(opciones);
    
    return 0;
}


void agregarPersona()
{
    numPers++;
    listaPersonas = (persona*) realloc(listaPersonas, numPers*sizeof(persona));
    (listaPersonas+numPers-1)->nombre= (char*)malloc(sizeof(char)*30);
    printf("\n Dame el nombre de la persona: ");
    scanf(" %[^\n]",(listaPersonas+numPers-1)->nombre);
    printf("\n Dame la edad de la persona: ");
    scanf("%d",&(listaPersonas+numPers-1)->edad);
    while (((listaPersonas+numPers-1)->edad>119) || ((listaPersonas+numPers-1)->edad<18)){
        printf("\n No entra en el rango. Dame otra vez la edad de la persona: ");
        scanf("%d",&(listaPersonas+numPers-1)->edad);
    }
}


void crearEncuesta(){
    
    numPregs=0;
    
    encuestaFinal= (pregCompleta*) malloc(sizeof(pregCompleta)*P);
    pregCompleta* temp = encuestaFinal;
    
//    while(numPregs<3){
    
    for(; temp<(encuestaFinal+P);++temp){
        (temp)->pregunta=(char*)malloc(sizeof(char)*100);
 //       (encuestaFinal+numPregs)->pregunta = "Putos";
        //printf("Pregunta 1 %s", (temp)->pregunta);
        printf("\nPregunta %d: ", numPregs+1);
        scanf(" %[^\n]",(temp)->pregunta);
        
        (temp)->res1=(char*)malloc(sizeof(char)*100);
        printf("\nRespuesta 1: ");
        scanf(" %[^\n]",(temp)->res1);
        
        (temp)->res2=(char*)malloc(sizeof(char)*100);
        printf("\nRespuesta 2: ");
        scanf(" %[^\n]",(temp)->res2);
        
        (temp)->res3=(char*)malloc(sizeof(char)*100);
        printf("\nRespuesta 3: ");
        scanf(" %[^\n]",(temp)->res3);
        
        (temp)->res4=(char*)malloc(sizeof(char)*100);
        printf("\nRespuesta 4: ");
        scanf(" %[^\n]",(temp)->res4);
        
        (temp)->res5=(char*)malloc(sizeof(char)*100);
        printf("\nRespuesta 5: ");
        scanf(" %[^\n]",(temp)->res5);
        
        (temp)->res6=(char*)malloc(sizeof(char)*100);
        printf("\nRespuesta 6: ");
        scanf(" %[^\n]",(temp)->res6);
               

        
        
 //   }
        numPregs++;
    }
    
/*    numPregs=0;
   while(numPregs<10){
       printf("%s\n", (encuestaFinal+numPregs)->pregunta);
       printf("%s\n", (encuestaFinal+numPregs)->res1);
       printf("%s\n", (encuestaFinal+numPregs)->res2);
       printf("%s\n", (encuestaFinal+numPregs)->res3);
       printf("%s\n", (encuestaFinal+numPregs)->res4);
       printf("%s\n", (encuestaFinal+numPregs)->res5);
       printf("%s\n", (encuestaFinal+numPregs)->res6);
    numPregs++;
    */
    
//}

}


void imprimirPreguntas(){
    numPregs=0;
    while(numPregs<10){
        printf("Pregunta %d : %s\n", numPregs,(encuestaFinal+numPregs)->pregunta);
        printf("1: %s\n", (encuestaFinal+numPregs)->res1);
        printf("2: %s\n", (encuestaFinal+numPregs)->res2);
        printf("3: %s\n", (encuestaFinal+numPregs)->res3);
        printf("4: %s\n", (encuestaFinal+numPregs)->res4);
        printf("5: %s\n", (encuestaFinal+numPregs)->res5);
        printf("6: %s\n", (encuestaFinal+numPregs)->res6);
        numPregs++;
        
    }
}





void imprimirPersonas(){
    persona* aux=listaPersonas;
    for(;aux<(listaPersonas+numPers);++aux){
        printf("Nombre: %s\n", aux->nombre);
        printf("Edad: %d\n\n", aux->edad);
        
    }
}






void generarEncuesta(){
   // numPers=0;
  //  temp->contResps=(int*)malloc(sizeof(int)*6);
    
    persona* aux=listaPersonas;
    for(;aux<(listaPersonas+numPers);++aux){
        aux->respuestas= (respPersona*) malloc(sizeof(respPersona)*1);
  //      numPregs=0;
  //      while(numPregs<10){
            aux->respuestas->p1=  ((rand() % 6)+1);
            printf("%d", aux->respuestas->p1);
            aux->respuestas->p2=  (rand() % 6)+1;
            aux->respuestas->p3=  (rand() % 6)+1;
            aux->respuestas->p4=  (rand() % 6)+1;
            aux->respuestas->p5=  (rand() % 6)+1;
            aux->respuestas->p6=  (rand() % 6)+1;
            aux->respuestas->p7=  (rand() % 6)+1;
            aux->respuestas->p8=  (rand() % 6)+1;
            aux->respuestas->p9=  (rand() % 6)+1;
            aux->respuestas->p10=  (rand() % 6)+1;
 //           printf("%d", aux->respuestas->p1);

    //        numPers++;
  //      }
        
        
    }
}



void infograma(){
    
    //  temp->contResps=(int*)malloc(sizeof(int)*6);
    
    persona* aux=listaPersonas;
    for(;aux<(listaPersonas+numPers);++aux){

        (frequencia[0][(aux->respuestas->p1)-1])++;
        (frequencia[1][(aux->respuestas->p2)-1])++;
        (frequencia[2][(aux->respuestas->p3)-1])++;
        (frequencia[3][(aux->respuestas->p4)-1])++;
        (frequencia[4][(aux->respuestas->p5)-1])++;
        (frequencia[5][(aux->respuestas->p6)-1])++;
        (frequencia[6][(aux->respuestas->p7)-1])++;
        (frequencia[7][(aux->respuestas->p8)-1])++;
        (frequencia[8][(aux->respuestas->p9)-1])++;
        (frequencia[9][(aux->respuestas->p10)-1])++;

    }

    int i=0, j=0;
    for (i=0; i<10;i++){
        for (j=0; j<7;j++){
            printf("Pregunta %d- Respuesta %d : %d \n",i,j,frequencia[i][j]);
        }
    }
    
    

    
}


void salir(){
    persona* aux=listaPersonas;
    for(;aux<(listaPersonas+numPers);++aux){
        free(aux->nombre);
        free(aux->respuestas);
    }
    
    numPregs=0;
    while(numPregs<10){
        free((encuestaFinal+numPregs)->pregunta);
        free((encuestaFinal+numPregs)->res1);
        free((encuestaFinal+numPregs)->res2);
        free((encuestaFinal+numPregs)->res3);
        free((encuestaFinal+numPregs)->res4);
        free((encuestaFinal+numPregs)->res5);
        free((encuestaFinal+numPregs)->res6);
   
        numPregs++;
        
    }
}



