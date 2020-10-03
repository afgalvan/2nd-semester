// WINDOWS O.S ONLY SCRIPT
#include <iostream>  // C++ standard library
#include <string.h>  // C library for better string management 
//Microsoft libraries
#include <conio.h>
#include <windows.h> // Library for window manipulation

#define WHITE "\e[1;97m"
#define RED "\e[1;91m"
#define BACKGROUND "\e[0;34;107m"

void Menu();
void AskUser(char user_input[], char var_type, int line);
void SetWindow();
void PaintWindow();
void gotoxy(int x, int y);
int CenterThis(std::string content);
void CenterPrintf(std::string text, int y);
bool CheckValue(std::string input, char type);
void ErrorMsg(std::string error_text, int y);
void RepeatProgram(int main_function(), int static_height);

int width, center_position, subsection;

using namespace std;

int main()
{
    SetWindow();
    Menu();
    // getch();
    RepeatProgram(main, 7);
    return 0; // My compiler requires to return int on main function
}

void Menu()
{
    // Put all functions together
    char user_dni[35], name[35];

    PaintWindow();
    CenterPrintf("PARCIAL", 2);
    subsection = center_position * 0.9;

    gotoxy(subsection, 4);
    std::cout << "CEDULA: ";
    gotoxy(subsection, 5);
    std::cout << "NOMBRE: ";

    AskUser(user_dni, 'n', 4);
    AskUser(name, 'l', 5);
}

void AskUser(char user_input[], char var_type, int line)
{
    // Validate if user's input it's valid
    bool is_valid;

    do
    {
        gotoxy(subsection+8, line);
        std::cout << "                                       ";

        gotoxy(subsection+8, line);
        std::cin.getline(user_input, 35, '\n');
        is_valid = CheckValue(user_input, var_type);

        ErrorMsg("Error. valores invalidos.", 7);
    } while(!is_valid);
    CenterPrintf("                                       ", 7);
}

void SetWindow()
{
    // Prepare the window to fit in the user's screeen an get information from it.
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL ) ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    int ret;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    if(ret)
        width = csbi.dwSize.X;
}

void PaintWindow()
{
    /* Paint window; white background and blue fore color,
    using a combination of cmd color code and ANSI escape code*/
    std::cout << BACKGROUND;
    system("color F1");
    system("cls");
}

void gotoxy(int x, int y)
{
    // Put the cursor in determinate point of the Window.
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int CenterThis(std::string content)
{
    // Use information given from SetWindow function to center text.
    int title_width = content.length();
    center_position = (width - title_width) / 2;
    return center_position;
}

void CenterPrintf(std::string text, int y)
{
    //Automate the process of printing center text.
    int x_position = CenterThis(text);
    gotoxy(x_position, y);
    std::cout << text;
}

bool CheckValue(std::string input, char type)
{
    // Check if a content is numeric or alphabetic.
    int i;

    for(i = 0; i < input.length(); i++)
        if(type == 'n' && !isdigit(input[i]))
            return false;
        else if(type == 'l' && isdigit(input[i]))
            return false;
    return true;
}

void ErrorMsg(std::string error_text, int y)
{
    // Print a red error message to alert the user.
    std::cout << RED;
    CenterPrintf(error_text, y);
    std::cout << WHITE;
    std::cout << BACKGROUND;
}

void RepeatProgram(int main_function(), int static_height)
{
    /* Display a menu to ask if the user wants to continue using the program.
    Repeat it calling the main function.*/
    std::string choice;
    char separator[] = {"-----------------------------"};
    int x, y = static_height;

    x = (width - strlen(separator)) / 2;
    
    // PaintWindow();
    gotoxy(x - 1, y); std::cout << separator;
    y++;
    gotoxy(x, y); std::cout << char(168) << "Desea repetir el programa?";
    y++;
    gotoxy(x, y); std::cout << "[1] Si.";
    y++;
    gotoxy(x, y); std::cout << "[2] No.";
    y += 2;
    do
    {
        gotoxy(x + 1, y);
        // std::cout << "                                  ";
        gotoxy(x, y); std::cout << "> ";
        choice = getche();
    } while(choice != "2" && choice != "1");

    if(choice == "1")
        main_function();
}
