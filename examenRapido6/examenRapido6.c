#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int x = 0;
int y = 0;
int segundos = 3;
int aux = 0;

void gestor_ctrlc(int senial){

  if (senial==SIGINT){
   x++;
   segundos++;
  }

  else if(senial==SIGTSTP){
    y++;
    if(segundos>1)
        segundos--;
  }

}


void gestorAlarma(int a)
{
    printf("Aparezco cada %d segundos\n", segundos);
}

void gestorConts(int a)
{
    printf("Se ha pulsado %d veces CTRL+C y se ha pulsado %d veces CTRL+Z. Acabando…\n", x, y);
    aux = 1;
}

int main(int argc, char** argv)
{
    pid_t pid;

    pid = fork();

    if(pid == 0)  {
        signal(SIGINT, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);

        sleep(10);
        kill(getppid(), SIGUSR1);

    }
    else if(pid > 0)  {
        signal(SIGUSR1, gestorConts);
        signal(SIGTSTP, gestor_ctrlc);
        signal(SIGINT, gestor_ctrlc);
        signal(SIGALRM, gestorAlarma);



        while(aux == 0)
        {
            alarm(segundos);
            pause();
        }


        kill(0, SIGKILL);
    }


}
