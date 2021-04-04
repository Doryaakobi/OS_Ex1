#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    printf("main pid is: %d\n", getpid());

    char *args[] = {NULL};

    pid_t pid = fork();

    if (pid == 0)
    {

        execvp("./main2_1", args);
    }
    else
    {

        pid_t pid = fork();
        if (pid == 0)
        {
            execvp("./main2_2", args);
        }

        else
        {

            pid_t pid = fork();
            if (pid == 0)
            {
                execvp("./main2_3", args);
            }
        }

        // usleep(1000000);
        waitpid(pid, 0, WUNTRACED);

        return 0;
    }
}
