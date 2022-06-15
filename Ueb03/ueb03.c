#include <stdio.h>

int main() 
{

//Deklarierung der Variablen

   double RGesamt;               // Gesamtwiderstand einer Reihenschaltung
   double RGesamtParallel;       // Gesamtwiderstand einer Parallelschaltung
   double RWheatston;            // Unbekannter Widerstand einer Wheatstonschen Messbrücke
   double R1;                    // Widerstand R1
   double R2;                    // Widerstand R2
   double R3;                    // Widerstand R3

//Initialisierung der Variablen
   RGesamt = 0.0;
   RGesamtParallel = 0.0;
   RWheatston = 0.0;
   R1 = 500;
   R2 = 200;
   R3 = 300;

//Berechnung des Ergebnisses
   RGesamt = R1 + R2 + R3;                      // Berechung des Gesamtwiderstandes einer Reihenschaltung
   RGesamtParallel = 1 / (1/R1 + 1/R2 + 1/R3);  // Berechnung des Gesamtwiderstandes einer Reihenschaltung
   RWheatston = R3 * (R1/R2);                   // Berechnung des Unbekannten Widerstandes einer Wheaststonschen Messbrücke

//Ausgabe in der Konsole
   printf("\n");
   printf("Reihenschaltung:\n%f Ohm + %f Ohm + %f Ohm = %f Ohm\n", R1, R2, R3, RGesamt );
   printf("\n");
   printf("Parallelschaltung:\n1 / %f Ohm + 1 / %f Ohm + 1 / %f Ohm = 1 / %f Ohm \n", R1, R2, R3, RGesamtParallel );
   printf("\n");
   printf("Wheatstonesche Messbrücke:\n%f Ohm * %f Ohm / %f Ohm = %f Ohm \n", R3, R1, R2, RWheatston);
   printf("\n");

   return 0;
}
