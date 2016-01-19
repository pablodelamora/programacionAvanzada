#include <stdio.h>
#include <stdlib.h>


	
struct persona {
	char nombre[25];
	char apellido[25];
	int edad;
}; 	




int main(){

    int n,i,edadProm=0, edadJoven=200, edadViejo=0;
    struct persona* ptr;
    printf("Enter number of people: ");
    scanf("%d",&n);
    ptr=(struct persona*)malloc(n*sizeof(struct persona));

    if(ptr==NULL){
        printf("Error! memory not allocated.");
        exit(0);
    }
  

    for(i=0;i<n; i++){
	printf("Nombre, apellido y edad ");
        scanf("%s",&(ptr+i)->nombre);
        scanf("%s",&(ptr+i)->apellido);
	scanf("%d",&(ptr+i)->edad);

	edadProm = (edadProm+(ptr+i)->edad);
	if (edadJoven>(ptr+i)->edad){
	    edadJoven=(ptr+i)->edad;
	}
	if (edadViejo<(ptr+i)->edad){
	    edadViejo=(ptr+i)->edad;
	}
    }

    edadProm = edadProm/n;

    printf("\nPromedio: %d", edadProm);
    printf("\nJoven: %d", edadJoven);
    printf("\nViejo: %d", edadViejo);

 //   printf("Sum=%d",sum);
    free(ptr);
    return 0;
}

