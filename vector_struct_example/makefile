# set the compiler
CC = gcc
# targets defined below:
# for the executable
main: my_main.o my_vector_struct.o
	$(CC) my_main.o my_vector_struct.o -o main

# for the object file
source.o: my_main.c my_vector_struct.c
	$(CC) -c my_main.c my_vector_struct.c

# remove executable and object file
clean:
	rm -f main my_main.o my_vector_struct.o