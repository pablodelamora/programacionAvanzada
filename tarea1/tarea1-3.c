#include<stdio.h>
#include<stdlib.h>

#define N 7

typedef void (* menu_t)();

typedef struct{
    char* nombreComp;
    char* telefono;
    int edad;
    int camaAsignada;
}persona;

/*typedef struct{
    persona* paciente;
    int status;
    char* status2;
    
}hospital;*/
void inicializaCamas();
void opcion1();
void imprimeCamas();
void buscarPorCama();
void darDeAlta();
void listarPacientes();
void clasificaCamas();
void salir();

int numPers=0;
int numCamas=5;

int* abc;
persona* lista;


int main (int argc, const char * argv[]){
    
    int opcion = -1;
    
    abc = (int*) malloc (numCamas*sizeof(int));
    //abc = (hospital*) malloc (numCamas*sizeof(hospital));
    //hospital* prueba = abc;
    //for (;prueba<(abc+numCamas);++prueba){
    //    prueba->status=0;
    //    
    //}
    inicializaCamas();
 //   imprimeCamas();
    
    
    
    menu_t* opciones = (menu_t *) malloc(N * sizeof(menu_t));
    
    *opciones = opcion1;
    *(opciones+1) = imprimeCamas;
    *(opciones+2)= buscarPorCama;
    *(opciones+3)= darDeAlta;
    *(opciones+4)= listarPacientes;
    *(opciones+5)= clasificaCamas;
    *(opciones+6)= salir;
    
    while (opcion!=7) {
        
        if (numPers>=numCamas){
            numCamas= numCamas+5;
            abc = (int*) realloc(abc,numCamas*sizeof(int));
        }
        
        printf("1-Agregar Persona \n2-Ver Disponibilidad de Camas 2\n3- Buscar por cama\n4- Dar de alta paciente\n5- Listar pacientes del hospital\n6- Clasifica Camas\n7- Salir\n");
        
        printf("Selecciona tu opcion: ");
        scanf("%d", &opcion);
        
        (*(opciones[opcion-1]))();
        
    }
    free(abc);
    free(lista);
    free(opciones);
    
    return 0;
}


void opcion1(){
    int opcionCama;
    numPers++;
    lista = (persona*) realloc(lista, numPers*sizeof(persona));
    (lista+numPers-1)->nombreComp= malloc(sizeof(char)*30);
    (lista+numPers-1)->telefono= malloc(sizeof(char)*10);
    printf("\n Dame el nombre de la persona: ");
    scanf(" %[^\n]",(lista+numPers-1)->nombreComp);
    printf("\n Dame la edad de la persona: ");
    scanf("%d",&(lista+numPers-1)->edad);
    printf("\n Dame el telefono de la persona: ");
    scanf(" %[^\n]",(lista+numPers-1)->telefono);
    imprimeCamas();
    printf("Escoge el # de alguna cama(0-disponible, 1-ocupada):");
    scanf("%d", &opcionCama);
//     printf("prueba");
//     opcionCama=1;
    
 //   printf("%d", *(abc+opcionCama-1));
    
     while(*(abc+opcionCama-1)!=0){
         printf("Cama ocupada. Selecciona otro numero: ");
         scanf("%d", &opcionCama);
     }
     
     *(abc+opcionCama-1)=1;
     
     (lista+numPers-1)->camaAsignada = opcionCama;
    
//    printf("prueba");
    

    
    
    
}

void imprimeCamas(){
    printf("Camas: \n");
    int* aux = abc;
    int aux1=1;
    for (;aux<(abc+numCamas);++aux){
        printf("Estado de cama # %d: %d\n", aux1, *(aux));
        aux1++;
    }
 //   printf("%d");
}




void opcion3(){
    printf("Selecionaste la opcion 3\n");
}

void inicializaCamas(){
    int* aux = abc;
    for (; aux<(abc+numCamas); ++aux){
        *(aux) = 0;
    }
}



void buscarPorCama(){
    persona* aux = lista;
    int numCam;
    printf("\nDame el numero de cama deseado: ");
    scanf("%d",&numCam );
    
    for (;aux<(lista+numPers);++aux){
//        printf("%d", aux->camaAsignada);
        if ((aux->camaAsignada)==numCam){
            printf("\nLa cama #%d esta ocupada por %s\n\n", numCam, aux->nombreComp);
            return;
        }
    } 
    printf("\nLa cama #%d esta disponible.\n\n", numCam);
    
    
}


void darDeAlta(){
    persona* aux = lista;
    int numCam;
    printf("Dame el numero de cama: ");
    scanf("%d", &numCam);
    
    
    for (;aux<(lista+numPers);++aux){
//        printf("%d", aux->camaAsignada);
        if ((aux->camaAsignada)==numCam){
            printf("\nEl paciente %s ha sido dado de alta. Cama %d ahora disponible.\n\n", aux->nombreComp, numCam);
            *(abc+numCam-1)=0;
            aux->camaAsignada=0;
//            printf("\nLa cama #%d esta ocupada por %s\n\n", numCam, aux->nombreComp);
            return;
        }
        
    
    }
    printf("La cama seleccionada esta vacia\n\n");

}


void listarPacientes(){
    persona* aux = lista;
    for (;aux<(lista+numPers);++aux){
        printf("\nNombre:\t\t Edad \t Telefono \t\t # Cama\n\n");
        if ((aux->camaAsignada)>0){
            //printf("\nNombre:\t Edad \t Telefono \t # Cama\n\n");
            printf("%s \t %d \t %s \t\t %d \n\n", aux->nombreComp, aux->edad, aux->telefono, aux->camaAsignada);
        }
    }
    
}



void clasificaCamas(){
    int vacias=0, ocupadas=0;
    int* aux = abc;
    for (; aux<(abc+numCamas);aux++){
        if (*aux==0)
            vacias=vacias+1;
        else 
            ocupadas=ocupadas+1;
    }
    printf ("Numero de camas vacias: %d\nNumero de camas llenas: %d \n", vacias, ocupadas);
        
}


void salir(){
    persona* aux = lista;
    for (;aux<(lista+numPers);++aux){
        free(aux->nombreComp);
        free(aux->telefono);
    }
    
}