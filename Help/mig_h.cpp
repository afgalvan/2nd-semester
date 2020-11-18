#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void Titulo();
void Menu();
int SoloNumeros(char texto[]);
int Preguntar(string pregunta);
void Porcentaje(long double capital[], float porcentajes[]);
int Hombres(int sexo[]);
int Mujeres(int sexo[]);
float Promedio(long double capital[]);
void Resultados(float porcentajes[], int hombres, int mujeres, float prom);

int main()
{
    Menu();
    getch();
    return 0;
}

void Titulo()
{
    system("cls");
    cout << "\n\t\t\t\tURIBE TECH.";
    cout << "\n\t\t\tINVERSIONES DE LA EMPRESA.\n\n";
}

void Menu()
{
    int sexo[6];
    long double capital[6];
    float porcentajes[6], prom;
    int i, hombres_cont = 0, mujeres_cont = 0;

    Titulo();
    for (i = 0; i < 6; i++)
    {
        cout << "\n";
        do
        {
            sexo[i] = Preguntar("* Ingrese su sexo (1 - Hombre, 2 - Mujer): ");
        } while (sexo[i] != 1 && sexo[i] != 2);
        do
        {
            capital[i] = Preguntar("* Ingrese la cantidad de su inversion: ");
        } while (capital[i] < 1);
    }

    Porcentaje(capital, porcentajes);
    hombres_cont = Hombres(sexo);
    mujeres_cont = Mujeres(sexo);
    prom = Promedio(capital);

    Resultados(porcentajes, hombres_cont, mujeres_cont, prom);
}

int SoloNumeros(char texto[])
{
    int i;
    // "400d"
    for (i = 0; i < strlen(texto); i++)
    {
        if (!isdigit(texto[i]))
        {
            return 0;
        }
    }
    return 1;
}

int Preguntar(string pregunta)
{
    int i;
    char aux[30];

    do
    {
        cout << pregunta;
        cin >> aux;
    } while (!SoloNumeros(aux));
    return atoi(aux);
}

void Porcentaje(long double capital[], float porcentajes[])
{
    int i;
    long double total_invertido = 0;

    for (i = 0; i < 6; i++)
        total_invertido += capital[i];
    for (i = 0; i < 6; i++)
        porcentajes[i] = (capital[i] / total_invertido) * 100;
}

int Hombres(int sexo[])
{
    int i, hombres = 0;

    for (i = 0; i <= 6; i++)
    {
        switch (sexo[i])
        {
        case 1:
            hombres++;
            break;
        }
    }
    return hombres;
}

int Mujeres(int sexo[])
{
    int i, mujeres = 0;

    for (i = 0; i < 6; i++)
    {
        switch (sexo[i])
        {
        case 2:
            mujeres++;
            break;
        }
    }
    return mujeres;
}

float Promedio(long double capital[])
{
    int i;
    long double total_invertido = 0;

    for (i = 0; i < 6; i++)
        total_invertido += capital[i];
    return total_invertido / 6;
}

void Resultados(float porcentajes[], int hombres, int mujeres, float prom)
{
    int i;

    system("cls");
    cout << "\n\t\t\t\tRESULTADOS.\n\n";
    cout << "\nPorcentajes:\n";
    for ( i = 0; i < 6; i++)
    {
        cout << i+1 << ". " << porcentajes[i] << "%\n";
    }
    cout << "\nCantidad de Hombres:\n";
    cout << hombres << "\n";
    cout << "\nCantidad de Mujeres:\n";
    cout << mujeres << "\n";
    cout << "\nPromedio invertido:\n";
    cout << prom << "\n";
}