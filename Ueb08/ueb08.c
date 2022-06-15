#include <stdio.h>
#include "escapesequenzen.h"


// Definition der Funktionen

void printFrame();
short getNumber();
char getOperator();
int askAgain();
short getNumber();
short calcResult(short, short, char);
int checkOperator(char);
void printResultNumber(int, short);
void getBinary(int, short);
void printOperator(char);



int main()
{ 
	short Op1, Op2, Erg;
	char Op;
		
	do
	{	
	     printFrame();                     // Gibt Rahmen auf Bildschirm aus
	     Op1 = getNumber(5);               // Nimmt ersten Operanten an
	     Op = getOperator(6, 12);          // Nimmt Operator an
	     Op2= getNumber(7);                // Nimmt zweiten Operanten an

        Erg = calcResult(Op1, Op2, Op);   // Berechnet Ergebnisse

        printResultNumber(12, Op1);       // Gibt erste Ergebnis Zeile aus
        printOperator(Op);                // Gibt Operanten im Rahmen an
	     printResultNumber(14, Op2);       // Gibt zweite Ergebnis Zeile aus
	     printResultNumber(16, Erg);       // Gibt dritte Ergebnis Zeile aus
		  POSITION(19, 1);                  // Positionswechsel zu Eingabeposition
        CLEAR_LINE;                       // Löscht Zeile

	} while(askAgain() == 1);              // Berechnung kann erneut gestartet werden

   printf("Das Programm wird beendet...\n");

   return 0;
}


/************************************************
* Gibt den Ein- und Ausgaberahmen aus
* Parameter: keine
* Ergebnis: Der Ausgegebene Rahmen
************************************************/
void printFrame()
{
CLEAR;
HOME;

printf("|-------------------------------------------------------------------------|\n");
printf("|                                                                         |\n");
printf("| Bitoperator-Rechner                                                     |\n");
printf("|                                                                         |\n");
printf("| Eingabe Zahl 1:                                                         |\n");
printf("| Operator:                                                               |\n");
printf("| Eingabe Zahl 2:                                                         |\n");
printf("|                                                                         |\n");
printf("|-------------------------------------------------------------------------|\n");
printf("|                                                                         |\n");
printf("|          |   dez.  |    okt.   |    hex.   |  Binaerdarstellung         |\n");
printf("| Zahl 1   |         |           |           |                            |\n");
printf("| Operator |         |           |           |                            |\n");
printf("| Zahl 2   |         |           |           |                            |\n");
printf("|-------------------------------------------------------------------------|\n");
printf("| Ergebnis |         |           |           |                            |\n");
printf("|                                                                         |\n");
printf("|-------------------------------------------------------------------------|\n");
}



/*******************************************************
* Liest ein operator Ein und prüft, ob dieser gültig ist.
* Parameter: keine
* Ergebnis: der Eingelesene Operator
********************************************************/

char getOperator()
{
   char op; // Operator
   do
   {
      scanf("%c", &op);
      getchar();
      POSITION(6, 13);
      printf("      %c", op);
      POSITION(19, 1);
      CLEAR_LINE;
      if(checkOperator(op) == 0) // Prüft Operator auf Gültigkeit
      {
         printf("Kein richtiger Operator! Bitte Geben Sie &, |, ^, << oder >> ein: ");
         POSITION(6, 1);
         CLEAR_LINE;
         printf("| Operator:                                                               |\n");
         POSITION(19, 67);
      }
   } while(checkOperator(op) == 0);	// Wiederholt Eingabe bis gültiger Operator eingeben wurde
 

   return op;
}


/*******************************************************
* Liest eine Zahl ein und prüft, ob dieser gültig ist.
* Parameter: Zeile
* Ergebnis: der eingelesene Zahl 
********************************************************/

short getNumber(int Zeile)
{
   short Zahl, ScanErg; // Operator und Ergebnis von scanf
   do
   {
      ScanErg = scanf("%hi", &Zahl);
      getchar();
      POSITION(Zeile, 19);
      printf("%-hi", Zahl);
      POSITION(19, 1);
      CLEAR_LINE;
        if(!ScanErg)
        {
           if (Zeile == 5)
           {
               POSITION(Zeile, 1);
               CLEAR_LINE;
               printf("| Eingabe Zahl 1:                                                         |\n");
               POSITION(19, 1);
               CLEAR_LINE;
           }
           else if(Zeile == 7)
           {
               POSITION(Zeile, 1);
               CLEAR_LINE;
               printf("| Eingabe Zahl 2:                                                         |\n");
               POSITION(19, 1); 
               CLEAR_LINE;
           }
           printf("Falsche Eingabe! Bitte Geben Sie eine ganze Zahl ein: ");

        }


   } while(!ScanErg);

   return Zahl;
}


