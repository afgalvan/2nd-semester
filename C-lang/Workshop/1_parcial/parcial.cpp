#include <iostream>  // C++ standard library
#include <string.h>  // C library for better string management 
//Microsoft libraries
#include <conio.h>
#include <windows.h> // Library for window manipulation

#define white "\e[1;97m"
#define red "\e[1;91m"
#define white_blue "\e[0;34;107m"

void menu();
void ask_user(char user_input[], char var_type, int line);
void set_window();
void paint_window();
void gotoxy(int x, int y);
int center_this(std::string content);
void center_printf(std::string text, int Y);
bool check_value(std::string input, char type);
void error_msg(std::string error_text, int Y);
void repeat_program(int main_function(), int static_height);

int width, center_position, subsection;

int main()
{
    set_window();
    menu();
    // getch();
    repeat_program(main, 7);
    return 0;
}

void menu()
{
    char user_dni[35], name[35];

    paint_window();
    center_printf("PARCIAL", 2);
    subsection = center_position * 0.9;

    gotoxy(subsection, 4);
    std::cout << "CEDULA: ";
    gotoxy(subsection, 5);
    std::cout << "NOMBRE: ";

    ask_user(user_dni, 'n', 4);
    ask_user(name, 'l', 5);
}

void ask_user(char user_input[], char var_type, int line)
{
    bool is_valid;

    do
    {
        gotoxy(subsection+8, line);
        std::cout << "                                       ";

        gotoxy(subsection+8, line);
        std::cin.getline(user_input, 35, '\n');
        is_valid = check_value(user_input, var_type);

        error_msg("Error. valores invalidos.", 7);
    } while (!is_valid);
    center_printf("                                     ", 7);
}

void set_window()
{
    HWND hwnd = GetConsoleWindow();
    if( hwnd != NULL ) ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    int ret;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    if(ret)
        width = csbi.dwSize.X;
}

void paint_window()
{
    std::cout << white_blue;
    system("color F1");
    system("cls");
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

int center_this(std::string content)
{
    int title_width = content.length();
    center_position = (width - title_width) / 2;
    return center_position;
}

void center_printf(std::string text, int Y)
{
    int x_position = center_this(text);
    gotoxy(x_position, Y);
    std::cout << text;
}

bool check_value(std::string input, char type)
{
    int i;

    for(i = 0; i < input.length(); i++)
        if(!isdigit(input[i]) && type == 'n')
            return false;
        else if(isdigit(input[i]) && type == 'l')
            return false;
    return true;
}

void error_msg(std::string error_text, int Y)
{
    std::cout << red;
    center_printf(error_text, Y);
    std::cout << white;
    std::cout << white_blue;
}

void repeat_program(int main_function(), int static_height)
{
    std::string choice;
    char separator[] = {"-----------------------------"};
    int X, Y = static_height;

    X = (width - strlen(separator)) / 2;
    
    // paint_window();
    gotoxy(X - 1, Y); std::cout << separator;
    Y++;
    gotoxy(X, Y); std::cout << char(168) << "Desea repetir el programa?";
    Y++;
    gotoxy(X, Y); std::cout << "[1] Si.";
    Y++;
    gotoxy(X, Y); std::cout << "[2] No.";
    Y += 2;
    do
    {
        gotoxy(X + 1, Y);
        // std::cout << "                                  ";
        gotoxy(X, Y); std::cout << "> ";
        choice = getche();
    } while(choice != "2" || choice == "1");

    if(choice == "1")
        main_function();
}
