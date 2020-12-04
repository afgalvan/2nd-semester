/***********************************************************************
 *  ESTE PROGRAMA ES CREADO CON EL FIN DE CONFIRMAR EL FUNCIONAMIENTO  *
 *  DE ARCHIVOS SECUENCIALES Y LAS OPERACIONES BASICAS                 *
 *                                        	                           *
 ***********************************************************************/

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

#define TITULO "CUEROLANDIA LTDA";
#define TITULO1 "REGITRO DE LOS DATOS";
#define TITULO2 "CONSULTA REGISTRO POR PANTALLA";
#define TITULO3 "CONSULTA SECUENCIAL TIPO LISADO";
#define TITULO4 "CONSULTA SELECTIVA";
#define TITULO5 "ELIMINAR";
#define TITULO6 "MODIFICAR";

/********************** DECLARACION DE FUNCIONES ********************/

void CREAR();
void CONSULTA_UNO_PANTALLA();
void CONSULTA_LISTADO();
void CONSULTA_SELECTIVA();
void ELIMINAR(void);
void CAMBIAR(void);
void MODIFICAR(void);
void DETALLE();

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

/*************************** PROGRAMA PRINCIPAL ***********************/

main()
{
    char OP = 'S', OPCION;
    int SW;
    while (OP == 'S')
    {
        system("cls");
        system("color F0");
        gotoxy(33, 5);
        cout << TITULO;
        gotoxy(37, 6);
        cout << "M E N U";
        gotoxy(32, 9);
        cout << "ARCHIVO SECUENCIAL";
        gotoxy(28, 12);
        cout << "1. CREAR, ADICIONAR EN EL ARCHIVO";
        gotoxy(28, 13);
        cout << "2. CONSULTA REGISTRO POR PANTALLA";
        gotoxy(28, 14);
        cout << "3. CONSULTA TIPO LISTADO";
        gotoxy(28, 15);
        cout << "4. CONSULTA SELECTIVA";
        gotoxy(28, 16);
        cout << "5. ELIMINAR REGISTRO";
        gotoxy(28, 17);
        cout << "6. MODIFICAR REGISTRO";
        gotoxy(28, 19);
        cout << "7. SALIR ";
        do
        {
            gotoxy(28, 23);
            cout << "SELECCIONE UNA ALTERNATIVA ";
            cin >> SW;
        } while ((SW < 1) || (SW > 7));

        switch (SW)
        {

        case 1:
            CREAR();
            break;
        case 2:
            CONSULTA_UNO_PANTALLA();
            break;
        case 3:
            CONSULTA_LISTADO();
            break;
        case 4:
            CONSULTA_SELECTIVA();
            break;
        case 5:
            ELIMINAR();
            break;
        case 6:
            MODIFICAR();
            break;
        case 7:
            OP = 'N';
        }
    }
}

/********************** FUNCION CREAR, Y ADICIONAR ********************/

void CREAR(void)
{
    char OPCION;
    DATOS.open("D:\\DATOSBAS\\ENERO.dat", ios ::app);
    //ofstream DATOS("D:\\DATOSBAS\\ENERO.dat", ios :: app );
    OPCION = 'S';
    while (OPCION == 'S')
    {
        system("cls");
        gotoxy(33, 5);
        cout << TITULO;
        gotoxy(30, 6);
        cout << TITULO1;
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
        } while (EMPLEADO.CEDULA < 0);
        gotoxy(20, 24);
        cout << "                                ";
        cin.sync();
        gotoxy(31, 13);
        fgets(EMPLEADO.NOMBRE, 40, stdin);
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
        } while (EMPLEADO.TEL < 0);
        gotoxy(20, 24);
        cout << "                                  ";
        do
        {
            gotoxy(31, 17);
            cout << "  ";
            gotoxy(20, 24);
            cout << " Digite : M-> Masculino o F -> Femenino ";
            gotoxy(31, 17);
            EMPLEADO.SEXO = getche();
            EMPLEADO.SEXO = toupper(EMPLEADO.SEXO);
        } while ((EMPLEADO.SEXO != 'M') && (EMPLEADO.SEXO != 'F'));
        gotoxy(20, 24);
        cout << "                                           ";
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

