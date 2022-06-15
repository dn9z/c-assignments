#include <stdio.h>
#include <math.h>

int main() 
{

// Deklarierung der Variablen

   double p;
   double q;
   double x1;
   double x2;

// Initialisierung der Ergebnisvariablen

   x1 = 0.0;
   x2 = 0.0;

// Textausgabe - Aufforderung zur Eingabe von p und q

   printf("|-----------------------------------------------------------------|\n");
   printf("|Dieses Programm loest eine quatratische Gleichung zweiten Grades:|\n");
   printf("|x^2 + p * x + q = 0                                              |\n");
   printf("|                                                                 |\n");
   printf("|Geben Sie bitte die Faktoren p und q ein:                        |\n");
   printf("|-----------------------------------------------------------------|\n");

// Eingabe der Variablen in der Konsole

   scanf("%lf %lf",&p, &q);

// Berechnung der Ergebnisse

   x1 = (-1.0 / 2.0 * p) + (sqrt(p*p / 4.0 - q));
   x2 = (-1.0 / 2.0 * p) - (sqrt(p*p / 4.0 - q));

// Textausgabe der berechneten Formel und der Ergebnisse

   printf("|--------------------------------------------------------------------|\n");
   printf("| Es wird nun die quadratische Gleichung zweiten Grades              |\n");
   printf("| x^2 + %8.2f * x + %8.2f = 0                                  |\n", p, q);
   printf("| geloest.                                                           |\n");
   printf("|                                _____________________________       |\n");
   printf("|           1             +     /  %8.2f ^ 2               \\      |\n", p);
   printf("| x    = - --- * %8.2f - \\  /  ------------- - %8.2f           |\n", p, q);
   printf("|  1,2      2                \\/         4                            |\n");
   printf("|                                                                    |\n");
   printf("| x1 = %-8.2f                                                      |\n", x1);
   printf("| x2 = %-8.2f                                                      |\n", x2);
   printf("|--------------------------------------------------------------------|\n");

   return 0;
}
