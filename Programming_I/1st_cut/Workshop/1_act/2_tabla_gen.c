/* 2) Generar y mostrar por pantalla una a
una las tablas de multiplicar del 1 al 12 */

#include "lib/grizzly.h"
void program_header(int n);
void generate_table(int n);

int number = 0;

int main()
{
   number++;
   if (number > 12) return 0;
   set_window();
   generate_table(number);
   repeat_program(main, "Desea continuar", 25);
   system(clean);
   return 0;
}

void program_header(int n)
{
   int indent = center_this("TABLAS DE MULTIPLICAR DEL n .");
   
   printf(white_blue);
   if (OS == "Windows")
      system("color F1");
   else
      printf(clrscr);
   system(clean);
   gotoxy(indent, 4); printf("TABLAS DE MULTIPLICAR DEL %i.", n);
}

void generate_table(int n)
{
   int i, product, indent, line = 6;
   program_header(n);

   indent = center_this(" a x b = c");

   for (i = 1; i <= 12; i++)
   {
      if (i == 10) indent--;
      product = i * n;
      gotoxy(indent, i+line);
      printf("%i x %i = %i", i, n, product);
   }
}
