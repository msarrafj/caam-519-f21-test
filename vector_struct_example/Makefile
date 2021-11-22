### begin MACROS
# define compiler
CC=gcc

# define linker
LD=gcc

CFLAGS= -c -Wall

INCLUDE=./

# define sources files to compile
SOURCES=my_main.c my_vector_struct.c

# define the name of the executable
EXEC=main
### end MACROS

OBJECTS=$(SOURCES:.c=.o)

### begin targets
build: $(SOURCES) $(EXEC)

$(EXEC) : $(OBJECTS)
	$(LD) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) $< -o $@
# define additional targets

clean:
	rm -rf $(OBJECTS)

all: clean build

### end targets
