CC=gcc
CFLAGS=-I.

DEPS_DIR = ./inc
DEPS = my_vector_struct.h

OBJ_DIR = ./.obj
OBJ = my_main.o my_vector_struct.o

.obj/%.o: src/%.c $(patsubst %,$(DEPS_DIR)/%,$(DEPS))
	$(CC) -c -o $@ $< $(CFLAGS)

hw5: $(patsubst %,$(OBJ_DIR)/%,$(OBJ))
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f .obj/*.o
	rm -f hw5