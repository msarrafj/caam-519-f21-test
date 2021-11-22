# set compiler
CC=gcc

### begin targets
# for the executable
main: my_main.o my_vector_struct.o my_vector_struct.h
	$(CC) my_main.o my_vector_struct.o my_vector_struct.h -o main

# for the object file
my_vector_struct.o: my_vector_struct.c
	$(CC) -c my_vector_struct.c
my_main.o: my_main.c
	$(CC) -c my_main.c

clean:
	rm -rf main my_main.o my_vector_struct.o
### end targets

