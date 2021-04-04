#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

int main()
{

    void *lib = dlopen("./libHelloAriel.so", RTLD_LAZY);

    if (lib == NULL)
    {
        printf("File not found!\n");
        return -1;
    }

    void (*myfunc)() = (void *)dlsym(lib, "myprint");

    if (myfunc == NULL)
    {
        printf("Function not found!\n");
        return -1;
    }

    myfunc("main 1_3");

    return 0;
}