/********************** FUNCION CONSULTA UNO POR PANTALLA ********************/

void CONSULTA_UNO_PANTALLA()
{
    char OPCION = 'S';
    //ifstream DATOS("D:\\DATOSBAS\\ENERO.dat");
    DATOS.open("D:\\DATOSBAS\\ENERO.dat", ios ::in);
    if (DATOS.fail())
    {
        gotoxy(20, 24);
        cout << " NO EXISTE ARCHIVO ";
        OPCION = 'N';
        getch();
    }
    while (!DATOS.eof() && (OPCION == 'S'))
    {
        system("cls");
        gotoxy(33, 5);
        cout << TITULO;
        gotoxy(25, 6);
        cout << TITULO2;
        DATOS.read((char *)&EMPLEADO, sizeof(ARCHIVO));
        if (DATOS.eof())
            OPCION = 'N';
        else
        {
            gotoxy(20, 11);
            cout << "CEDULA    = " << EMPLEADO.CEDULA;
            gotoxy(20, 13);
            cout << "NOMBRE    = " << EMPLEADO.NOMBRE;
            gotoxy(20, 15);
            cout << "TELEFONO  = " << EMPLEADO.TEL;
            gotoxy(20, 17);
            cout << "SEXO      = " << EMPLEADO.SEXO;
            do
            {
                gotoxy(28, 22);
                cout << "DESEA CONTINUAR - S/N - ";
                OPCION = getch();
                OPCION = toupper(OPCION);
            } while ((OPCION != 'S') && (OPCION != 'N'));
        }
    }
    DATOS.close();
}

/********************** FUNCION CONSULTA TIPO LISTADO ********************/

void CONSULTA_LISTADO(void)
{
    int F;
    ifstream DATOS("D:\\DATOSBAS\\ENERO.dat");
    //DATOS.open("D:\\DATOSBAS\\ENERO.dat", ios :: in  );
    if (DATOS.fail())
    {
        gotoxy(20, 24);
        cout << " NO EXISTE ARCHIVO ";
        getch();
    }
    else
    {
        F = 11;
        DETALLE();
        while (!DATOS.eof())
        {
            DATOS.read((char *)&EMPLEADO, sizeof(ARCHIVO));
            if (DATOS.eof())
                break;
            gotoxy(12, F);
            cout << EMPLEADO.CEDULA;
            gotoxy(24, F);
            cout << EMPLEADO.NOMBRE;
            gotoxy(57, F);
            cout << EMPLEADO.TEL;
            gotoxy(72, F);
            cout << EMPLEADO.SEXO;
            if (F <= 24)
                F++;
            else
            {
                gotoxy(21, F += 3);
                cout << "Pulse Cualquier tecla para Continuar";
                getch();
                F = 11;
                DETALLE();
            }
        }
        gotoxy(21, F += 3);
        cout << "Pulse Cualquier tecla para Continuar";
        getch();
        DATOS.close();
    }
}

/************************ FUNCION CONSULTA SELECTIVA **********************/

void CONSULTA_SELECTIVA(void)
{
    int SW;
    char OPCION = 'S';
    long CED;
    DATOS.open("D:\\DATOSBAS\\ENERO.dat", ios ::in);
    if (DATOS.fail())
    {
        gotoxy(20, 24);
        cout << " NO EXISTE ARCHIVO ";
        getch();
    }
    else
    {
        system("cls");
        gotoxy(33, 5);
        cout << TITULO;
        gotoxy(32, 6);
        cout << TITULO4;
        gotoxy(20, 11);
        cout << "CEDULA    : ";
        cin.sync();
        do
        {
            gotoxy(31, 11);
            cin >> CED;
            //gotoxy(37,11) ; CED = VALNUMERO(37,11,10);
            gotoxy(20, 24);
            cout << "Error .... valor fuera de rango ";
        } while ((CED < 0) || (CED > 2147483640));
        gotoxy(20, 24);
        cout << "                                   ";
        SW = 0;
        while (!DATOS.eof() && SW == 0)
        {
            DATOS.read((char *)&EMPLEADO, sizeof(ARCHIVO)); // PERMITE LEER UN REGISTRO
            if (CED == EMPLEADO.CEDULA)
            {
                SW = 1;
                gotoxy(20, 13);
                cout << "NOMBRE    = " << EMPLEADO.NOMBRE;
                gotoxy(20, 15);
                cout << "TELEFONO  = " << EMPLEADO.TEL;
                gotoxy(20, 17);
                cout << "SEXO      = " << EMPLEADO.SEXO;
            }
        }
        if (SW == 0)
        {
            gotoxy(50, 11);
            cout << "REGISTRO NO EXISTE ";
        }
        gotoxy(20, 22);
        cout << "PULSE CUALQUIER TECLA Y REGRESA AL MENU";
        getch();
        DATOS.close();
    }
}

