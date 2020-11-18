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

void titulo();
int menu();
int recibir_tam(int tam, string text);
void leer_arreglo(int filas, int columnas, int matriz[][10]);
void consultar(int filas, int columnas,  int matriz[][10]);
void mostrar_vector(int filas, int columnas, int matriz[][10]);

main()
{
    int opc, filas = 0, columnas = 0;
    int matriz[10][10];

    do
    {
        titulo();
        opc = menu();
        switch (opc)
        {
        case 1:
            titulo();
            gotoxy(45, 9);
            cout << "ASIGNAR VALORES A LA MATRIZ";
            gotoxy(44, 24);
            cout << "Digite valor entre 0 - 10 ";
            filas = recibir_tam(filas, "filas");
            columnas = recibir_tam(columnas, "columnas");
            gotoxy(44, 24);
            cout << "                                        ";
            leer_arreglo(filas, columnas, matriz);
            break;
        case 2:
            consultar(filas, columnas, matriz);
            break;
        case 3:
            mostrar_vector(filas, columnas, matriz);
            break;
        };
    } while (opc != 4);
    system("cls");
    getch();
}

void titulo()
{
    system("color 2F");
    system("cls");
    gotoxy(42, 5);
    cout << "UNIVERSIDAD  POPULAR  DEL  CESAR";
    gotoxy(44, 6);
    cout << "CREAR Y CONSULTAR UN ARREGLO";
}

int recibir_tam(int tam, string pedir)
{
    do
    {
        gotoxy(58, 13);
        cout << "                               ";
        gotoxy(41, 13);
        cout << "Ingrese cantidad de " << pedir << ": ";
        cin >> tam;
    } while ((tam < 0) || (tam > 10));
    gotoxy(41, 13);
    cout << "                                         ";
    return tam;
}

int menu()
{
    int opcion;

    gotoxy(39, 9);
    cout << "1. ASIGNAR VALORES A LA MATRIZ";
    gotoxy(39, 10);
    cout << "2. CONSULTAR VALORES DE LA MATRIZ";
    gotoxy(39, 11);
    cout << "3. MOSTRAR COMO VECTOR";
    gotoxy(39, 13);
    cout << "4. SALIR DEL PROGRAMA";
    do
    {
        gotoxy(55, 16);
        cout << "                       ";
        gotoxy(39, 16);
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 4);
    return opcion;
}

void leer_arreglo(int filas, int columnas, int matriz[][10])
{
    int i, k;

    for (i = 0; i < filas; i++)
    {
        for (k = 0; k < columnas; k++)
        {
            gotoxy(40, 13); cout << "Introducir un valor: ";
            cin >> matriz[i][k];
            gotoxy(61, 13); cout << "                     ";
        }
    }
}

void consultar(int filas, int columnas,  int matriz[][10])
{
    int i, k, f = 12;
    if ((filas == 0) || (columnas == 0))
    {
        gotoxy(50, 24);
        cout << "NO Existe Vector";
        getch();
    }
    else
    {
        titulo();
        gotoxy(44, 9);
        cout << "CONSULTAR VALORES DE LA MATRIZ.";
        for (i = 0; i < filas; i++)
        {
            gotoxy(45, f);
            for (k = 0; k < columnas; k++)
                cout << matriz[i][k] << "   ";
            f++;
        }
        gotoxy(43, f+5);
        cout << "Pulse cualquier tecla para salir ";
        getch();
    }
}

void mostrar_vector(int filas, int columnas, int matriz[][10])
{
    int i, k, f, j = 14, vector[100];

    if ((filas == 0) || (columnas == 0))
    {
        gotoxy(50, 24);
        cout << "NO Existe Vector";
        getch();
    }
    else
    {
        titulo();
        gotoxy(51, 9);
        cout << "MOSTRAR VECTOR.";
        j = 0;
        for (i = 0; i < filas; i++)
        {
            for (k = 0; k < columnas; k++)
            {
                vector[j] = matriz[i][k];
                j++;
            }
        }
        gotoxy(43, 12);
        for (i = 0; i < filas*columnas; i++)
        {
            cout << vector[i] << "   ";
        }
        gotoxy(43, 16);
        cout << "Pulse cualquier tecla para salir ";
        getch();
    }
}
