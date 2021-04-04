#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#define RUN 100

void print(char *str)
{
    int i;
    for (i = 0; i < RUN; i++)
    {
        printf("hello from %s (PID = %d)\n", str, getpid());
        usleep(100000);
    }
}

int main()
{

    pid_t pid = fork();

    printf("pid of parent = %d\n",pid);

    if(pid == 0){

        pid_t pid = fork();
        printf("pid of child = %d\n",pid);

        if(pid == 0){


            print("grand child");

            
        }else{
            print("child\n");
        }
    }else{
        print("father\n");
    }

    return 0;
}
