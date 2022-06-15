CC = gcc -Wall
PRG = ueb00
OBJ = ueb00.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^

ueb00.o: ueb00.c
	$(CC) -c $<

run:
	./$(PRG)

clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run
