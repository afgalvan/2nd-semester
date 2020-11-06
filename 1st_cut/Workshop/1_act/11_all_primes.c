/* 11) Mostrar por pantalla todos los números que sean primos menores a un
 * número N leído desde el teclado. */

#include "lib/grizzly.h"

void menu();
void ask_number();
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
    center_print("NUMEROS PRIMOS.", 2);
    subsection = title_align() * 0.9;

    gotoxy(subsection, 4);
    printf("INGRESE UN EL LIMITE: ");
    ask_number();
}

void ask_number()
{
    char str_number[50], *rte;
    bool is_numeric;
    unsigned long long limit, i;
    
    do
    {
        gotoxy(subsection+22, 4);
        printf("                        ");
        
        gotoxy(subsection+22, 4);
        scanf("%s", str_number);
        is_numeric = only_numbers(str_number, 'p');
        error_msg("Error. solo números postivos", 6);
    } while(!is_numeric);
    center_print("                              ", 6);
    
    limit = strtoull(str_number, &rte, 10);
    
    for(i = 2; i < limit; i++)
        if(is_prime(i))
            printf("%llu, ", i);
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
