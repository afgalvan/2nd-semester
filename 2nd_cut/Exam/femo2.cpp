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
int leer_arreglo(int n, int arreglo[]);
void consultar(int n, int arreglo[]);
void sumar(int n, int arreglo[]);
void eliminar(int n, int arreglo[]);

main()
{
    int opc, tam = 0;
    int vector[10];

    do
    {
        titulo();
        opc = menu();
        switch (opc)
        {
        case 1:
            tam = leer_arreglo(tam, vector);
            break;
        case 2:
            consultar(tam, vector);
            break;
        case 3:
            sumar(tam, vector);
            break;
        case 4:
            eliminar(tam, vector);
            break;
        };
    } while (opc != 5);
    system("cls");
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

int menu()
{
    int opcion;

    gotoxy(39, 9);
    cout << "1. ASIGNAR VALORES AL VECTOR";
    gotoxy(39, 10);
    cout << "2. CONSULTAR VALORES AL VECTOR";
    gotoxy(39, 11);
    cout << "3. SUMAR VECTOR";
    gotoxy(39, 12);
    cout << "4. ELIMINAR EN EL VECTOR ";
    gotoxy(39, 14);
    cout << "5. SALIR DEL PROGRAMA";
    do
    {
        gotoxy(55, 17);
        cout << "                       ";
        gotoxy(39, 17);
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 6);
    return opcion;
}

int leer_arreglo(int n, int arreglo[])
{
    char op = 'S';
    int i;

    titulo();
    gotoxy(45, 9);
    cout << "ASIGNAR VALORES AL VECTOR";
    gotoxy(44, 24);
    cout << "Digite valor entre 0 - 10 ";
    do
    {
        gotoxy(58, 13);
        cout << "                               ";
        gotoxy(41, 13);
        cout << "Ingrese el tamaño del vector : ";
        cin >> n;
        gotoxy(41, 24);
        cout << "ERROR... Digite valor entre 0 - 10 ";
    } while ((n < 0) || (n > 10));
    gotoxy(41, 24);
    cout << "                                        ";

    system("cls");
    titulo();
    for (i = 0; i < n; i++)
    {
        gotoxy(60, 13);
        cout << "                               ";
        gotoxy(41, 13);
        cout << "[" << i << "] Ingrese un valor para el vector : ";
        cin >> arreglo[i];
    }
    
    return n;
}

void consultar(int n, int arreglo[])
{
    int i;

    if (n == 0)
    {
        gotoxy(50, 24);
        cout << "NO Existe Vector";
        getch();
    }
    else
    {
        titulo();
        gotoxy(44, 9);
        cout << "CONSULTAR VALORES AL VECTOR.";
        gotoxy(45, 14);
        for (i = 0; i < n; i++)
            cout << arreglo[i] << "   ";
        gotoxy(43, 19);
        cout << "Pulse cualquier tecla para salir ";
        getch();
    }
}

void sumar(int n, int arreglo[])
{
    int i, acum = 0;

    if (n == 0)
    {
        gotoxy(55, 24);
        cout << "NO Existe Vector";
        getch();
    }
    else
    {
        titulo();
        gotoxy(45, 9);
        cout << "SUMAR VALORES DEL VECTOR";
        gotoxy(45, 12);
        for (i = 0; i < n; i++)
            cout << arreglo[i] << "   ";
        gotoxy(51, 14);
        cout << "RESULTADO";
        gotoxy(55, 15);
        for (i = 0; i < n; i++)
            acum += arreglo[i];
        cout << acum;
        gotoxy(42, 19);
        cout << "Pulse cualquier tecla para salir ";
        getch();
    }
}

void eliminar(int n, int arreglo[])
{
    if (n == 0)
    {
        gotoxy(55, 24);
        cout << "NO Existe Vector";
        getch();
    }
    else
    {
        titulo();
        gotoxy(45, 9);
        cout << "ELMINAR ELEMENTO DEL VECTOR";
    }
    
}
