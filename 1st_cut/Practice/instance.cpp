/*******************************************************************************
 *                                                                             *
 *   Este Programa permite leer desde el teclado valores para la variable :    *
 *   CEDULA, NOMBRE,  DIRECCION, ESATDO CIVIL y SEXO . Luego imprime en        *
 *	 Pantalla los valores asignados a las variables.                       *
 *                                                                             *
 *******************************************************************************/

#include <stdio.h>    // para printf, puts, putchar o getchar
#include <windows.h>  // libreria para gotoxy(USHORT x,USHORT y) 
#include <iostream>  // entrada y salida (cin>> y el cout<<)
#include <conio.h>   // entrada para getche y getch

using namespace std; // esta directiva es obligatoria para cin>> y cout<< , no se te olvide

int gotoxy(USHORT x,USHORT y){                                  // Esta funcion es obligatoria
COORD cp={x,y};                                                 // para que pueda funcionar la
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   // sentencia gotoxy
}

main(){
    int CEDULA ;
    char NOMBRE[20], DIRECCION[30], EST_CIVIL[15], SEXO;
    long TEL;
    system("cls");      	//limpia pantalla
    system("color 1F");
    gotoxy(25,4); cout<<"UNIVERSIDAD POPULAR DEL CESAR";
    gotoxy(24,5); cout<<"PROGRAMA INGENIERIA DE SISTEMAS"; 
    gotoxy(20,8); cout<< "CEDULA     : ";
    gotoxy(20,9); cout<< "NOMBRE     : ";
    gotoxy(20,10); cout<< "DIRECCION  : " ;
    gotoxy(20,11); cout<< "TELEFONO   : " ;
    gotoxy(20,12); cout<< "SEXO  M/F  : " ;
    gotoxy(20,13); cout<< "EST. CIVIL : " ;
    gotoxy(33,8); cin>> CEDULA;
    cin.sync();
    gotoxy(33,9); gets(NOMBRE);
    gotoxy(33,10); gets(DIRECCION);
    gotoxy(33,11); cin>>TEL;
    cin.sync();
    gotoxy(33,12); SEXO = getchar() ;
    cin.sync();
    gotoxy(33,13); gets(EST_CIVIL); 
    gotoxy(34,15); printf( "DATOS LEIDOS");
    gotoxy(20,17); cout<< "CEDULA     = " << CEDULA;
    gotoxy(20,18); cout<< "NOMBRE     = " << NOMBRE;
    gotoxy(20,19); cout<< "DIRECCION  = " << DIRECCION ;
    gotoxy(20,20); cout<< "TELEFONO   = " << TEL;
    gotoxy(20,21); cout<< "SEXO       = " << SEXO ;
    gotoxy(20,22); cout<< "EST. CIVIL = " << EST_CIVIL ; 
    gotoxy(4,24); cout << "EN LA PARTE SUPERIOR DERECHA DE LA VENTANA HAGA CLIC EN LA 'X' PARA SALIR";
    getch();
    }
