#include "../Grizzly/grizzly.h"

void gotoxy(int x, int y);
void menu();
void ask_info();
int subsection;

int main()
{
   set_window();
   menu();
   repeat_program(main, 26);
   system(reset);
   system(clean);
   return 0;
}

void menu()
{
   system(white_blue);
   system(clean);
   center_print("UNIVERSIDAD POPULAR DEL CESAR", 4);
   center_print("PROGRAMA INGENIERIA DE SISTEMAS", 5);
   
   subsection = title_align();

   gotoxy(subsection, 8);  printf("CEDULA     :");
   gotoxy(subsection, 9);  printf("NOMBRE     :");
   gotoxy(subsection, 10); printf("DIRECCION  :");
   gotoxy(subsection, 11); printf("TELEFONO   :");
   gotoxy(subsection, 12); printf("SEXO M/F   :");
   gotoxy(subsection, 13); printf("EST. CIVIL :");
   
   ask_info();
}

void ask_info()
{
   char person_dni[11], phone_number[11];
   char name[20], address[30], civil_state[15];
   char genre;
   bool is_number, is_letter;

   do 
   {
      gotoxy(subsection + 13, 8); scanf("%s", person_dni);
      is_number = only_numbers(person_dni, 'p');
      fflush(stdin);
      if(!is_number){
         error_msg("Error. Valores invalidos", 15);}
   } while(!is_number);
   center_print("                        ", 15);

   do
   {
      /*if (OS == "Linux"){*/
         /*gotoxy(subsection + 13, 9); fgets(name, 20, stdin);}*/
      gotoxy(subsection + 13, 9); fgets(name, 20, stdin);
      is_letter = only_letters(name);
      if(!is_letter){
         error_msg("Error. Valores invalidos", 15);}
   } while(!is_letter);
   center_print("                        ", 15);

   gotoxy(subsection + 13, 10); fgets(address, 30, stdin);
   
   do
   {
      gotoxy(subsection + 13, 11); scanf("%s", phone_number);
      is_number = only_numbers(phone_number, 'p');
      if(!is_number){
         error_msg("Error. Valores invalidos", 15);}
   } while (!is_number);
   center_print("                        ", 15);

   gotoxy(subsection + 13, 12); scanf(" %c", &genre); getchar();
   fflush(stdin);
   
   do
   {
      gotoxy(subsection + 13, 13); fgets(civil_state, 15, stdin);
      is_letter = only_letters(civil_state);
      if(!is_letter){
         error_msg("Error. Valores invalidos", 15);}
   } while(!is_letter);
   center_print("                        ", 15);
   
   center_print( "DATOS LEIDOS", 16);
   gotoxy(subsection, 18); printf("CEDULA     = %s", person_dni);
   gotoxy(subsection, 19); printf("NOMBRE     = %s", name);
   gotoxy(subsection, 20); printf("DIRECCION  = %s", address);
   gotoxy(subsection, 21); printf("TELEFONO   = %s", phone_number);
   gotoxy(subsection, 22); printf("SEXO       = %c", genre);
   gotoxy(subsection, 23); printf("EST. CIVIL = %s", civil_state);
   stop;
}
