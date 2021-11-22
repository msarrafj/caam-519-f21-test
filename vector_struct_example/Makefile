###begin MACROS
#define compiler
CC=gcc
#compilation flags.
CFLAGS=
RM=rm -rf
#define executable name.
OUT=vector
###end MACROS

#begin targets.
all: build
#combine my_main.o and my_vector_struct.o into executable vector.
build: my_main.o my_vector_struct.o
	$(CC) $(CFLAGS) -o $(OUT) my_main.c my_vector_struct.c
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build
#build my_main.o
my_main.o: my_main.c my_vector_struct.h
	$(CC) $(CFLAGS) -c my_main.c

#build my_vector_struct.o
my_vector_struct.o: my_vector_struct.c my_vector_struct.h
	$(CC) $(CFLAGS) -c my_vector_struct.c

clean:
	$(RM) *.o $(OUT)
