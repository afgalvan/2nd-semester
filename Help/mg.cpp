#include <iostream>

void Preguntar();
void CalcularInteres(long double capital, float interes, int tiempo);

int main()
{
    system("cls");
    Preguntar();
    return 0;
}

void Preguntar()
{
    long double capital;
    float interes;
    int tiempo; // Tiempo en años

    do
    {
        std::cout << "\nIngrese el capital: ";
        std::cin >> capital;
    } while (capital < 0);

    do
    {
        std::cout << "\nIngrese el interes (porcentaje): ";
        std::cin >> interes;
    } while (interes < 0);

    do
    {
        std::cout << "\nIngrese los a" << char(164) << "os: ";
        std::cin >> tiempo;
    } while (tiempo < 1);

    CalcularInteres(capital, interes, tiempo);
}

void CalcularInteres(long double capital, float interes, int tiempo)
{
    int i;
    long double res;

    for (i = 0; i < tiempo; i++)
        res = (capital * interes) / 100;
    capital = capital + res;
    system("cls");
    std::cout << "\n" << capital;
}
