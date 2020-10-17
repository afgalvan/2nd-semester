#include <iostream>

int main()
{
    int n, i, total;

    std::cout << "Ingrese un numero: ";
    std::cin >> n;
    std::cout << "\n";

    for(int i = 1; i <= 12; i++)
    {
        total = n * i;
        std::cout << n << " x " << i << " = " << total;
        std::cout <<"\n";
    }
    return 0;
}