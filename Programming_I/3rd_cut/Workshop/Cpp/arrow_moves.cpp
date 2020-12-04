#include <iostream>
#include <string>
#include <conio.h>
#include "controllers.hh"

void UpDownArrowMoves(int position_x, int position_y, int down_limit);
int PageMove(int index);

int main()
{
    system("cls");

    int key;
    gotoxy(25, 5);
    std::cout << "Option 1: ";
    gotoxy(25, 6);
    std::cout << "Option 2: ";
    gotoxy(25, 7);
    std::cout << "Option 2: ";
    gotoxy(25, 8);
    std::cout << "Option 2: ";
    UpDownArrowMoves(36, 5, 8);

    system("cls");
    for (int i = 0; i < 6; i++)
    {
        std::cout << i;
        i += PageMove(i);
    }
    
    
    return 0;
}

void UpDownArrowMoves(int position_x, int position_y, int down_limit)
{
    int key_pressed, line = position_y;
    int up_key = 72, down_key = 80, enter_key = 13, esc_key = 27;

    while (true)
    {
        gotoxy(position_x, line);
        key_pressed = getch();
        if (key_pressed == 0)
            key_pressed = getch();

        if (key_pressed == up_key)
            line--;
        else if (key_pressed == down_key)
            line++;
        else if (key_pressed == esc_key)
            break;
        if (line > down_limit)
            line = position_y;
        else if (line < position_y)
            line = down_limit;
    }
}

int PageMove(int index)
{
    int key_pressed;
    int left_key = 75, right_key = 77;

    while(true)
    {
        key_pressed = getch();
        if (key_pressed == 0)
            key_pressed = getch();
        
        if (key_pressed == left_key)
        {
            if (index > 0)
                return -2;
            return -1;
        }
        else if (key_pressed == right_key)
            return 0;
    }
}