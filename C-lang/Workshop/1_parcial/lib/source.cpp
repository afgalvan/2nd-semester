#include <stdio.h>   // The C standard library for in and out
#include <string.h>  // C library for strings managament
#include <stdbool.h> // C library for boolean operations
#include <stdlib.h>  // C standard library for main functions
#include <ctype.h>   // Varible type manipulation

//Windows libraries
#include <conio.h>
#include <windows.h>

#define clean "cls"
#define stop getch()
#define clrscr "\e[1;1H\e[2J"
#define white "\e[1;97m"
#define red "\e[1;91m"
#define reset "\e[0;0m"
#define white_blue "\e[0;34;107m"

void menu();
void ask_user(char user_input[], char var_type, int line);
void set_window();
void paint_window();
void gotoxy(int x, int y);
int center_this(char content[]);
void center_printf(char text[], int Y);
bool check_value(char input[], char type);
void error_msg(char error_text[], int Y);
void repeat_program(int main_function(), int static_height);

int width, center_position, subsection;

int main()
{
    set_window();
    menu();
    repeat_program(main, 10);
    return 0;
}

void menu()
{
    char user_dni[25], name[35];

    paint_window();
    center_printf("PARCIAL", 2);
    subsection = center_position * 0.9;

    gotoxy(subsection, 4);
    printf("CEDULA: ");
    gotoxy(subsection, 5);
    printf("NOMBRE: ");

    ask_user(user_dni, 'n', 4);
    ask_user(name, 'l', 5);

}

void ask_user(char user_input[], char var_type, int line)
{
    bool is_valid;

    do
    {
        gotoxy(subsection+8, line);
        printf("                                       ");

        gotoxy(subsection+8, line);
        scanf("%s", user_input);
        is_valid = check_value(user_input, var_type);

        error_msg("Error. valores invalidos.", 7);
    } while (!is_valid);
    center_printf("                                  ", 7);
    
}

void set_window()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    if(ret)
        width = csbi.dwSize.X;
}

void paint_window()
{
    printf(white_blue);
    system("color F1");
    system(clean);
}

void gotoxy(int x, int y)
{
    COORD cp={x,y};                                               
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); 
}

int center_this(char content[])
{
    int title_width = strlen(content);
    center_position = (width - title_width) / 2;
    return center_position;
}

void center_printf(char text[], int Y)
{
    center_this(text);
    gotoxy(center_position, Y);
    printf("%s\n", text);
}

bool check_value(char input[], char type)
{
    int i;

    for(i = 0; i < strlen(input); i++)
        if(!isdigit(input[i]) && type == 'n')
            return false;
        else if(isdigit(input[i]) && type == 'l')
            return false;
    return true;
}

void error_msg(char error_text[], int Y)
{
    printf(red);
    center_printf(error_text, Y);
    printf(white);
    printf(white_blue);
}

void repeat_program(int main_function(), int static_height)
{
    char choice_char[100], separator[] = {"-----------------------------"};
    int choice, X, Y = static_height;

    X = (width - strlen(separator)) / 2;
    
    gotoxy(X - 1, Y); printf("%s", separator);
    Y++;
    gotoxy(X, Y); printf("%cDesea repetir el programa?", 168);
    Y++;
    gotoxy(X, Y); printf("[1] Si.");
    Y++;
    gotoxy(X, Y); printf("[2] No.");
    Y += 2;
    gotoxy(X + 1, Y);
    printf("                                  ");
    gotoxy(X, Y); printf("> ");
    scanf("%s", choice_char);
    fflush(stdin);

    choice = atoi(choice_char);

    if(choice == 1)
        main_function();
    else if(choice != 2)
        repeat_program(main_function, static_height);
}