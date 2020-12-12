/**********************************************************************
 *  ESTE PROGRAMA ES CREADO CON EL FIN DE CONFIRMAR EL FUNCIONAMIENTO *
 *  DE ARCHIVOS INDEXADOS                                             *
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

/********************** DECLARACION DE FUNCIONES ********************/

void CAPTURA();
void CONSULTA();
int MENU();
long double VALNUMERO(int X, int Y, int T);
char *VALCADENA(int X, int Y, int T);

/********************** DECLARACION DE ESTRUCTURA ********************/

struct ARCHIVO
{
    long CEDULA;
    char NOMBRE[30];
    unsigned TEL;
    char SEXO;
} EMPLEADO;

fstream DATOS;

/************************** PROGRAMA PRINCIPAL ***********************/

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

/******************************* MENU *****************************/

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
    cout << "ARCHIVO INDEXADO";
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

/********************** FUNCION CREAR, Y ADICINAR ********************/

void CAPTURA()
{
    DATOS.open("D:\\DATOSBAS\\INDEXADO.dat", ios ::out | ios ::binary);
    //ofstream DATOS("D:\\DATOSBAS\\INDEXADO.dat", ios::app);
    char OPCION = 'S';
    while (OPCION == 'S')
    {
        system("cls");
        gotoxy(33, 5);
        cout << "CUEROLANDIA LTDA";
        gotoxy(30, 7);
        cout << "REGISTRO DE LOS DATOS";
        gotoxy(20, 11);
        cout << "CEDULA   : ";
        gotoxy(20, 13);
        cout << "NOMBRE   : ";
        gotoxy(20, 15);
        cout << "TELEFONO : ";
        gotoxy(20, 17);
        cout << "SEXO     : ";
        cin.sync();
        do
        {
            gotoxy(31, 11);
            cin >> EMPLEADO.CEDULA;
            //gotoxy(31,11) ; EMPLEADO.CEDULA = VALNUMERO(31,11,10);
            gotoxy(20, 24);
            cout << "Error .... valor fuera de rango ";
        } while ((EMPLEADO.CEDULA < 0) || (EMPLEADO.CEDULA > 2147483640));
        gotoxy(20, 24);
        cout << "                                  ";
        cin.sync();
        gotoxy(31, 13);
        gets(EMPLEADO.NOMBRE);
        //gotoxy(31,13); strcpy( EMPLEADO.NOMBRE , VALCADENA(31,13,30));
        gotoxy(31, 13);
        cout << strupr(EMPLEADO.NOMBRE);
        do
        {
            gotoxy(31, 15);
            cin >> EMPLEADO.TEL;
            //gotoxy(31,15) ; EMPLEADO.TEL = VALNUMERO(31,15,10);
            gotoxy(20, 24);
            cout << "Error .... valor fuera de rango ";
        } while ((EMPLEADO.TEL < 0) || (EMPLEADO.TEL > 4000000000));
        gotoxy(20, 24);
        cout << "                                  ";
        do
        {
            gotoxy(31, 17);
            cout << " ";
            gotoxy(20, 20);
            cout << " Digite : M-> Masculino o F -> Femenino ";
            gotoxy(31, 17);
            EMPLEADO.SEXO = getche();
            EMPLEADO.SEXO = toupper(EMPLEADO.SEXO);
        } while ((EMPLEADO.SEXO != 'M') && (EMPLEADO.SEXO != 'F'));
        gotoxy(20, 20);
        cout << "                                          ";
        DATOS.seekp((EMPLEADO.CEDULA - 1) * sizeof(ARCHIVO));
        DATOS.write((char *)&EMPLEADO, sizeof(ARCHIVO));
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

/************************** FUNCION CONSULTA ************************/

void CONSULTA()
{
    DATOS.open("D:\\DATOSBAS\\INDEXADO.dat", ios ::in | ios ::binary);
    //ifstream DATOS("D:\\DATOSBAS\\INDEXADO.dat");
    char OPCION = 'S';
    long CED;
    if (DATOS.fail())
    {
        gotoxy(20, 24);
        cout << " NO EXISTE ARCHIVO ";
        OPCION = 'N';
        getch();
    }
    while (OPCION == 'S')
    {
        system("cls");
        gotoxy(33, 7);
        cout << "CUEROLANDIA LTDA";
        gotoxy(32, 9);
        cout << "DATOS  REGISTRADOS";
        gotoxy(25, 13);
        cout << "CEDULA    : ";
        cin.sync();
        do
        {
            gotoxy(37, 13);
            cin >> CED;
            //gotoxy(37,13) ; CED = VALNUMERO(37,13,10);
            gotoxy(20, 22);
            cout << "Error .... valor fuera de rango ";
        } while (CED < 0);
        gotoxy(20, 22);
        cout << "                                   ";
        DATOS.seekg((CED - 1) * sizeof(ARCHIVO));
        DATOS.read((char *)&EMPLEADO, sizeof(ARCHIVO)); // PERMITE LEER UN REGISTRO
        if (CED != EMPLEADO.CEDULA)
        {
            gotoxy(50, 13);
            cout << "NO EXISTE REGISTRO";
        }
        else
        {
            gotoxy(25, 15);
            cout << "NOMBRE    = " << EMPLEADO.NOMBRE;
            gotoxy(25, 17);
            cout << "TELEFONO  = " << EMPLEADO.TEL;
            gotoxy(25, 19);
            cout << "SEXO      = " << EMPLEADO.SEXO;
        }
        do
        {
            gotoxy(28, 24);
            cout << "DESEA CONTINUAR - S/N - ";
            OPCION = getch();
            OPCION = toupper(OPCION);
        } while ((OPCION != 'S') && (OPCION != 'N'));
    }
    DATOS.close();
}

/************************* FUNCION VALIDAR NUMEROS ***********************/

long double VALNUMERO(int X, int Y, int T)
{
    long double NUMERO;
    char CADENA1[30];
    int SW, K, LONG, LETRA;
    do
    {
        SW = 0;
        gotoxy(X, Y);
        cout << "                                              ";
        gotoxy(X, Y);
        NUMERO = atof(gets(CADENA1));
        LONG = strlen(CADENA1);
        if (LONG > T)
        {
            gotoxy(20, 22);
            cout << "ERROR.. demasiados digitos, Max = " << T;
            getch();
            SW = 1;
        }
        else if (LONG == 0)
        {
            gotoxy(20, 22);
            cout << "ERROR.. no ha escrito nada, max = " << T;
            getch();
            SW = 1;
        }
        else
        {
            for (K = 0; K < LONG; K++)
                if (!isdigit(CADENA1[K]) && (CADENA1[K] != '.'))
                {
                    gotoxy(20, 22);
                    cout << "ERROR.. No Digite Letras";
                    getch();
                    SW = 1;
                }
        }
        gotoxy(20, 22);
        cout << "                                      ";
    } while (SW == 1);
    return NUMERO;
}

/************************* FUNCION VALIDAR CADENAS **********************/

char *VALCADENA(int X, int Y, int T)
{
    char C[40];
    int SW, K, LONG;
    do
    {
        SW = 0;
        gotoxy(X, Y);
        cout << "                                         ";
        gotoxy(X, Y);
        gets(C);
        LONG = strlen(C);
        if (LONG > T)
        {
            gotoxy(20, 22);
            cout << "ERROR.. demasiados LETRAS, Max = " << T;
            getch();
            SW = 1;
        }
        else if (LONG == 0)
        {
            gotoxy(20, 22);
            cout << "ERROR.. no ha escrito nada, max = " << T;
            getch();
            SW = 1;
        }
        else
        {
            for (K = 0; K < LONG; K++)
                if ((!isalpha(C[K])) && (C[K] != ' ') && (C[K] != '.') && (C[K] != '-') && (C[K] != '�') && (C[K] != '�'))
                {
                    gotoxy(20, 22);
                    cout << "ERROR.. Digite solo Letras";
                    getch();
                    SW = 1;
                }
        }
        gotoxy(10, 22);
        cout << "                                      ";
    } while (SW == 1);
    return C;
}
