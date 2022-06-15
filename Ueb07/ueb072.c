#include <stdio.h>

int main()
{
   
   
   double Operant1;
   double Operant2;
   int Menuewahl; 
   int Eingabe;
   char Dummy;
   double Ergebnis;
   
   do
   {

      printf("Einfacher Taschenrechner\n");
      printf("========================\n");
      printf("\n");
      printf("1. Addition\n");
      printf("2. Subraktion\n");
      printf("3. Multiplikation\n");
      printf("4. Division\n");
      printf("9. Programmende\n");
      
      
      Eingabe = scanf("%i", &Menuewahl);
      do scanf("%c", &Dummy);
      while (Dummy != '\n');
      


      if(Eingabe)
      {
         switch(Menuewahl)
         {
            case 1: printf("Geben Sie bitte den ersten Operanten ein:\n");
                    scanf("%lf", &Operant1)
                    printf("Geben Sie bitte den zweiten Operanten ein:\n");
                    scanf("%lf", &Operant2)
                    printf("%lf + %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            case 2: printf("Geben Sie bitte den ersten Operanten ein:\n");
                    scanf("%lf", &Operant1);
                    printf("Geben Sie bitte den zweiten Operanten ein:\n");
                    scanf("%lf", &Operant2);
                    Ergebnis = Operant1 - Operant2;
                    printf("%lf - %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            case 3: printf("Geben Sie bitte den ersten Operanten ein:\n");
                    scanf("%lf", &Operant1);
                    printf("Geben Sie bitte den zweiten Operanten ein:\n");
                    scanf("%lf", &Operant2);
                    Ergebnis = Operant1 * Operant2;
                    printf("%lf * %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            case 4: printf("Geben Sie bitte den ersten Operanten ein:\n");
                    scanf("%lf", &Operant1);
                    printf("Geben Sie bitte den zweiten Operanten ein:\n");
                    scanf("%lf", &Operant2);
                    Ergebnis = Operant1 / Operant2;
                    printf("%lf / %lf = %lf\n", Operant1, Operant2, Ergebnis);
                    break;
            default: printf("Keine gültige Eingabe!\n");
                    break;
         }
      }
      
   }while (Menuewahl != 9);
         
   return 0;
}

