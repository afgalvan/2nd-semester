#include "lib/grizzly.h"
/* #include <math.h> */

void menu();
void ask_values();
void evaluate_values(char value[], int heigth, char range);
int power(long long base, long long exponent, char base_char[]);
int subsection;
char question[] = "Digite el exponente : ";

int main()
{
   set_window();
   menu();
   repeat_program(main, "Desea continuar", 12);
   system(clean);
   return 0;
}

void menu()
{
   subsection = center_this(question) * 0.85;

   paint_window();
   center_print("CALCULAR EXPONENTES.", 4);
   gotoxy(subsection, 6);
   printf("Digite la base      : ");
   gotoxy(subsection, 7);
   printf("Digite el exponente : ");
   
   ask_values();
}

void ask_values()
{
   char base_char[100], exponent_char[100];
   long long base, exponent;
  
   evaluate_values(base_char, 6, 'p');
   evaluate_values(exponent_char, 7, 'p');
   base = atoll(base_char);
   exponent = atoll(exponent_char);
   
   power(base, exponent, base_char);
}

void evaluate_values(char value[], int heigth, char range)
{
   bool is_numeric;
   char nl;

   do
   {
      gotoxy(subsection + strlen(question), heigth);
      printf("                                      ");
      
      gotoxy(subsection + strlen(question), heigth);
      scanf("%s", value);
      is_numeric = only_numbers(value, range);
      error_msg("Error. solo ingrese numeros.", 9);
   } while (!is_numeric);
   center_print("                            ", 9);
   scanf("%c", &nl);
}

int power(long long base, long long exponent, char base_char[])
{
   long long result = 1, n;
   int digits = 0;
   int result_position = center_this(" elevado a la  es ");
 
   if (exponent == 0)
   {
      result_position -= strlen(base_char);
      gotoxy(result_position, 9);
      printf("%lld elevado a la %lld es 1", base, exponent);
      return 0;
   }
   for (int i = 0; i < exponent; i++)
      result *= base;
   /* result = pow(base, exponent); */
   n = result;
   // n = log(result)+1;
   // digits = (int)n;
   while (n != 0)
   {
      n /= 10;
      digits++;
   }
   result_position -= digits;

   gotoxy(result_position, 9);
   printf("%lld elevado a la %lld es %llu", base, exponent, result);
   return 0;
}
