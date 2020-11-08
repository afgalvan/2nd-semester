#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;
void PedirValores();
void RaizReal(float a, float b, float c);

int main()
{
    PedirValores();
    return 0;
}

void PedirValores()
{
    float a, b, c;

    system("cls");
    cout << "\t\t\tRAICES REALES.\n\n";
    cout << "ax^2 + bx + c = 0\n\n";

    cout << "* Valor de a: ";
    cin >> a;
    cout << "* Valor de b: ";
    cin >> b;
    cout << "* Valor de c: ";
    cin >> c;
    
    cout << "\n";
    RaizReal(a, b, c);
    getch();
}

void RaizReal(float a, float b, float c)
{
    float disc = pow(b, 2.0) - 4 * a * c; // Valor discriminante
    float x1, x2, xr, xi;


    if (disc > 0.0)
    {
        x1 = ((-b + sqrt(disc))/(2.0*a));
        x2 = ((-b - sqrt(disc))/(2.0*a));
        cout << "La ecuacion tiene dos raices reales.\n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    else
    {
        if (disc == 0)
        {
            x1 = (-b)/(2.0*a);
            cout << "La ecuacion tiene una raiz.\n";
            cout << "x1 = " << x1 << "\n";
        }
        else
        {
            xr = (-b/(2.0*a));
            xi = (sqrt(-disc)/(2.0*a));
            cout << "La raiz real es = " << xr << "\n";
            cout << "La raiz imaginaria es = " << xi << "\n";
        }
    }
}

