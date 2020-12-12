
/**********************************************************************
 *  ESTE PROGRAMA ES CREADO CON EL FIN DE CONFIRMAR EL FUNCIONAMIENTO *
 *  DE ARCHIVOS TEXTO                                                 *
 *                                        	                          *
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

int gotoxy(USHORT x, USHORT y)
{
    COORD cp = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}

/********************* DECLARACION DE FUNCIONES ********************/

void CAPTURA();
void CONSULTA();
int MENU();

fstream DATOS;

/*************************** PRINCIPAL **************************/

main()
{
    char OP = 'S';
    int SW;
    while (OP == 'S')
    {
        SW = MENU();
        switch (SW)
        {

        case 1:
            CAPTURA();
            break;
        case 2:
            CONSULTA();
            break;
        case 3:
            OP = 'N';
        }
    }
}

/***************************** MENU ****************************/

int MENU()
{
    int OPCION;
    system("cls");
    system("color F0");
    gotoxy(33, 5);
    cout << "CUEROLANDIA LTDA";
    gotoxy(37, 7);
    cout << "M E N U";
    gotoxy(33, 9);
    cout << "ARCHIVO TEXTO";
    gotoxy(28, 12);
    cout << "1. CREAR, ADICIONAR EN EL ARCHIVO";
    gotoxy(28, 14);
    cout << "2. CONSULTAR EL ARCHIVO";
    gotoxy(28, 16);
    cout << "3. SALIR ";
    do
    {
        gotoxy(28, 20);
        cout << "SELECCIONE UNA ALTERNATIVA ";
        cin >> OPCION;
    } while ((OPCION < 1) || (OPCION > 3));
    return OPCION;
}

/**************************** CAPTURA ****************************/

void CAPTURA()
{
    DATOS.open("D:\\DATOSBAS\\TEXTO.dat", ios ::app);
    char LINEA[50], OPCION = 'S';
    while (OPCION == 'S')
    {
        system("cls");
        gotoxy(33, 5);
        cout << "CUEROLANDIA LTDA";
        gotoxy(30, 7);
        cout << "REGISTRO DE LOS DATOS";
        gotoxy(20, 11);
        cout << "Digite Linea : ";
        cin.sync();
        gets(LINEA);
        DATOS << LINEA << endl;
        do
        {
            gotoxy(28, 22);
            cout << "DESEA CONTINUAR - S/N - ";
            OPCION = getch();
            OPCION = toupper(OPCION);
        } while ((OPCION != 'S') && (OPCION != 'N'));
    }
    DATOS.close();
}

/***************************** CONSULTA ****************************/

void CONSULTA()
{
    DATOS.open("D:\\DATOSBAS\\TEXTO.dat", ios ::in);
    char LINEA[50], OPCION = 'S';
    int F;
    if (DATOS.fail())
    {
        gotoxy(20, 10);
        cout << " NO EXISTE ARCHIVO ";
        getch();
    }
    else
    {
        system("cls");
        F = 13;
        gotoxy(33, 7);
        cout << "CUEROLANDIA LTDA";
        gotoxy(36, 9);
        cout << "DATOS LEIDOS";
        while (!DATOS.eof())
        {
            DATOS.getline(LINEA, sizeof(LINEA));
            gotoxy(10, F);
            cout << LINEA << endl;
            F++;
        }
        gotoxy(10, F + 3);
        cout << "Pulse Cualquier Tecla y Regresa al Menu";
        getch();
        DATOS.close();
    }
}
