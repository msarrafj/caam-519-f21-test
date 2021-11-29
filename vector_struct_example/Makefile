# compiler
CC=gcc

# flags
CFLAGS=-I.

# dependencies (.h files)
DEPS_DIR = ./inc
DEPS = my_vector_struct.h

# objects (hidden directory)
OBJ_DIR = ./.obj
OBJ = my_main.o my_vector_struct.o

# make objects
.obj/%.o: src/%.c $(patsubst %,$(DEPS_DIR)/%,$(DEPS))
	$(CC) -c -o $@ $< $(CFLAGS)

# make executable
hw5: $(patsubst %,$(OBJ_DIR)/%,$(OBJ))
	$(CC) -o $@ $^ $(CFLAGS)

# clean up
clean:
	rm -f .obj/*.o
	rm -f hw5
