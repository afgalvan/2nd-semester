//                          PROGRAMACIÓN DE COMPUTADORES 1
//                      FACULTAD DE INGENIERIA Y TECNOLOGICAS
//                       PROGRAMA DE INGENIERIA DE SISTEMAS

//                           EJERCICIOS PARA REVISAR

// RECOMENDACIÓN :  COPIE CADA PROGRAMA Y LUEGO PEGELO EN  DEV C++

// ************************ PROBLEMA No 7 DEL TALLER No 3 *************************

/*******************************************************************************
 *                                                                             *
 *   PERMITE CREAR, ORDENAR(Metodo Lineal) E IMPRIMIR LOS VALORES DE UN        *
 *   VECTOR DE MAX = 10 ELEMENTOS                                              *
 *   PROBLEMA No 7 DEL TALLER No 3                                             *
 *                                                                             *
 *******************************************************************************/

#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int gotoxy(USHORT x, USHORT y)
{
   COORD cp = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void TITULOS();
int MENU();

main()
{
   int I, K, AUX, TIPO;
   char OP = 'S';
   int VECTOR[10], N = 0;
   while (OP == 'S')
   {
      TITULOS();
      TIPO = MENU();
      switch (TIPO)
      {

      case 1:
         TITULOS();
         gotoxy(27, 9);
         cout << "ASIGNAR VALORES AL VECTOR";

         do
         {
            gotoxy(15, 13);
            cout << "Digite el No de Elemetos, Max = 10 :      ";
            gotoxy(52, 13);
            cin >> N;
         } while ((N < 0) || (N > 10));
         gotoxy(15, 13);
         cout << "                                               ";

         for (I = 0; I < N; I++)
         {
            gotoxy(15, 19);
            cout << "Digite valor entre 0 - 99 ";
            do
            {
               gotoxy(15, 15);
               cout << "Introducir un valor Entero para la posicion " << I << " [    ]";
               gotoxy(62, 15);
               cin >> VECTOR[I];
               gotoxy(15, 19);
               cout << "ERROR ....Digite valor entre 0 - 99 ";
            } while ((VECTOR[I] < 0) || (VECTOR[I] > 99));
            gotoxy(15, 19);
            cout << "                                        ";
         }
         break;

      case 2:
         if (N == 0)
         {
            gotoxy(20, 24);
            cout << " No existen elementos en la Listas";
            getch();
         }
         else
         {
            TITULOS();
            gotoxy(26, 10);
            cout << "ORDENAR VECTOR E IMPRIMIR";

            // **** RUTINA DE IMPRIMIR VECTOR INICIAL ****

            gotoxy(25, 14);
            cout << "VECTOR  INICIAL = ";
            for (I = 0; I < N; I++)
               cout << VECTOR[I] << "   ";

            // **** RUTINA DE ORDENAMIENTO - METODO LINEAL ****

            for (K = 0; K < N - 1; K++)
               for (I = K + 1; I < N; I++)
                  if (VECTOR[K] > VECTOR[I])
                  {
                     AUX = VECTOR[K];
                     VECTOR[K] = VECTOR[I];
                     VECTOR[I] = AUX;
                  }
            // **** RUTINA DE IMPRIMIR VECTOR ORDENADO ****

            gotoxy(25, 17);
            cout << "VECTOR ORDENADO = ";
            for (I = 0; I < N; I++)
               cout << VECTOR[I] << "   ";

            gotoxy(25, 22);
            cout << "Pulse cualquier tecla para salir ";
            getch();
         }
         break;

      case 3:
         OP = 'N';
         break;
      }
   }
}

void TITULOS()
{
   system("cls");
   system("color F1");
   gotoxy(22, 6);
   cout << "CREAR, ORDENAR E IMPRIMIR UN VECTOR";
   gotoxy(34, 7);
   cout << "METODO LINEAL";
}

int MENU()
{
   int TIPO;
   gotoxy(26, 10);
   cout << "1 - ASIGNAR VALORES AL VECTOR";
   gotoxy(26, 11);
   cout << "2 - ORDENAR VECTOR E IMPRIMIR";
   gotoxy(26, 13);
   cout << "3 - SALIR DEL PROGRAMA";
   do
   {
      gotoxy(24, 16);
      cout << "Seleccine una alternativa :  ";
      gotoxy(54, 16);
      cin >> TIPO;
   } while ((TIPO < 1) || (TIPO > 3));
   return TIPO;
}

// ************************ PROBLEMA No 8 DEL TALLER No 3 *************************

/*******************************************************************************
 *                                                                             *
 *   PERMITE CREAR, ORDENAR(Metodo Burbuja) E IMPRIMIR LOS VALORES DE UN       *
 *   VECTOR DE MAX = 10 ELEMENTOS                                              *
 *   PROBLEMA No 8 DEL TALLER No 3                                             *
 *                                                                             *
 *******************************************************************************/

#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int gotoxy(USHORT x, USHORT y)
{
   COORD cp = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void TITULOS();
int MENU();

main()
{
   int I, K, AUX, TIPO;
   char OP = 'S';
   int VECTOR[10], N = 0;
   while (OP == 'S')
   {
      TITULOS();
      TIPO = MENU();
      switch (TIPO)
      {

      case 1:
         TITULOS();
         gotoxy(27, 9);
         cout << "ASIGNAR VALORES AL VECTOR";

         do
         {
            gotoxy(15, 13);
            cout << "Digite el No de Elemetos, Max = 10 :      ";
            gotoxy(52, 13);
            cin >> N;
         } while ((N < 0) || (N > 10));
         gotoxy(15, 13);
         cout << "                                               ";

         for (I = 0; I < N; I++)
         {
            gotoxy(15, 19);
            cout << "Digite valor entre 0 - 99 ";
            do
            {
               gotoxy(15, 15);
               cout << "Introducir un valor Entero para la posicion " << I << " [    ]";
               gotoxy(62, 15);
               cin >> VECTOR[I];
               gotoxy(15, 19);
               cout << "ERROR ....Digite valor entre 0 - 99 ";
            } while ((VECTOR[I] < 0) || (VECTOR[I] > 99));
            gotoxy(15, 19);
            cout << "                                        ";
         }
         break;

      case 2:
         if (N == 0)
         {
            gotoxy(20, 24);
            cout << " No existen elementos en la Listas";
            getch();
         }
         else
         {
            TITULOS();
            gotoxy(26, 10);
            cout << "ORDENAR VECTOR E IMPRIMIR";

            // **** RUTINA DE IMPRIMIR VECTOR INICIAL ****

            gotoxy(25, 14);
            cout << "VECTOR  INICIAL = ";
            for (I = 0; I < N; I++)
               cout << VECTOR[I] << "   ";

            // **** RUTINA DE ORDENAMIENTO - METODO BURBUJA ****

            for (I = 1; I < N; I++)
               for (K = N - 1; K >= I; K--)
                  if (VECTOR[K - 1] > VECTOR[K])
                  {
                     AUX = VECTOR[K - 1];
                     VECTOR[K - 1] = VECTOR[K];
                     VECTOR[K] = AUX;
                  }

            // **** RUTINA DE IMPRIMIR VECTOR ORDENADO ****

            gotoxy(25, 17);
            cout << "VECTOR ORDENADO = ";
            for (I = 0; I < N; I++)
               cout << VECTOR[I] << "   ";

            gotoxy(25, 22);
            cout << "Pulse cualquier tecla para salir ";
            getch();
         }
         break;

      case 3:
         OP = 'N';
         break;
      }
   }
}

void TITULOS()
{
   system("cls");
   system("color F1");
   gotoxy(22, 6);
   cout << "CREAR, ORDENAR E IMPRIMIR UN VECTOR";
   gotoxy(34, 7);
   cout << "METODO BURBUJA";
}

int MENU()
{
   int TIPO;
   gotoxy(26, 10);
   cout << "1 - ASIGNAR VALORES AL VECTOR";
   gotoxy(26, 11);
   cout << "2 - ORDENAR VECTOR E IMPRIMIR";
   gotoxy(26, 13);
   cout << "3 - SALIR DEL PROGRAMA";
   do
   {
      gotoxy(24, 16);
      cout << "Seleccine una alternativa :  ";
      gotoxy(54, 16);
      cin >> TIPO;
   } while ((TIPO < 1) || (TIPO > 3));
   return TIPO;
}

// ********************* PROBLEMA No 10 DEL TALLER No 3 **********************

/**************************************************************************
 *                                                                        *
 *   PERMITE CREAR Y/O ADICIONAR, CONSULTAR , ORDENAR Y ELIMINAR VALORES  *
 *   EN UNA LISTA DE MAXIMO 15 ELEMENTOS                                  *
 *   PROBLEMA No 10 DEL TALLER No 3                                       *
 *                                                                        *
 **************************************************************************/

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

// ********************* PROBLEMA No 13 DEL TALLER No 3 ********************

/************************************************************************
 *                                                                      *
 *   PERMITE CREAR E IMPRIMIR LOS VALORES DE UNA MATRIZ MAX = 10X10.    * 
 *   ASIMISMO, OBTIENE UN VECTOR CON LA SUMA DE LAS FILAS DE LA MATRIZ  *  
 *   PROBLEMA No 13 DEL TALLER No 3                                     *
 *                                                                      *
 ************************************************************************/

#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int gotoxy(USHORT x, USHORT y)
{
   COORD cp = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

void TITULOS();
int MENU();
void CREAR(int ARREGLO[10][10], int NF, int NC);
void CONSULTA(int ARREGLO[10][10], int NF, int NC);

main()
{
   char CONTROL = 'S';
   int OPCION, N, M;
   int MATRIZ[10][10];

   while (CONTROL == 'S')
   {
      TITULOS();
      OPCION = MENU();

      switch (OPCION)
      {
      case 1:
         TITULOS();
         gotoxy(26, 9);
         cout << "ASIGNAR VALORES A LA MATRIZ";
         do
         {
            gotoxy(15, 13);
            cout << "Digite el No de Filas, Max = 10    :      ";
            gotoxy(52, 13);
            cin >> N;
         } while ((N < 0) || (N > 10));

         do
         {
            gotoxy(15, 14);
            cout << "Digite el No de Columnas, Max = 10 :      ";
            gotoxy(52, 14);
            cin >> M;
         } while ((M < 0) || (M > 10));
         gotoxy(15, 13);
         cout << "                                               ";
         gotoxy(15, 14);
         cout << "                                               ";
         CREAR(MATRIZ, N, M);
         break;
      case 2:
         CONSULTA(MATRIZ, N, M);
         break;
      case 3:
         CONTROL = 'N';
      };
   }
}

void TITULOS()
{
   system("cls");
   system("color B0");
   gotoxy(26, 6);
   cout << "CREAR E IMPRIMIR UN ARREGLO";
}

int MENU()
{
   int OP;
   gotoxy(36, 7);
   cout << "M E N U";
   gotoxy(26, 10);
   cout << "1 - CAPTURAR VALORES A LA MATRIZ";
   gotoxy(26, 11);
   cout << "2 - IMPRIMIR MATRIZ Y OBTENER VECTOR";
   gotoxy(26, 13);
   cout << "3 - SALIR DEL PROGRAMA";
   do
   {
      gotoxy(24, 16);
      cout << "Seleccine una alternativa :  [ _ ]";
      gotoxy(55, 16);
      cin >> OP;
   } while ((OP < 1) || (OP > 3));
   return OP;
}

void CREAR(int ARREGLO[10][10], int NF, int NC)
{
   int K, I;
   TITULOS();
   gotoxy(26, 7);
   cout << "CAPTURAR VALORES A LA MATRIZ";
   for (I = 0; I < NF; I++)
   {
      gotoxy(15, 19);
      cout << "Digite valor entre 0 - 99 ";
      for (K = 0; K < NC; K++)
      {
         do
         {
            gotoxy(15, 15);
            cout << "Introducir un valor  [   ]";
            gotoxy(37, 15);
            cin >> ARREGLO[I][K];
            gotoxy(15, 19);
            cout << "ERROR ......Digite valor entre 0 - 99 ";
         } while ((ARREGLO[I][K] < 0) || (ARREGLO[I][K] > 99));
         gotoxy(15, 19);
         cout << "Digite valor entre 0 - 99                ";
      }
   }
}

/*********** IMPRIME LA MATRIZ, CALCULA EL VECTOR Y LO IMPRIME *********/

void CONSULTA(int ARREGLO[10][10], int NF, int NC)
{
   int VECTOR[10], I, K, F;
   TITULOS();
   gotoxy(21, 7);
   cout << "IMPRIMIR LA MATRIZ Y VECTOR RESULTANTE";
   F = 11;
   gotoxy(20, F);
   cout << "MATRIZ = ";
   for (I = 0; I < NF; I++)
   {
      VECTOR[I] = 0;
      gotoxy(30, F);
      for (K = 0; K < NC; K++)
      {
         printf("%3d %3s", ARREGLO[I][K], "   ");
         VECTOR[I] = VECTOR[I] + ARREGLO[I][K];
      }
      F++;
   }

   gotoxy(20, F += 2);
   cout << "VECTOR =  ";
   for (I = 0; I < NF; I++)
      cout << VECTOR[I] << "   ";

   gotoxy(20, F + 3);
   cout << "Pulse cualquier tecla para salir";
   getch();
}