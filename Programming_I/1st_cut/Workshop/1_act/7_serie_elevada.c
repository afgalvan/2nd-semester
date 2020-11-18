#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define clrscr "\e[1;1H\e[2J"
#define red "\e[1;91m"
#define reset "\e[0;0m"
#define white_blue "\e[0;34;107m"

void set_window();
int center_this(char text[]);
void gotoxy(int x, int y);
void center_printf(char text[], int y);
void print_title();
void menu();
bool only_numbers(char numeric_data[]);
void generate_serie(int n);
void repeat_program(int main_function());

int width, height, center_position;

int main()
{
    set_window();
    menu();
    repeat_program(main);
    system("clear");
    printf(clrscr);
    return 0;
}

void set_window()
{
    initscr();
    getmaxyx(stdscr, height, width);
    endwin();
}

int center_this(char text[])
{
    int text_len = strlen(text);
    return (width - text_len) / 2;
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

void center_printf(char text[], int y)
{
    center_position = center_this(text);
    gotoxy(center_position, y);
    printf("%s", text);
}

void print_title()
{
    printf(white_blue);
    printf(clrscr);
    system("clear");
    center_printf("SERIE DE POTENCIAS.", 4);
}

void menu()
{
    char number_char[50], nl;
    int number;
    bool is_numeric;
    int subsection;

    print_title();
    center_printf("Ingrese un numero: ", 6);
    subsection = center_position + 19;
    
    do
    {
        gotoxy(subsection, 6);
        printf("                                              ");
        
        gotoxy(subsection, 6);
        scanf("%s", number_char);
        is_numeric = only_numbers(number_char);
        printf(red);
        center_printf("Error. Ingrese números positivos", 8);
        printf(white_blue);
    } while(!is_numeric);
    scanf("%c", &nl);
    center_printf("                                              ", 8);
    
    number = atoi(number_char);
    generate_serie(number);
}

bool only_numbers(char numeric_data[])
{
    int size = strlen(numeric_data);
    int i;

    for(i = 0; i < size; i++)
    {
        if (!isdigit(numeric_data[i]))
            return false;
    }
    return true;
}

void generate_serie(int n)
{
    int i, digits, center_display;
    unsigned long long result = 0, j;

    for(i = 1; i <= n; i++)
    {
        result += pow(i, i);
    }

    j = result;
    while (j != 0)
    {
        j /= 10;
        digits++;
    }
    center_display = center_this(" ");
    center_display -= (digits/2);
    gotoxy(center_display, 8);
    printf("%llu", result);
}

void repeat_program(int main_function())
{
    char choice[15];
    char separator[] = "-------------------";
    int separator_position = center_this(separator);
    fflush(stdin);
    getchar();
    
    gotoxy(separator_position, 12);
    printf("%s", separator);
    center_printf("¿DESEA CONTINUAR?", 13);
    gotoxy(center_position, 14);
    printf("[1] SI");
    gotoxy(center_position, 15);
    printf("[2] NO");
    do
    {
        gotoxy(center_position+1, 16);
        printf("                                      ");
        
        gotoxy(center_position, 16);
        printf("> ");
        fgets(choice, sizeof(choice), stdin);
    } while(strcmp(choice, "2\n") != 0 && strcmp(choice, "1\n") != 0);

    if (strcmp(choice, "1\n") == 0)
        main_function();
}
