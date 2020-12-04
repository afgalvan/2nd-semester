#include <iostream>
#include <conio.h>


int main()
{
    int key;

    system("cls");
    while (true)
    {
        key = getch();
        if (key == 0)
            key = getch();
        std::cout << key << " <- Pressed.\n";
    }
    
    return 0;
}