/*******************************************************
*Berechnet die Ergebnisse
*Parameter: Operant 1, Operant 2, Operator
*Ergebnis: Ergebnis der Berechnung
********************************************************/

short calcResult(short Z1, short Z2, char Op)
{
   short Result; // Ergebnis

   if      (Op == '&') Result = Z1 & Z2;
   
   else if (Op == '|') Result = Z1 | Z2;   
   
   else if (Op == '^') Result = Z1 ^ Z2;
   
   else if (Op == '<') Result = Z1 << Z2;
   
   else if (Op == '>') Result = Z1 >> Z2;
   
   return Result;

}

/*******************************************************
*Überprüft eingebenen Operator auf gültigkeit
*Parameter: Operator
*Ergebnis: Wahrheitswert
********************************************************/


int checkOperator(char Op)
{
    short Result; // Ergebnis

    if (Op == '&' || Op == '|' || Op == '^' || Op == '<' || Op == '>') Result = 1; // Prüfung der Operatoren

    else Result = 0;

    return Result;

}

/*******************************************************
*Gibt den resultierenden Wert aus
*Parameter: Zeile, Zahl
*Ergebnis: Keines
********************************************************/


void printResultNumber(int Zeile, short Zahl)
{
   POSITION(Zeile, 13);
   printf("%8hi", Zahl);
   POSITION(Zeile, 25);
   printf("%08o", Zahl);
   POSITION(Zeile, 37);
   printf("%#8X", Zahl);
   POSITION(Zeile, 50);
   //printf("%016i", getBinary(Zahl)); 50
   getBinary(Zeile, Zahl);


}

/*******************************************************
*Wandelt dezimalen Wert in binären Wert um
*Parameter: Dezimaler Wert
*Ergebnis Keines
********************************************************/

void getBinary(int Zeile, short Zahl)
{
   POSITION(Zeile, 50);
   int i;
   for (i = 32768; i > 0; i = i>>1)
   {
      if((Zahl & i) == i)
      {
         printf("1");
      }
      else
      {
            printf("0");
      }
   }
}

/*******************************************************
*Gibt den Operator Im Rahmen aus
*Parameter: Operator
*Ergebnis: Keins
********************************************************/

void printOperator(char c)
{
   if ( c == '<') 
   {
      POSITION(13, 19);   printf("%c%c", c, c);
      POSITION(13, 31);   printf("%c%c", c, c);
      POSITION(13, 43);   printf("%c%c", c, c);
      POSITION(13, 64);   printf("%c%c", c, c);


   }
   else if ( c == '>')
   {
       POSITION(13, 19);
       printf("%c%c", c, c);
       POSITION(13, 31);
       printf("%c%c", c, c);
       POSITION(13, 43);
       printf("%c%c", c, c);
       POSITION(13, 64);
       printf("%c%c", c, c);

   }
   else
   {
      POSITION(13, 20);
      printf("%c", c);
      POSITION(13, 32);
      printf("%c", c); 
      POSITION(13, 44);
      printf("%c", c);
      POSITION(13, 65);
      printf("%c", c);
   }

}

/*******************************************************
*Fragt nach ob Berechnung wiederholt werden soll
*Parameter: Keine
*Ergebis: Wahrheitswert
********************************************************/


int askAgain()
{
   int Value;      // Wahrheitswert
   char Answer;    // Ergebnis der Eingabe
   do 
   {
      printf("Moechten Sie noch eine Berechnung durchführen? j/n: ");
      scanf("%c", &Answer);
      getchar();
      if (Answer == 'j' || Answer == 'J') Value = 1;
      else if (Answer == 'n' || Answer == 'N') Value = 0;
   } while (Answer != 'j' && Answer != 'J' && Answer != 'n' && Answer != 'N');

   return Value;
}
