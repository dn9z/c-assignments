CC = gcc -Wall
PRG = ueb03
OBJ = ueb03.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^

ueb03.o: ueb03.c
	$(CC) -c $<

run:
	./$(PRG)

clean:
	rm $(OBJ) $(PRG) -f

all: clean $(PRG) run
