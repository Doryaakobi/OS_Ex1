#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sched.h>
#define RUN 1000000
#define STACK_SIZE 10000
char brother_stack[STACK_SIZE+1];

void print(const char *str)
{
    int i;
    for (i = 0; i < RUN; i++)
    {
        printf("hello from %s\n", str);
        usleep(100000);
    }
}

int cloneProcces(void *params){
    print("beni");
}

int cloneProcces2(void *params){
    print("cohen");
}


int main()
{

int result = clone(cloneProcces,brother_stack+STACK_SIZE,CLONE_PARENT,0);
int result2 = clone(cloneProcces2,brother_stack+STACK_SIZE,CLONE_PARENT,0);
print("avi");
return 0;
}