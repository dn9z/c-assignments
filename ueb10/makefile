CC = gcc -Wall -std=c99
PRG = ueb10
OBJ = ueb10.o tools.o
COM = ueb10.o
$(PRG):$(OBJ)
		$(CC) -o $@ $^ 

$(PRG).o: $(PRG).c tools.h
		$(CC) -c $<

tools.o: tools.c tools.h
		$(CC) -c $<
run:
		./$(PRG)

clean: 
		rm -f $(OBJ) $(PRG) 
all: clean $(PRG) run


