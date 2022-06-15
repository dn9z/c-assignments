CC = gcc -Wall
PRG = ueb04
OBJ = ueb04.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb04.o: ueb04.c
	$(CC) -c $<

run:
	./$(PRG)

clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run
