/****************************************************************
*                                                               *
*   CALCULA LA TABLA DE MULTIPLICAR DE UN NUMERO (1 AL 12)      *
*   DIGITADO DESDE EL TECLADO                                   *
*                                                               *
*****************************************************************/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int gotoxy(USHORT x, USHORT y)
{
    COORD cp = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

main()
{

    int J, K, T, F, N;
    char OP = 'S';
    while (OP == 'S')
    {
        system("cls");
        system("color 1F");
        gotoxy(30, 5);
        cout << "TABLA DE MULTIPLICAR";
        gotoxy(25, 22);
        cout << "EL VALOR DEBE SER ENTRE 1 y 12";
        do
        {
            gotoxy(25, 8);
            cout << "Digite el Numero de Calculo : ";
            gotoxy(55, 8);
            cin >> N;
            gotoxy(25, 22);
            cout << "ERROR.....EL VALOR DEBE SER ENTRE 1 y 12";
        } while ((N <= 0) || (N > 12));
        system("cls");
        gotoxy(31, 5);
        cout << "TABLA DE MULTIPLICAR DEL " << N;
        F = 8;
        for (J = 1; J <= 12; J++)
        {
            T = N * J;
            gotoxy(34, F);
            printf(" %2d %3s %2d %3s %2d", J, " X ", N, " = ", T);
            F++;
        }
        do
        {
            gotoxy(31, F + 3);
            cout << "DESEA CONTINUAR  S/N : ";
            OP = getch();
            OP = toupper(OP);
        } while ((OP != 'S') && (OP != 'N'));
    }
}