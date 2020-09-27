/* 1) Recibir por teclado un numero entero entre 1 y 12 .
Generar y mostrar por pantalla la tabla de multiplicar
de dicho número.

a) Realizar solo operaciones de productos
b) Realizar solo operaciones de sumas . */

#include "lib/grizzly.h"
void program_header();
void ask_number();
void generate_table(int n);

int main()
{
   set_window();
   program_header();
   ask_number();
   repeat_program(main, "Desea repetir el programa", 22);
   return 0;
}

void program_header()
{
   printf(white_blue);
   if (OS == "Windows")
      system("color F1");
   else
      printf(clrscr);
   system(clean);
   center_print("TABLAS DE MULTIPLICAR.", 4);
}

void ask_number()
{
   char number_char[100], question[] = "Digite el numero a calcular: ";
   int number;
   int subsection = center_this(question) - 2;
   bool is_number;

   center_print("EL VALOR DEBE ESTAR ENTRE 1 Y 12.", 5);
   do
   {
      gotoxy(subsection+29, 7); printf("                                                          ");
      gotoxy(subsection, 7); printf("%s", question);
      gotoxy(subsection+29, 7); scanf("%s", number_char);
      is_number = only_numbers(number_char, 'a');
      if (!is_number) {
         error_msg("Error. Solo Ingrese números.", 10);
         continue;
      }
      error_msg("Error. Ingrese numeros entre 1 - 12.", 10);
      number = atoi(number_char);
   } while(!is_number || number <= 0 || number > 12);
   center_print("                                   ", 10);
   
   generate_table(number);
}

void generate_table(int n)
{
   int i, product, line = 6;
   int indent = center_this("TABLAS DE MULTIPLICAR DEL n .");
   program_header();
   gotoxy(indent, 4); printf("TABLAS DE MULTIPLICAR DEL %i.", n);

   indent = center_this(" a x b = c");

   for (i = 1; i <= 12; i++, line++)
   {
      if (i == 10) indent -= 1;
      product = i * n;
      gotoxy(indent, line);
      printf("%i x %i = %i", i, n, product);
   }
}
