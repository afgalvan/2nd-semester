#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int c;
    float s, a;
    cout << "* Digite su categoria: ";
    cin >> c;
    cout << "* Digite su sueldo: ";
    cin >> s;
    cout << "\n";
    switch (c)
    {
    case 1:
        a = (s + (s * 0.08));
        cout << "Su nuevo sueldo es: " << a;
        break;
    case 2:
        a = (s - (s * 0.05));
        cout << "Su nuevo sueldo es: " << a;
        break;
    case 3:
        a = (s + (s * 0.03));
        cout << "Su nuevo sueldo es: " << a;
        break;
    case 4:
        a = (s * 2);
        cout << "Su nuevo sueldo es: " << a;
        break;
    }
    getch();
}