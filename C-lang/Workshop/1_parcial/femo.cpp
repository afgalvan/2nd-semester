#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int gotoxy(SHORT x,SHORT y){         
COORD cp={x,y};                                               
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); 
}

main() {
    char OP = 'S';
    char var1[30], var2[30];
    unsigned var3, var4;
     while (OP == 'S') {
        system("cls");
        system("color F1");

        gotoxy(29, 4); cout<<"TITULO PARCIAL";
        gotoxy(24, 6); cout<<"INGRESA ALGO  : ";
        gotoxy(24, 7); cout<<"INGRESA ALGO2 : ";
        gotoxy(24, 8); cout<<"INGRESA ALGO3 : ";
        gotoxy(24, 9); cout<<"INGRESA ALGO4 : ";

        gotoxy(40, 6); gets(var1);
        gotoxy(40, 7); gets(var2);
        do {
            gotoxy(40, 8); cin >> var3;
        } while (var3 <= 0);
        cin.sync();
        do {
            gotoxy(40, 9); cin >> var4;
        } while (var3 <= 0);
        cin.sync();

        do {
        	gotoxy(27,20); cout<< "DESEA CONTINUAR  S/N : " ;
        	OP = getche();
        	OP = toupper(OP);
        }  while ((OP != 'S') && (OP != 'N'));
    }
}