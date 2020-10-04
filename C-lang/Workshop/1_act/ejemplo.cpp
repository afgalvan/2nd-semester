#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

int main()
{
    gotoxy(35, 10);
    printf("HOLA, COMO ESTAS?\n");
    getchar();
    return 0;
}
