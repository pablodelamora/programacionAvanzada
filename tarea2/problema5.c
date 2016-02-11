#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//int execl (const char *filename, const char *arg0);

int main(int argc,  char * argv[]) {

    int nvalue;
    char *pvalue = NULL;
    int c;
    pid_t pid;

    opterr = 0;

    while ((c = getopt (argc, argv, "n:p:")) != -1)
        switch (c)
    {
        case 'n':
            nvalue = atoi(optarg);
            break;
        case 'p':
            pvalue = optarg;
            break;
        default:
            abort ();
    }

  //    printf("%s %d\n", pvalue, nvalue);
    int i;
    for (i=0;i<nvalue; ++i){
        system(pvalue);
    }
    wait(NULL);
    return 0;

}
