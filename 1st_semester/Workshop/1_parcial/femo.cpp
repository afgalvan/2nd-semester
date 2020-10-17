#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <windows.h>

using namespace std; 

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}
main() {
	char NOMBRE[30];
	float sexo, edad,var1,var2,estado_civil,hombrecumple=0,mujercumple=0,contador=0, acum=0,acum2=0;
	char OP='S';
	while(OP=='S'){
		system("cls");
		system("color F5");
		
		gotoxy(28,4); cout<<" UNIVERSIDAD POPULAR DEL CESAR             ";
		gotoxy(28,5); cout<<" FACULTAD DE INGENIERIA DE SISTEMAS        ";
		gotoxy(20,10); cout<<" DIGITE SU NOMBRE:               ";
		gotoxy(20,11); cout<<" DIGITE SU SEXO:            ";
		gotoxy(20,12); cout<<" DIGITE SU EDAD:            ";
		gotoxy(20,13); cout<<" DIGITE SU ESTADO CIVIL:            ";
		
		gotoxy(39,10); cout<<"             ";
		gotoxy(39,10); gets(NOMBRE);
		
do {
gotoxy(31,17); cout<< "  " ;
gotoxy(20,24); cout << " DIGITE : M-> MASCULINO O F -> FEMENINO " ;
gotoxy(37,11); sexo = getchar();
sexo = toupper(sexo) ;
} while((sexo != 'M')&&( sexo != 'F'));
gotoxy(20,24); cout <<"                                                                                         ";
cin.sync();
		
	do {	
	         gotoxy(39,12) ; cin >> edad;
	         gotoxy(20,22); cout<< "Error .... valor fuera de rango ";
	      } while ((edad <= 0) || (edad > 100));
          gotoxy(20,22); cout <<"                                   ";
          cin.sync();
		
		
	do {
gotoxy(31,17); cout<< " " ;
gotoxy(10,23); cout << " DIGITE :S->SOLTERO,C->CASADO,U->UNION LIBRE" ;
gotoxy(45,13); estado_civil = getchar();
estado_civil = toupper(estado_civil) ;
} while ((estado_civil != 'S') && ( estado_civil != 'C') && ( estado_civil != 'U'));
cin.sync();

		contador = contador+1;
		acum=acum+hombrecumple;
		acum2=acum2+mujercumple;
		
		if(sexo == 'M' && estado_civil == 'C' && edad > 40 )
	    var1=hombrecumple;
		else if(sexo == 'F' && estado_civil == 'S' && edad < 50 )
		var2=mujercumple;
           do
           {
               gotoxy(28, 16);
               cout << " DESEA CONTINUAR S-N   ";
               OP = getch();
               OP = toupper(OP);
           } while ((OP != 'S') && (OP != 'N'));
    }	


	system("cls");
		
	
		gotoxy(50,5); printf("%30s %2.2f"," HOMBRES QUE CUMPLEN =",var1);
		gotoxy(50,6); printf("%30s %2.2f"," MUJERES QUE CUMPLEN=",var2);
		
		getch(); 
		
	}
