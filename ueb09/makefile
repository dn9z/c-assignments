CC = gcc -Wall
PRG = ueb09
OBJ = ueb09.o matrix.o tools.o

start: all
 

$(PRG): $(OBJ)
	@$(CC) -o $@ $^ -lm

ueb09.o: ueb09.c matrix.h tools.h
	@$(CC) -c $<

matrix.o: matrix.c matrix.h tools.h
	@$(CC) -c $<

tools.o: tools.c tools.h
	@$(CC) -c $<

run: 
	@./$(PRG)

clean:
	@rm $(OBJ) $(PRG) -f

all: clean $(PRG) run
