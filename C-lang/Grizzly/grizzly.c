#include "grizzly.h"

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64) || defined(NT_)
    //Group Windows 32-bits and 64-bits
    #include <conio.h>
    #include <windows.h>
    #define OS "Windows"
    #define clean "cls"
    #define green "color A"
    #define stop getch()
#elif linux
    #include <ncurses.h> // CLI Window manipulation
    #define OS "Linux"
    #define clean "clear"
    #define green "echo -e \"\e[92m\""
    #define stop fflush(stdin);getchar()
#endif

#define white "\e[0;97m"
#define white_blue "\e[97;21;104m"
#define red "\e[1;91m"
#define reset "\e[0;0m"

int height, width, centered;

int title_align()
{
    return centered * 0.95;
}

void set_window()
{
    #if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64) || defined(NT_)
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int ret;
        ret = GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE  ),&csbi);
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

void center_print(char text[], int Y)
{
    int title_width;

    title_width = strlen(text);
    centered = (width - title_width) / 2;
    
    gotoxy(centered, Y); printf("%s\n", text);
}

void repeat_program(int main_function(), int Y)
{
    char choice[100], separator[] = {"-----------------------------"};
    int choice_int, X, defect_height = Y;
    
    X = (width - strlen(separator)) / 2;
    
    gotoxy(X-1, Y); printf("%s", separator); Y++;
    if (OS == "Linux"){
        gotoxy(X, Y); printf("¿Desea repetir el programa?"); Y++;
    }else{
        gotoxy(X, Y); printf("%cDesea repetir el programa?", 168); Y++;
    }
    gotoxy(X, Y); printf("[1] Si."); Y++;
    gotoxy(X, Y); printf("[2] No."); Y += 2;
    gotoxy(X, Y); printf("> "); 
    scanf("%s", choice);
    fflush(stdin);
    
    choice_int = atoi(choice);

    if (choice_int == 1)
    {
        main_function();
    }
    else if (choice_int != 2)
    {
        gotoxy(X+1, Y); printf("                        ");
        repeat_program(main_function, defect_height);
    }
}

void error_identifier(char errorID[], int x, int y)
{
    gotoxy(x, y); printf("\nEn \"%s\".\n", errorID);
}

void error_msg(char error_text[], int Y)
{
    printf(red);
    center_print(error_text, Y);
    printf(white);
    /* printf(white_blue); */
}

bool only_numbers(char input[], char numbers_range)
{
    bool invalid_input;
    int i;

    invalid_input = false;
    
    for (i = 0; i < strlen(input); i++)
    {
        if (tolower(numbers_range) == 'n')
            if (input[0] == '-') continue;
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
