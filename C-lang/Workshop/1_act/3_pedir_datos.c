#include "lib/grizzly.h" // Import my library that includes all other the necesary libraries

void menu();
void ask_info();
void ask_numbers(char numeric_data[], int height);
void ask_letters(char alphabetic_data[], int height);
void ask_char(char character[], int height, char allowed[]);
int subsection;

int main()
{
   set_window();
   menu();
   repeat_program(main,"Desea continuar", 26);
   system(reset);
   system(clean);
   return 0;
}

void menu()
{
   printf(white_blue);
   if (OS == "Windows")
      system("color F1");
   else
      printf(clrscr);
   system(clean);
   center_print("UNIVERSIDAD POPULAR DEL CESAR", 4);
   center_print("PROGRAMA INGENIERIA DE SISTEMAS", 5);

   subsection = title_align() * 0.95;

   gotoxy(subsection, 8); printf("CEDULA     :");
   gotoxy(subsection, 9); printf("NOMBRE     :");
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
   char genre[10];

   ask_numbers(person_dni, 8);
   ask_letters(name, 9);
   gotoxy(subsection + 13, 10); fgets(address, 30, stdin);
   ask_numbers(phone_number, 11);
   ask_char(genre, 12, "mf");
   ask_letters(civil_state,13);

   center_print("DATOS LEIDOS", 16);
   gotoxy(subsection, 18);
   printf("CEDULA     = %s", person_dni);
   gotoxy(subsection, 19);
   printf("NOMBRE     = %s", name);
   gotoxy(subsection, 20);
   printf("DIRECCION  = %s", address);
   gotoxy(subsection, 21);
   printf("TELEFONO   = %s", phone_number);
   gotoxy(subsection, 22);
   printf("SEXO       = %s", genre);
   gotoxy(subsection, 23);
   printf("EST. CIVIL = %s", civil_state);
   stop;
}

void ask_numbers(char numeric_data[], int height)
{
   bool is_number;
   char nl;
 
   do
   {
      gotoxy(subsection + 13, height);
      printf("                                                              ");
      
      gotoxy(subsection + 13, height); scanf("%s", numeric_data);
      is_number = only_numbers(numeric_data, 'p');
      error_msg("Error. Valores invalidos", 15);
   } while (!is_number);
   center_print("                          ", 15);
   scanf("%c", &nl);
}

void ask_letters(char alphabetic_data[], int height)
{
   bool is_letter;

   do
   {
      gotoxy(subsection + 13, height);
      printf("                                                              ");
      fflush(stdin);
      
      gotoxy(subsection + 13, height); fgets(alphabetic_data, 20, stdin);
      is_letter = only_letters(alphabetic_data);
      if (!is_letter)
         error_msg("Error. No ingrese numeros.", 15);
   } while (!is_letter);
   center_print("                            ", 15);
}

void ask_char(char character[], int height, char allowed[])
{
   int i, input_len;
   bool invalid = true;

   do
   {
      ask_letters(character, height);
      input_len = strlen(character);
      if (input_len != 2)
      {
         continue; 
      }
      
      for (i = 0; i < strlen(allowed); i++)
         if (tolower(character[0]) == allowed[i])
            invalid = false;
   } while (invalid);
}
