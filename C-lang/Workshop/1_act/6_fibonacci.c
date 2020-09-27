#include "lib/grizzly.h"
#include <math.h>

void ask_limit();
void fibonacci_gen(int limit);

int main()
{
    set_window();
    printf(white_blue);
    if (OS == "Windows")
        system("color F1");
    else
        printf(clrscr);
    system(clean);
    center_print("FIBONACCI", 4);
    ask_limit();
    repeat_program(main, "Desea repetir el programa", 20);
    return 0;
}

void ask_limit()
{
    int i, range_int;
    int center = title_align();
    char range[100];
    bool is_number;

    do
    {
        gotoxy(center + 19, 6);
        printf("                                                   ");
        if (OS == "Windows")
        {
            gotoxy(center, 6);
            printf("Cuantos n%cmeros desea mostrar: ", 163);
        }
        else
        {
            center_print("Cuantos números desea mostrar: ", 6);
        }
        gotoxy(center + 19, 6);
        scanf("%s", range);
        is_number = only_numbers(range, 'p');
    } while (!is_number || atoi(range) > 94 || atoi(range) < 1);

    range_int = atoi(range);

    fibonacci_gen(range_int);
}

void fibonacci_gen(int limit)
{
    unsigned long x, y;
    double PHI = (1 + pow(5, 0.5)) / 2;
    printf("\n");
    for (x = 0; x < limit; x++)
    {
        y = round((pow(PHI, x) - (pow(1 - PHI, x))) / pow(5, 0.5));
        printf("%lu", y);
        if (x < limit - 1)
            printf(", ");
        else
            printf(".\n");
    }
}
