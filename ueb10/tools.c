#include <stdio.h>
#include "tools.h"
#include "escapesequenzen.h"

void clearBuffer();
int askAgain();



/**************************************************************
 *Funktion: Leert den Tastaturpuffer
 **************************************************************/

void clearBuffer()
{ 
char Dummy;
do
	scanf("%c", &Dummy);
while (Dummy != '\n');
}



/****************************************************************
 * Funktion: Abfrage, Programm erneut durchlaufen
 * Ausgabe: Ja oder Nein
 ****************************************************************/

int askAgain()
{
	char Eingabe = 0, jn;
	
	POSITION(30,1);
	printf("Moechten sie noch einmal(j,n)?\n");
	do
	{
		scanf("%c", &jn);
		if(jn != '\n')
		clearBuffer();
		if(jn =='j' || jn == 'J')
		{	jn = 1;
			return jn;
			
		}
		else if(jn == 'n' || jn == 'N')
		{	jn = 0;
			return jn;
			
		}
		else
		{	
			printf(" Geben sie Ja oder Nein ein");
			
		}
	}while(!Eingabe);
}
