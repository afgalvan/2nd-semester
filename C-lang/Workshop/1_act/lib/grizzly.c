#include <stdio.h>   // The C standard library for in and out
#include <string.h>  // C library for strings managament
#include <stdbool.h> // C library for boolean operations
#include <stdlib.h>  // C standard library for main functions
#include <ctype.h>   // Varible type manipulation

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64) || defined(NT_)
//Group Windows 32-bits and 64-bits
    #include <conio.h>
    #include <windows.h>
    #define OS "Windows"
    #define clean "cls"
    #define stop getch()
#elif linux
    #include <ncurses.h> // CLI Window manipulation
    #define OS "Linux"
    #define clean "clear"
    #define stop fflush(stdin);getchar()
#endif

#define clrscr "\e[1;1H\e[2J"
#define white "\e[1;97m"
#define red "\e[1;91m"
#define reset "\e[0;0m"
#define white_blue "\e[0;34;107m"

int height, width, centered;

int title_align()
{
    return centered;
}

void set_window()
{
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64) || defined(NT_)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ret;
    ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    if (ret)
        width = csbi.dwSize.X;
#else
    initscr();
    getmaxyx(stdscr, height, width);
    endwin();
#endif
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

int center_this(char content[])
{
    int title_width = strlen(content);
    centered = (width - title_width) / 2;
    return centered;
}

void center_print(char text[], int Y)
{
    center_this(text);
    gotoxy(centered, Y);
    printf("%s\n", text);
}

void repeat_program(int main_function(), char message[], int Y)
{
    char choice[100], separator[] = {"-----------------------------"};
    int choice_int, X, defect_height = Y;

    X = (width - strlen(separator)) / 2;

    gotoxy(X - 1, Y);
    printf("%s", separator);
    Y++;
    if (OS == "Linux") {
        gotoxy(X, Y); printf("¿%s?", message);
        Y++;
    }
    else {
        gotoxy(X, Y); printf("%c%s?", 168, message);
        Y++;
    }
    gotoxy(X, Y); printf("[1] Si."); Y++;
    gotoxy(X, Y); printf("[2] No."); Y += 2;
    gotoxy(X, Y); printf("> "); scanf("%s", choice);
    fflush(stdin);

    choice_int = atoi(choice);

    if (choice_int == 1)
    {
        main_function();
    }
    else if (choice_int != 2)
    {
        gotoxy(X+1, Y); printf("                        ");
        repeat_program(main_function, message, defect_height);
    }
}

void error_identifier(char errorID[], int x, int y)
{
    gotoxy(x, y);
    printf("\nEn \"%s\".\n", errorID);
}

void error_msg(char error_text[], int Y)
{
    printf(red);
    center_print(error_text, Y);
    printf(white);
    printf(white_blue);
}

bool only_numbers(char input[], char numbers_range)
{
    bool invalid_input;
    int i;

    invalid_input = false;

    for (i = 0; i < strlen(input); i++)
    {
        if (tolower(numbers_range) == 'a')
        {
            if (input[0] == '-')
                continue;
        }
        else if (tolower(numbers_range) == 'n')
        {
            if (input[0] != '-')
                return false;
        }
        if (!isdigit(input[i]))
        {
            invalid_input = true;
            break;
        }
    }

    if (!invalid_input)
        return true;
    return false;
}

bool only_letters(char input[])
{
    bool invalid_input;
    int i;

    invalid_input = false;

    for (i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]))
        {
            invalid_input = true;
            break;
        }
    }

    if (!invalid_input)
        return true;
    return false;
}
