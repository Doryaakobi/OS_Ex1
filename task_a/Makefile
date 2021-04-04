export LD_LIBRARY_PATH=.

.PHONY: all
all: main1_1 main1_2 main1_3 library

# Subtask 1:

main1_1: hello_ariel.c hello_ariel.h main1_1.c
	gcc -o main1_1 hello_ariel.h main1_1.c

# Subtask 2:

main1_2: main1_2.c library
	gcc main1_2.c -L. -l HelloAriel -o main1_2

# Subtask 3:

main1_3: main1_3.c
	gcc main1_3.c -fPIC -ldl -o main1_3

library: hello_ariel.h hello_ariel.c
	gcc -o libHelloAriel.so -shared -fPIC hello_ariel.c



.PHONY: clean
clean:
	-rm main1_1 main1_2 main1_3 libHelloAriel.so
