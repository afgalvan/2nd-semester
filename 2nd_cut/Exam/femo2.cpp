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
int leer_arreglo(int arreglo[]);
void consultar(int n, int arreglo[]);

main()
{
    int opc, num = 0;
    int vector[10];

    do
    {
        titulo();
        opc = menu();
        switch (opc)
        {
        case 1:
            num = leer_arreglo(vector);
            break;
        case 2:
            consultar(num, vector);
            break;
        };
    } while (opc != 6);
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
    cout << "3. ORDENAR EL VECTOR (Metodo Lineal) ";
    gotoxy(39, 12);
    cout << "4. ORDENAR EL VECTOR (Metodo Burbuja) ";
    gotoxy(39, 13);
    cout << "5. ELIMINAR EN EL VECTOR ";
    gotoxy(39, 15);
    cout << "6. SALIR DEL PROGRAMA";
    do
    {
        gotoxy(39, 18);
        cout << "Seleccione una opcion: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 6);
    return opcion;
}

int leer_arreglo(int arreglo[])
{
    char op = 'S';
    int n;

    titulo();
    gotoxy(27, 9);
    cout << "ASIGNAR VALORES AL VECTOR";
    while ((op == 'S') && (n < 15))
    {
        gotoxy(15, 24);
        cout << "Digite valor entre 0 - 99 ";
        do
        {
            gotoxy(15, 13);
            cout << "Introducir un valor Entero  [    ]";
            gotoxy(44, 13);
            cin >> arreglo[n];
            gotoxy(15, 24);
            cout << "ERROR ....Digite valor entre 0 - 99 ";
        } while ((arreglo[n] < 0) || (arreglo[n] > 99));
        gotoxy(15, 24);
        cout << "                                        ";
        n = n + 1;
        do
        {
            gotoxy(20, 20);
            cout << "Desea Capturar un Nuevo Elemento  S/n :   ";
            op = getche();
            op = toupper(op);
        } while ((op != 'S') && (op != 'n'));
    }
    return n;
}

void consultar(int n, int arreglo[])
{
    int I;
    if (n == 0)
    {
        gotoxy(20, 24);
        cout << "NO Existe Vector";
        getch();
    }
    else
    {
        titulo();
        gotoxy(26, 9);
        cout << "CONSULTAR VALORES AL VECTOR";
        gotoxy(25, 14);
        cout << "vector = ";
        for (I = 0; I < n; I++)
            cout << arreglo[I] << "   ";
        gotoxy(25, 19);
        cout << "Pulse cualquier tecla para salir ";
        getch();
    }
}
