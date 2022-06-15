#include <stdio.h>
#include "matrix.h"
#include "tools.h"
#include "escapesequenzen.h"

void clearBuffer()
{
	char Dummy;
	do              // Tastaturpuffer loeschen
		scanf("%c", &Dummy);
	while (Dummy != '\n');
}

int askAgain(int Row, int Col)
{
	char c;
		do
		{
			POSITION(Row,Col);
			printf("Moechten Sie noch einmal (j/n)? \n");			//char gefragt um unten in einer der 3 verschieden 
			scanf("%c",&c);							//fälle zu kommen
			if (c != '\n')
			{
				clearBuffer();
			}
			if (c!='j' && c!='n' && c!='N' && c!='y' && c!='Y' && c!='J')
			{
				printf("Falsche Eingabe! Bitte 'j' oder 'n' eingeben! \n");
			}
	
		} while (c!='j' && c!='n' && c!='N' && c!='y' && c!='Y' && c!='J');	// fall 1 user gibt alles andere ausser n oder j ein
			if (c=='j' || c=='J')
				return 1;
	return 0;
}