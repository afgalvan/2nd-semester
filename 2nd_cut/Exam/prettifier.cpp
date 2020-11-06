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

void LargestInColumn(int list[], int array[][6], int rows, int columns)
{
    int c, r;
    int max;

    for (c = 0; c < columns; c++)
    {
        max = 0;
        for (r = 0; r < rows; r++)
            if (DigitsOf(array[r][c]) > max)
                max = DigitsOf(array[r][c]);
        list[c] = max;
    }
    
}

void DelimiterLines(int r, int columns, int lines[])
{
    int c;
    int l;
    
    if (r == 0)
            std::cout << char(218);
    else
        std::cout << char(195);
    for (c = 0; c < columns; c++)
    {
        for (l = 0; l < lines[c]; l++)
            std::cout << char(196);
        if (c + 1 < columns)
            if (r == 0)
                std::cout << char(194);
            else
                std::cout << char(197);
    }

    if (r == 0)
        std::cout << char(191);
    else
        std::cout << char(180);
}

void DownLines(int columns, int lines[])
{
    int c, l;

    std::cout << char(192);
    for (c = 0; c < columns; c++)
    {
        for (l = 0; l < lines[c]; l++)
            std::cout << char(196);
        if (c + 1 < columns)
            std::cout << char(193);
        else
            std::cout << char(217);
    } 
}

void DisplayArray(int array[][6], int rows, int columns)
{
    int r, c;
    int a, l, lines[columns];
    int i, blanks;

    LargestInColumn(lines, array, rows, columns);

    for (r = 0, a = 0; r < rows; r++, a+=2)
    {
        gotoxy(30, 8+a);
        DelimiterLines(r, columns, lines);

        gotoxy(30, 9+a);
        std::cout << char(179);
        for (c = 0; c < columns; c++)
        {
            std::cout << array[r][c];
            blanks = lines[c] - DigitsOf(array[r][c]);
            for (i = 0; i < blanks; i++)
                std::cout << " ";
            std::cout << char(179);
        }

        gotoxy(30, 10+a);
        DownLines(columns, lines);
    }
    getch();
}

int main()
{
    int array[6][6] = {{12121, 1, 32, 2}, {1, 2222, 33, 4}, {8, 5, 6, 0}, {11, 1, 3, 777}};

    DisplayArray(array, 4, 5);
    return 0;
}
