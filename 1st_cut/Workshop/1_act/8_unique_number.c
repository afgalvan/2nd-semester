/* 8) Identificar e imprimir por pantalla el número medio de un conjunto de tres 
 *  únicos. El número medio es aquel que no es el menor ni el mayor.
 */
#include "lib/grizzly.h"
#include <stdio.h>

void ask_numbers();
void menu();
bool is_unique(int chunk, char list[][50], char n[]);
void medium_number(char numbers[][50]);

int subsection;

int main()
{
   set_window();
   menu();
   repeat_program(main, "Desea repetir el programa", 15);
   system(clean);
   return 0;
}

void menu()
{
   paint_window();
   int i;

   center_print("NÚMERO MEDIO CHECK.", 2);
   subsection = title_align() * 0.95;
   center_print("INGRESE NÚMEROS DIFERENTES.", 3);

   for(i = 5; i < 8; i++)
   {
      gotoxy(subsection, i);
      printf("%d. INGRESE UN NUMERO: ", i-4);
   }

   ask_numbers();
}

void ask_numbers()
{
   int i;
   char number[50], number_list[3][50];
   bool is_numeric;
  
   for(i = 0; i < 3; i++)
   {
      do
      {
         gotoxy(subsection+22, i+5);
         printf("                                  ");
         
         gotoxy(subsection+22, i+5);
         scanf("%s", number);
         strcpy(number_list[i], number);
         is_numeric = only_numbers(number, 'a');
         error_msg("Error. Valor no permitido.", 9);
      } while(!is_numeric || !is_unique(i, number_list, number));
      center_print("                               ", 9);
   }

   medium_number(number_list);
}

bool is_unique(int chunk, char list[][50], char n[])
{
   int i;

   for(i = 0; i < chunk; i++)
      if(strcmp(list[i], n) == 0)
         return false;
   return true;
}

void medium_number(char numbers[][50])
{
   int i, j, k, mid;
   long long  arr[3], max = -922337203685477580, min = 999999999999999999;
   int center_x, quantity = 3;
   
   for(i = 0; i < quantity; i++)
      arr[i] = atoll(numbers[i]);

   for(i = 0; i < quantity; i++)
   {
      if(arr[i] >= max)
      {
         max = arr[i];
         j = i;
      }
      if(arr[i] <= min)
      {
         min = arr[i];
         k = i;
      }
   }
   
   mid = quantity - k - j;
   center_x = center_this("El numero medio es  ");
   gotoxy(center_x, 10);
   printf("El numero medio es %lld", arr[mid]);
}
