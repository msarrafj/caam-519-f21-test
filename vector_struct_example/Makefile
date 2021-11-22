my_main.o: my_main.c
	gcc -c my_main.c

my_vector_struct.o: my_vector_struct.c
	gcc -c my_vector_struct.c

vector_output: my_main.o my_vector_struct.o
	gcc my_main.o my_vector_struct.o -o vector_output -lm

clean:
	rm -f vector_output my_main.o my_vector_struct.o
