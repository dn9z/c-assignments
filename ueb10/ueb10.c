#include <stdio.h>
#include "escapesequenzen.h"
#include "tools.h"

void resetArray(int *A, int Anz);
void printTitle();
void getText(unsigned char *T);
void countChar(unsigned char *T, int *A);
void setUpper2Lower(int *A);
void printTable(int *A);

int main()
{
	do
	{	
		unsigned char text[151];
	        int zaehler[256];

		HOME;
		CLEAR;
		printTitle();
		resetArray(zaehler, 256);
		getText(text);
		countChar(text, zaehler);
		setUpper2Lower(zaehler);
		printTable(zaehler);
	} while (askAgain() == 1);
	return 0;
} 




void printTitle()
{
	printf("==========================\n");
	printf("||                      ||\n");
	printf("||    Zeichenzaehler    ||\n");
	printf("||                      ||\n");
	printf("==========================\n\n");
	printf("Geben sie bitte den Text ein (mind. 1 Zeichen / max. 150 Zeichen), dessen Zeichen gezählt werden sollen:\n");

}


void resetArray(int *A, int Anz)
{
	for (int i = 0; i < Anz; i++)
	{
		*(A + i) = 0;
	}
}	

void getText(unsigned char *T)
{
	unsigned char *ptr = T;

	do
	{
		*T = '\0';
		POSITION(13,1);
		scanf("%150[^\n]", ptr);
		clearBuffer();
	} while (*T == '\0');
}

void countChar(unsigned char *T, int *A)
{
	while(*T)
	{
		*(A + (*T)) += 1;
		T++;
	}
}


void setUpper2Lower(int *A)
{
	int *klein = 0;
	int *gross = 0;
	for(int i = 'a'; i <= 'z'; i++)
	{
		klein = A + i;
		gross = A + i - 32;
		*klein += *gross;
		*gross = 0;
	}
	klein = A + 0xe4;
	gross = A + 0xe4 - 32;
	*klein += *gross;
	*gross = 0;

	klein = A + 0xf6;
	gross = A + 0xf6 - 32;
	*klein += *gross;
	*gross = 0;

	klein = A + 0xfc;
	gross = A + 0xfc - 32;
	*klein += *gross;
	*gross = 0;
}


void printTable(int *A)
{
	int help = 0;
	printf("-------------------------------------------------------------\n");
	for(int i = 0; i < 256; i++)
	{
		if (*(A + i) != 0)
		{
			if(i < 32)
			{
				printf("|   (%#4hx):%3i ", i, *(A + i));
				help++;
			}
			else
			{
				printf("| %c (%#4hx):%3i ", i, i, *(A + i));
				help++;
			}
			if(help == 4)
			{
				printf("|\n");
				help = 0;
			}
		}
	}
	if(help > 0)
	{
		do
		{
			printf("|              ");
			help++;
		}while(help < 4);
		printf("| \n");
	}
	printf("-------------------------------------------------------------\n");
}
