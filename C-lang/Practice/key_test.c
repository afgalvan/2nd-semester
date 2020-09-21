#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gotoxy(int x, int y);

int main()
{
    bool itis = true;
    gotoxy(25, 4); printf("EJEMPLO");
    if (!itis)
        printf("Bro, es falso");
    return 0;
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
