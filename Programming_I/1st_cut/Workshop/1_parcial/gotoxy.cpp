/* First Programming I test
 * Primer parcial de Programación I
 * Andrés Felipe Galván
 * 08/10/2020 */

#include <iostream>  // C++ standard library
#include <string.h>  // C library for better string management 
//Microsoft libraries
#include <conio.h>
#include <windows.h> // Library for window manipulation

#define WHITE "\e[1;97m"
#define RED "\e[1;91m"
#define BACKGROUND "\e[0;34;107m"

void gotoxy(int x, int y);

// Window dimension and text position.
int width, center_position, subsection;

int main()
{
    gotoxy(30, 30);
    std::cout << "G\n";
    return 0; // My linter requires to return int on main function
}

void gotoxy(int x, int y)
{
    // Put the cursor in determinate point of the Window.
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}