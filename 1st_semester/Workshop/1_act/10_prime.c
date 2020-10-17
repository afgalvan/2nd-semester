/* 10) Recibir desde el teclado un número entero positivo y determinar si dicho
 * número es primo. */

#include "lib/grizzly.h"

void menu();
int ask_number();
bool is_prime(unsigned long long n);
int subsection;

int main()
{
    set_window();
    menu();
    repeat_program(main, "Desea repetir el programa", 10);
    system(clean);
    return 0;
}

void menu()
{
    paint_window();
    center_print("NUMERO PRIMO.", 2);
    subsection = title_align() * 0.9;

    gotoxy(subsection, 4);
    printf("INGRESE UN NUMERO: ");
    ask_number();
}

int ask_number()
{
    char str_number[50], *rte;
    bool is_numeric;
    unsigned long long number;
    
    do
    {
        gotoxy(subsection+19, 4);
        printf("                        ");
        
        gotoxy(subsection+19, 4);
        scanf("%s", str_number);
        is_numeric = only_numbers(str_number, 'p');
        error_msg("Error. solo números postivos", 6);
    } while(!is_numeric);
    center_print("                              ", 6);
    
    number = strtoull(str_number, &rte, 10);
    if(is_prime(number))
    {
        center_print("El número es primo", 6);
        return 0;
    }
    center_print("El número no es primo", 6);
    return 0;
}

bool is_prime(unsigned long long n)
{
    int i;

    if(n < 2) return false;

    for(i = 2; i < n; i++)
        if(n % i == 0)
            return false;
    return true;
}
