#include <iostream>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    // Put the cursor in determinate point of the Window.
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int DigitsOf(int number)
{
    int digits = 0, n = number;
    if (number == 0)
        return 1;
    while (n != 0)
    {
        n /= 10;
        digits++;
    }
    return digits;
}

void DisplayArray(int array[], int size, int position_x)
{
    int i, j, center_table = 30;

    gotoxy(center_table, 8+position_x);
    std::cout << char(218);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < DigitsOf(array[i]); j++)
            std::cout << char(196);
        if (i + 1 < size)
            std::cout << char(194);
    }
    std::cout << char(191);

    gotoxy(center_table, 9+position_x);
    std::cout << char(179);
    for (i = 0; i < size; i++)
    {
        std::cout << array[i];
        std::cout << char(179);
    }

    gotoxy(center_table, 10+position_x);
    std::cout << char(192);
    int x;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < DigitsOf(array[i]); j++)
            std::cout << char(196);
        if (i + 1 < size)
            std::cout << char(193);
    }
    std::cout << char(217);
}

int main()
{
    int array[6][6] = {{2, 1, 0, 2}, {1, 2, 3, 4}, {8, 5, 6, 2}, {4, 1, 3, 2}};
    int i, j;
    int max = 0;

    for (i = 0, j = 4; i < 4; i++, j += 2)
        DisplayArray(array[i], 4, j);
    
    return 0;
}