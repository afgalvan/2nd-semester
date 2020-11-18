#include "lib/grizzly.h"
#include <stdio.h>

void menu();
void factorial(long long n);
void ask_numbers(char numeric_data[], int height);
int subsection;

int main()
{
    set_window();
    paint_window();
    center_print("CALCULAR FACTORIAL.", 4);
    menu();
    repeat_program(main, "Desea continuar", 12);
    system(clean);
    return 0;
}

void menu()
{
    char number_char[30];
    long long number;
    subsection = title_align() * 0.95;
    
    gotoxy(subsection, 6); printf("Ingrese un numero: ");
    ask_numbers(number_char, 6);
    gotoxy(subsection+19+strlen(number_char), 6);
    printf("!");
    number = atoll(number_char);
    factorial(number);
}

void factorial(long long n)
{
    unsigned long long result = 1, j;
    int i, center, digits=0;
    for(i = 1; i <= n; i++)
        result *= i;
    center = center_this("a! = b");
    j = result;
    while(j != 0)
    {
        j /= 10;
        digits++;
    }
    center -= (digits/2);
    gotoxy(center, 8);
    printf("%lld! = %llu", n, result);
}

void ask_numbers(char numeric_data[], int height)
{
    bool is_numeric;
    char nl;

    do
    {
        gotoxy(subsection+19, height);
        printf("                                                   ");
        
        gotoxy(subsection+19, height); scanf("%s", numeric_data);
        is_numeric = only_numbers(numeric_data, 'p');
        error_msg("Error. Ingrese números positivos.", 8);
    } while(!is_numeric);
    center_print("                                  ", 8);
    scanf("%c", &nl);
}
