#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y);
int BuildArray(int N, int ARREGLO[15]);
void ArrayManagement(char process);
void DisplayArray(int ARREGLO[15], int N);

int size = 0;

void gotoxy(int x, int y)
{
    // Put the cursor in determinate point of the Window.
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int main()
{
    char choice;
    while (true)
    {
        system("cls");
        cin >> choice;
        ArrayManagement(choice);
    }
    
    return 0;
}

void ArrayManagement(char process)
{
    int array[10];

    switch (process)
    {
    case '1':
        size = BuildArray(size, array);
        cout << size;
        getch();
        break;
    case '2':
        cout << size;
        getch();
        DisplayArray(array, size);
        break;
    case '3':
        break;
    }
}

int BuildArray(int N, int ARREGLO[15])
{
    char OP = 'S';
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

void DisplayArray(int ARREGLO[15], int N)
{
    getch();
    int I;
    if (N == 0)
    {
        gotoxy(20, 24);
        cout << "NO Existe Vector";
        getch();
    }
    else
    {
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