#include <stdio.h>

int main()
{
   // Deklarierung der Variablen
   double Operant1;     // Erster Rechenoperant
   double Operant2;     // Zweiter Rechenoperant
   int Menuewahl;       // Benutzereingabe der Menüwahl
   int Eingabe;         // Ergebnis von scanf
   double Ergebnis;     // Ergebnis der Rechnung

   do
   {
      // Ausgabe des Benutzermenüs
      printf("Einfacher Taschenrechner\n");
      printf("========================\n");
      printf("\n");
      printf("1. Addition\n");
      printf("2. Subraktion\n");
      printf("3. Multiplikation\n");
      printf("4. Division\n");
      printf("9. Programmende\n");
      
      Eingabe = scanf("%i", &Menuewahl);     // Eingabe des Menüpunktes
      getchar();                             // Bei falscher Eingabe wird die Eingabe wiederholt
      if (Eingabe == 1)                      // Richtige Eingabe
      {

         switch(Menuewahl)
         {
            case 1: printf("Addition\n");       break;
            case 2: printf("Subtraktion\n");    break;
            case 3: printf("Multiplikation\n"); break;
            case 4: printf("Division\n");       break;
            default: Eingabe = 0;
         }
         if (Eingabe == 1){               // Richtige Eingabe

            do
            {
               printf("Geben Sie bitte den ersten Operanten ein:\n");
               Eingabe = scanf("%lf", &Operant1);      // Eingabe erster Operant
               getchar();
               if (Eingabe == 0) 
                  printf("Keine gültige Eingabe\n");      // Bei falscher Eingabe wird wiederholt
            } while (Eingabe == 0);

            do
            {
               printf("Geben Sie bitte den zweiten Operanten ein:\n");
               Eingabe = scanf("%lf", &Operant2);         // Eingabe zweiter Operant
               getchar();
               if (Eingabe == 0) 
                  printf("Keine gültige Eingabe\n");      // Bei falscher Eingabe wird wiederholt
               else ((Menuewahl == 4) && Operant2 == 0);
               {
                  printf("Division durch 0!\n");
                  Eingabe = 0;
               }
            } while (Eingabe == 0);
         }
         switch (Menuewahl)
         {
            case 1: Ergebnis = Operant1 + Operant2;
                    printf("%lf + %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            case 2: Ergebnis = Operant1 - Operant2;
                    printf("%lf - %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            case 3: Ergebnis = Operant1 * Operant2;
                    printf("%lf * %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            case 4: Ergebnis = Operant1 / Operant2;
                    printf("%lf / %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            case 9: break;
            default:
                    printf("Keine gültige Eingabe\n");
         }
      }
      else
         printf("Keine gültige Eingabe, versuchen Sie es erneut:\n"); 
   }while (Menuewahl != 9);
   return 0;
}