/************************ FUNCION ELIMINAR REGISTRO **********************/

void ELIMINAR(void)
{
    int SW;
    char OPCION = 'S';
    long CED;
    DATOS.open("D:\\DATOSBAS\\ENERO.dat", ios ::in);
    ofstream NUEVO("D:\\DATOSBAS\\ENERO2.dat");
    if (DATOS.fail())
    {
        gotoxy(20, 24);
        cout << " NO EXISTE ARCHIVO ";
        getch();
    }
    else
    {
        system("cls");
        gotoxy(33, 5);
        cout << TITULO;
        gotoxy(36, 6);
        cout << TITULO5;
        gotoxy(25, 11);
        cout << "CEDULA    : ";
        cin.sync();
        do
        {
            gotoxy(37, 11);
            cin >> CED;
            //gotoxy(37,11) ; CED = VALNUMERO(37,11,10);
            gotoxy(20, 24);
            cout << "Error .... valor fuera de rango ";
        } while ((CED < 0) || (CED > 2147483640));
        gotoxy(20, 24);
        cout << "                                   ";
        SW = 0;
        while (!DATOS.eof())
        {
            DATOS.read((char *)&EMPLEADO, sizeof(ARCHIVO)); // PERMITE LEER UN REGISTRO
            if (DATOS.eof())
                break;
            if (CED == EMPLEADO.CEDULA)
            {
                SW = 1;
                gotoxy(25, 13);
                cout << "NOMBRE    = " << EMPLEADO.NOMBRE;
                gotoxy(25, 15);
                cout << "TELEFONO  = " << EMPLEADO.TEL;
                gotoxy(25, 17);
                cout << "SEXO      = " << EMPLEADO.SEXO;
                gotoxy(50, 11);
                cout << "ELIMINADO REGISTRO";
            }
            else
                NUEVO.write((char *)&EMPLEADO, sizeof(ARCHIVO));
        }
        if (SW == 0)
        {
            gotoxy(50, 11);
            cout << "REGISTRO NO EXISTE ";
        }
        gotoxy(20, 22);
        cout << "PULSE CUALQUIER TECLA Y REGRESA AL MENU";
        getch();
        DATOS.close();
        NUEVO.close();
        remove("D:\\DATOSBAS\\ENERO.dat");
        rename("D:\\DATOSBAS\\ENERO2.dat", "D:\\DATOSBAS\\ENERO.dat");
    }
}

/************************ FUNCION MODIFICAR REGISTRO **********************/

