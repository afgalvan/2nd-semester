#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>

using namespace std;

int gotoxy(USHORT x, USHORT y)
{
   COORD cp = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void TITULOS();
int MENU();
int CAPTURA(int N, int ARREGLO[15]);
void CONSULTA(int N, int ARREGLO[15]);
void ORDENAR_LINEAL(int N, int ARREGLO[]);
void ORDENAR_BURBUJA(int N, int ARREGLO[]);
int ELIMINAR(int N, int ARREGLO[]);

// ***********************PROGRAMA PRINCIPAL ****************

main()
{
   char CONTROL = 'S';
   int OPCION, NRO = 0;
   int VECTOR[15];
   while (CONTROL == 'S')
   {
      TITULOS();
      OPCION = MENU();
      switch (OPCION)
      {
      case 1:
         NRO = CAPTURA(NRO, VECTOR);
         break;
      case 2:
         CONSULTA(NRO, VECTOR);
         break;
      case 3:
         ORDENAR_LINEAL(NRO, VECTOR);
         break;
      case 4:
         ORDENAR_BURBUJA(NRO, VECTOR);
         break;
      case 5:
         NRO = ELIMINAR(NRO, VECTOR);
         break;
      case 6:
         CONTROL = 'N';
      };
   }
}

// *********************** FUNCION TITULOS ****************
void TITULOS()
{
   system("cls");
   system("color 5F");
   gotoxy(10, 6);
   cout << "CREAR Y/O ADICIONA, CONSULTA, ORDENA Y ELIMINA EN UN ARREGLO";
   gotoxy(28, 7);
   cout << "UNIDIMENSIONAL - VECTOR";
}

// *********************** FUNCION MENU *******************

int MENU()
{
   int TIPO;
   gotoxy(26, 10);
   cout << "1 - ASIGNAR VALORES AL VECTOR";
   gotoxy(26, 11);
   cout << "2 - CONSULTAR VALORES AL VECTOR";
   gotoxy(26, 12);
   cout << "3 - ORDENAR EL VECTOR (Metodo Lineal) ";
   gotoxy(26, 13);
   cout << "4 - ORDENAR EL VECTOR (Metodo Burbuja) ";
   gotoxy(26, 14);
   cout << "5 - ELIMINAR EN EL VECTOR ";
   gotoxy(26, 16);
   cout << "6 - SALIR DEL PROGRAMA";
   do
   {
      gotoxy(24, 19);
      cout << "Seleccine una alternativa :  ";
      gotoxy(54, 19);
      cin >> TIPO;
   } while ((TIPO < 1) || (TIPO > 6));
   return TIPO;
}

// *********************** FUNCION CREAR  *******************

int CAPTURA(int N, int ARREGLO[15])
{
   char OP = 'S';
   TITULOS();
   gotoxy(27, 9);
   cout << "ASIGNAR VALORES AL VECTOR";
   while ((OP == 'S') && (N < 15))
   {
      gotoxy(15, 24);
      cout << "Digite valor entre 0 - 99 ";
      do
      {
         gotoxy(15, 13);
         cout << "Introducir un valor Entero  [    ]";
         gotoxy(44, 13);
         cin >> ARREGLO[N];
         gotoxy(15, 24);
         cout << "ERROR ....Digite valor entre 0 - 99 ";
      } while ((ARREGLO[N] < 0) || (ARREGLO[N] > 99));
      gotoxy(15, 24);
      cout << "                                        ";
      N = N + 1;
      do
      {
         gotoxy(20, 20);
         cout << "Desea Capturar un Nuevo Elemento  S/N :   ";
         OP = getche();
         OP = toupper(OP);
      } while ((OP != 'S') && (OP != 'N'));
   }
   return N;
}

// *********************** FUNCION CONSULTA *******************

void CONSULTA(int N, int ARREGLO[15])
{
   int I;
   if (N == 0)
   {
      gotoxy(20, 24);
      cout << "NO Existe Vector";
      getch();
   }
   else
   {
      TITULOS();
      gotoxy(26, 9);
      cout << "CONSULTAR VALORES AL VECTOR";
      gotoxy(25, 14);
      cout << "VECTOR = ";
      for (I = 0; I < N; I++)
         cout << ARREGLO[I] << "   ";
      gotoxy(25, 19);
      cout << "Pulse cualquier tecla para salir ";
      getch();
   }
}

// ***************** FUNCION ORDENAR ( Metodo Lineal) **************

void ORDENAR_LINEAL(int N, int ARREGLO[])
{
   if (N == 0)
   {
      gotoxy(20, 24);
      cout << "NO Existe Vector";
      getch();
   }
   else
   {
      int K, I, AUX;
      TITULOS();
      gotoxy(28, 9);
      cout << "ORDENAR - METODO LINEAL";
      for (K = 0; K < N - 1; K++)
         for (I = K + 1; I < N; I++)
            if (ARREGLO[K] > ARREGLO[I])
            {
               AUX = ARREGLO[K];
               ARREGLO[K] = ARREGLO[I];
               ARREGLO[I] = AUX;
            }
      gotoxy(28, 14);
      cout << "OK, Lista quedo ordenada";
      getch();
   }
}

// *************** FUNCION ORDENAR (Metodo Burbuja) **************

void ORDENAR_BURBUJA(int N, int ARREGLO[])
{
   if (N == 0)
   {
      gotoxy(20, 24);
      cout << "NO Existe Vector";
      getch();
   }
   else
   {
      int K, I, AUX;
      TITULOS();
      gotoxy(28, 9);
      cout << "ORDENAR - METODO BURBUJA";
      for (I = 1; I < N; I++)
         for (K = N - 1; K >= I; K--)
         {
            if (ARREGLO[K - 1] > ARREGLO[K])
            {
               AUX = ARREGLO[K - 1];
               ARREGLO[K - 1] = ARREGLO[K];
               ARREGLO[K] = AUX;
            }
         }
      gotoxy(28, 14);
      cout << "OK, Lista quedo ordenada";
      getch();
   }
}

// ******************** FUNCION ELIMINAR ****************

int ELIMINAR(int N, int ARREGLO[])
{
   int VALOR, I, K, SW;
   if (N == 0)
   {
      gotoxy(20, 24);
      cout << "NO Existe Vector";
      getch();
   }
   else
   {
      TITULOS();
      gotoxy(15, 19);
      cout << "Digite valor entre 0 - 99 ";
      do
      {
         gotoxy(15, 15);
         cout << "Introducir un valor Entero  [    ]";
         gotoxy(44, 15);
         cin >> VALOR;
         gotoxy(15, 19);
         cout << "ERROR ....Digite valor entre 0 - 99 ";
      } while ((VALOR < 0) || (VALOR > 99));
      gotoxy(15, 19);
      cout << "                                        ";
      gotoxy(15, 15);
      cout << "                                        ";
      SW = 0;
      for (K = 0; K < N; K++)
         if (VALOR == ARREGLO[K])
         {
            SW = 1;
            for (I = K; I < N; I++)
               ARREGLO[I] = ARREGLO[I + 1];
            N--;
            gotoxy(28, 14);
            cout << "OK, Elemento Eliminado en la Lista";
         }
      if (SW == 0)
      {
         gotoxy(28, 14);
         cout << "Elemento NO Existe en la Lista " << VALOR;
      }
      getch();
      return N;
   }
}