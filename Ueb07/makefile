CC = gcc -Wall
PRG = ueb07
OBJ = ueb07.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^

ueb07.o: ueb07.c
	$(CC) -c $<

run:
	./$(PRG)

clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run