void MODIFICAR(void)
{
    int SW;
    char OPCION = 'S';
    long CED;
    DATOS.open("D:\\DATOSBAS\\ENERO.dat", ios ::in);
    ofstream NUEVO("D:\\DATOSBAS\\ENERO2.dat");
    if (DATOS.fail())
    {
        gotoxy(20, 24);
        cout << " NO EXISTE ARCHIVO ";
        getch();
    }
    else
    {
        system("cls");
        gotoxy(33, 5);
        cout << TITULO;
        gotoxy(36, 6);
        cout << TITULO6;
        gotoxy(20, 11);
        cout << "CEDULA    : ";
        cin.sync();
        do
        {
            gotoxy(31, 11);
            cin >> CED;
            //gotoxy(31,11) ; CED = VALNUMERO(31,11,10);
            gotoxy(20, 24);
            cout << "Error .... valor fuera de rango ";
        } while ((CED < 0) || (CED > 2147483640));
        gotoxy(20, 24);
        cout << "                                   ";
        SW = 0;
        while (!DATOS.eof())
        {
            DATOS.read((char *)&EMPLEADO, sizeof(ARCHIVO)); // PERMITE LEER UN REGISTRO
            if (DATOS.eof())
                break;
            if (CED == EMPLEADO.CEDULA)
            {
                SW = 1;
                gotoxy(20, 13);
                cout << "NOMBRE   = " << EMPLEADO.NOMBRE;
                gotoxy(20, 15);
                cout << "TELEFONO = " << EMPLEADO.TEL;
                gotoxy(20, 17);
                cout << "SEXO     = " << EMPLEADO.SEXO;
                CAMBIAR();
                gotoxy(50, 11);
                cout << "REGISTRO MODIFICADO";
            }

            NUEVO.write((char *)&EMPLEADO, sizeof(ARCHIVO));
        }
        if (SW == 0)
        {
            gotoxy(50, 11);
            cout << "REGISTRO NO EXISTE ";
        }
        gotoxy(20, 24);
        cout << "PULSE CUALQUIER TECLA Y REGRESA AL MENU";
        getch();
        DATOS.close();
        NUEVO.close();
        remove("D:\\DATOSBAS\\ENERO.dat");
        rename("D:\\DATOSBAS\\ENERO2.dat", "D:\\DATOSBAS\\ENERO.dat");
    }
}

/*********************************** CAMBIAR **********************************/

void CAMBIAR(void)
{
    int OP = 1, F = 13;
    char TECLA;
    gotoxy(20, 21);
    cout << "Utilize Las Flechas Abajo y Arriba Para Desplazarse";
    do
    {
        gotoxy(31, F);
        TECLA = getch();
        if (kbhit())
        {
            TECLA = getch();
            if (TECLA == 80)
            {
                OP++;
                F += 2;
            }
            if (TECLA == 72)
            {
                OP--;
                F -= 2;
            }
            if ((OP > 3) || (OP < 1))
            {
                OP = 1;
                F = 13;
            }
        }
    } while ((TECLA == 80) || (TECLA == 72));

    switch (OP)
    {
    case 1:
        cin.sync();
        gotoxy(31, 13);
        cout << "                                ";
        gotoxy(31, 13);
        fgets(EMPLEADO.NOMBRE, 40, stdin);
        //gotoxy(31,13); strcpy( EMPLEADO.NOMBRE , VALCADENA(31,13,30));
        gotoxy(31, 13);
        cout << strupr(EMPLEADO.NOMBRE);
        break;
    case 2:
        do
        {
            gotoxy(31, 15);
            cout << "           ";
            gotoxy(31, 15);
            cin >> EMPLEADO.TEL;
            //gotoxy(31,15) ; EMPLEADO.TEL = VALNUMERO(31,15,10);
            gotoxy(20, 24);
            cout << "Error .... valor fuera de rango ";
        } while (EMPLEADO.TEL < 0);
        gotoxy(20, 24);
        cout << "                                  ";
        break;
    case 3:
        do
        {
            gotoxy(31, 17);
            cout << "  ";
            gotoxy(20, 24);
            cout << " Digite : M-> Masculino o F -> Femenino ";
            gotoxy(31, 17);
            EMPLEADO.SEXO = getche();
            EMPLEADO.SEXO = toupper(EMPLEADO.SEXO);
        } while ((EMPLEADO.SEXO != 'M') && (EMPLEADO.SEXO != 'F'));
        gotoxy(20, 24);
        cout << "                                           ";
        break;
    }
}

/************************** FUNCION DETALLE  ************************/

void DETALLE()
{
    system("cls");
    gotoxy(33, 5);
    cout << TITULO;
    gotoxy(24, 6);
    cout << TITULO3;
    gotoxy(12, 9);
    cout << "CEDULA      NOMBRE                           TELEFONO     SEXO ";
}

/************************ FUNCION VALIDAR NUMEROS ***********************/

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
        NUMERO = atof(fgets(CADENA1, 40, stdin));
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

/*********************** FUNCION VALIDAR CADENAS *********************/

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
        fgets(C, 40, stdin);
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
