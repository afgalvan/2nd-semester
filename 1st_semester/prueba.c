#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y);
void menu();
void clear_console();

int main()
{
   menu();
   clear_console();
   return 0;
}


void gotoxy(int x, int y)
{
   printf("%c[%d;%df", 0x1B, y, x); 
}


void clear_console()
{
   system("cls");
}


void menu()
{
   int person_dni;
   char name[20], address[30], civil_state[15], phone_number[11];
   char genre;

   system("color 1F");
   clear_console();
   gotoxy(25, 4); printf("UNIVERSIDAD POPULAR DEL CESAR");
   gotoxy(25, 5); printf("PROGRAMA INGENIERIA DE SISTEMAS");
   
   gotoxy(20, 8); printf("CEDULA\t: ");
   gotoxy(20, 9); printf("NOMBRE\t: ");
   gotoxy(20, 10); printf("DIRECCION\t: ");
   gotoxy(20, 11); printf("TELEFONO\t: ");
   gotoxy(20, 12); printf("SEXO M/F\t: ");
   gotoxy(20, 13); printf("EST. CIVIL\t: ");
   
   gotoxy(35, 8); scanf("%i", &person_dni);
   fflush(stdin);
   gotoxy(35, 9); fgets(name, 20, stdin);
   gotoxy(35, 10); fgets(address, 30, stdin);
   gotoxy(35, 11); scanf("%s", phone_number);
   gotoxy(35, 12); scanf(" %c", &genre); getchar();
   fflush(stdin);
   gotoxy(35, 13); fgets(civil_state, 15, stdin);
   
   gotoxy(34,15); printf( "DATOS LEIDOS");
   gotoxy(20,17); printf("CEDULA\t= %i", person_dni);
   gotoxy(20,18); printf("NOMBRE\t= %s", name);
   gotoxy(20,19); printf("DIRECCION\t= %s", address);
   gotoxy(20,20); printf("TELEFONO\t= %s", phone_number);
   gotoxy(20,21); printf("SEXO   \t= %c", genre);
   gotoxy(20,22); printf("EST. CIVIL\t= %s", civil_state);
   gotoxy(4,24); printf("EN LA PARTE SUPERIOR DERECHA DE LA VENTANA HAGA CLIC EN LA 'X' PARA SALIR\n");
   fflush(stdin);
   getchar();
}
