# set the compiler
CC = gcc

# targets defined below:
# for the executable
main: main.o my_vector_struct.o
	$(CC) my_main.o my_vector_struct.o -o main

# for the object file
main.o: my_main.c
	$(CC) -c my_main.c

my_vector_struct.o: my_vector_struct.c
	$(CC) -c my_vector_struct.c

# remove executable and object file
clean:
	rm -f main main.o 