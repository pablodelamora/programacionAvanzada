#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>

#define N 5
#define T 3

int grabar;
void creaDestruyeDirectorio();
void temporizador(int);

int main(int argc, const char * argv[])
{
	signal(SIGALRM, temporizador);
    creaDestruyeDirectorio();

	int i, fd, len = ((N-1) / 10) + 9;
	char* buffer = (char*) malloc(len * sizeof(char));
	struct stat st;

	for (i = 0; i < N; ++i) {
		grabar = 1;
		snprintf(buffer, len, "Datos/a%d", i);
		fd = open(buffer, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

		alarm(T);
		while (grabar)
			write(fd, "x", sizeof(char));

		fstat(fd, &st);
		printf("a%d   %d\n", i, (int)st.st_size);

		close(fd);
	}

	free(buffer);
	return 0;
}

void temporizador(int s) {
	grabar = 0;
}

void creaDestruyeDirectorio() {
  char da[7] = "Datos/\0";
	DIR* dir = opendir("Datos");
	if (dir) {
///////////////////////////////////////////////
    DIR * d = opendir("Datos");
    struct dirent * dir;
    char * res;

    while((dir = readdir(d)) != NULL)
    {
        if(dir->d_type == DT_REG)
        {
            res = (char*)malloc((strlen(da)+strlen(dir->d_name)+1)*sizeof(char));
            strcpy(res, da);
            strcat(res, dir->d_name);
            unlink(res);
            free(res);
        }
    };
    printf("Se borro el contenido de Datos\n");
	}

  else{
  mkdir("Datos", 0777);
  printf("Se creo el directorio Datos\n");
  }
}
