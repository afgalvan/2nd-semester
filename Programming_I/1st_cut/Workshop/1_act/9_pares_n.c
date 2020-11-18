#include "lib/grizzly.h"

void menu();
void ask_numbers(char user_input[]);
void pair_numbers(unsigned long long n);

int subsection;

int main()
{
    set_window();
    menu();
    repeat_program(main, "Desea repetir el programa", 15);
    system(clean);
    return 0;
}

void menu()
{
    char number_str[50], *prt;
    unsigned long long number;

    paint_window();
    center_print("NUMEROS PARES", 2);
    subsection = title_align() * 0.95;
    gotoxy(subsection, 4);
    printf("INGRESE UN NUMERO: ");

    ask_numbers(number_str);
    number = strtoull(number_str, &prt, 10);
    pair_numbers(number);
}

void ask_numbers(char user_input[])
{
    bool is_number;

    do
    {
        gotoxy(subsection+19, 4);
        printf("                                   ");
        
        gotoxy(subsection+19, 4);
        scanf("%s", user_input);
        is_number = only_numbers(user_input, 'p');
        error_msg("Error. solo numeros positivos", 6);
    } while(!is_number || atoi(user_input) <= 1);
    center_print("                                   ", 6);
}


void pair_numbers(unsigned long long n)
{
    unsigned long long i;
    
    gotoxy(20, 6);
    for(i = 2; i <= n; i += 2)
        printf("%llu, ", i);
}
