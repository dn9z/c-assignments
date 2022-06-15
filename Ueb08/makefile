CC = gcc -Wall
PRG = ueb08
OBJ = ueb08.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^

ueb08.o: ueb08.c
	$(CC) -c $<

run:
	./$(PRG)

clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run
