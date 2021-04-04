#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sched.h>
#include <syslog.h>


int main(){

    pid_t pid = fork();

    if(pid ==0){


        // redirecting to root 
        chdir("/");
        //
        setsid();

        printf("My Daemon proccess\n");

        close(stdout);
        close(stdin);
        close(stderr);

        openlog("log.txt",LOG_PID,LOG_DAEMON);
        syslog(LOG_NOTICE,"daemon started..\n");
        usleep(1000000);
        syslog(LOG_NOTICE,"doing something..\n");
        usleep(1000000);
        syslog(LOG_NOTICE,"work is done..\n");




    }


    return 0;
}

