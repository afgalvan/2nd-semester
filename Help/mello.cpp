#include <iostream>
#include <string>
#include <string.h>

int main()
{
    char palabra[100];
    int tam_palabra;

    std::cout << "Ingrese una palabra: ";
    std::cin.getline(palabra, 100, '\n');
    tam_palabra = strlen(palabra);

    if(tam_palabra >= 3 && tam_palabra < 10)
        std::cout << "True";
    else
        std::cout << "False";
    return 0;
}