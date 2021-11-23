# set compiler
CC = gcc
# define target
# for object file
my_vector_struct.o: my_vector_struct.c
                  $(CC) -c my_vector_struct.c

main_vector_struct.o: main_vector_struct.c
                  $(CC) -c main_vector_struct.c

# for executable
main: my_vector_struct.o main_vector_strut.o
                  $(CC) my_vector_struct.o main_vector_struct.o main

# remove executable and object files
clean:
                  rm -f main my_vector_struct.o main_vector_struct.o
