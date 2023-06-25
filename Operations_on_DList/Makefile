# C compiler to be used
CC = gcc
# compiler flags to include debugging information
CFLAGS = -g

# all the source files required to build the executable program
SRC = main.c Update.c Move.c Band.c Execute.c Print.c Free.c
# all the header files used in the source files
HEADERS = Update.h Move.h Band.h Execute.h Print.h Free.h
# Create a list of object files to be generated from the source files
OBJ = $(SRC:.c=.o)

# name of the executable program to be generated
EXEC = tema1
all: $(EXEC)

# build the executable program from the object files
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# compile a C source file to an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# compile a C source file to an object file
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $< $@

# "clean" is not a file to be generated
.PHONY: clean


clean:
	rm -f $(OBJ) $(EXEC)

valgrind: $(EXEC)
	valgrind --leak-check==full --track-origins=yes ./$(EXEC)

# make rule to run the executable program
run: $(EXEC)
	valgrind --leak-check=full --track-origins=yes ./$(EXEC)
