#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

void SplashScreen();
void Menu();
std::string MenuChoice(int position_y, std::string allow_this);
int ArrayManagement(char process, int array[], int size);
int BuildArray(int array[]);
int DigitsOf(int number);
int AlingArray(int array[], int size);
void ArrayTable(int array[], int size, int line);
void DisplayArray(int array[], int size);
void SumArray(int array[], int size);
void BubbleSort(int array[], int size);
void LinearSort(int array[], int size);
void DeleteElement(int array[], int size);
bool CheckValue(std::string input, char type);
void AskUser(char user_input[], char var_type, int line, int question_len);
bool AllowedInput(std::string allowed, std::string user_input);
void SetWindow(char mode);
void gotoxy(int x, int y);
int CenterThis(std::string text);
void CenterPrint(std::string text, int position_y);
void PrintTitle(std::string title, int height);
void BoxIn(std::string options[], int options_quantity, int height);
int LongestWord(std::string words[], int len);
void RepeatProgram(int main_function(), int position_y);

int width, center, s_screen = 1;

void SplashScreen()
{
    // A Splash Screen to show when the program opens or closes.
    Sleep(190);
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t     _                        _           "
           "\n\t\t\t\t\t\t\t\t    / \\   _ __ _ __ ___  __ _| | ___  ___ "
           "\n\t\t\t\t\t\t\t\t   / _ \\ | '__| '__/ _ \\/ _` | |/ _ \\/ __|"
           "\n\t\t\t\t\t\t\t\t  / ___ \\| |  | | |  __/ (_| | | (_) \\__ \\"
           "\n\t\t\t\t\t\t\t\t /_/   \\_\\_|  |_|  \\___|\\__, |_|\\___/|___/"
           "\n\t\t\t\t\t\t\t\t                        |___/             ");
    Sleep(920);
}

int BuildArray(int array[])
{
    char size[30], number[30];
    int len, i;

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("CREAR ARREGLO UNIDIMENSIONAL", 6);

    do
    {
        gotoxy(center * 0.91, 8);
        std::cout << "Ingrese el numero de elementos: ";
        CenterPrint("Numero entero de 1 - 10", 15);
        AskUser(size, 'n', 8, center * 0.91 + 32);
        std::cout << "                                ";
        len = atoi(size);
    } while (len < 1 || len > 15);
    CenterPrint("                              ", 15);

    for (i = 0; i < len; i++)
    {
        gotoxy(center * 0.87, 8);
        std::cout << "Ingrese un valor para la posicion [" << i << "]: ";
        AskUser(number, 'n', 8, center * 0.87 + 39);
        array[i] = atoi(number);
    }

    return len;
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

int AlingArray(int array[], int size)
{
    int i, all_digits = 0, table_width;

    for (i = 0; i < size; i++)
        all_digits += DigitsOf(array[i]);
    table_width = all_digits + size + 1;

    return (width - table_width) / 2;
}

void ArrayTable(int array[], int size, int line)
{
    int i, j, center_table = AlingArray(array, size);

    gotoxy(center_table, line);
    std::cout << char(218);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < DigitsOf(array[i]); j++)
            std::cout << char(196);
        if (i + 1 < size)
            std::cout << char(194);
    }
    std::cout << char(191);

    gotoxy(center_table, line + 1);
    std::cout << char(179);
    for (i = 0; i < size; i++)
    {
        std::cout << array[i];
        std::cout << char(179);
    }

    gotoxy(center_table, line + 2);
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

void DisplayArray(int array[], int size)
{
    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("MOSTRAR ARREGLO UNIDIMENSIONAL", 6);
    ArrayTable(array, size, 8);
    CenterPrint("Presione cualquier tecla para volver... ", 22);
    getch();
}

void SumArray(int array[], int size)
{
    int i, acum, addition[1];

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("SUMAR TERMINOS DEL VECTOR", 6);

    for (i = 0; i < size; i++)
        acum += array[i];
    addition[0] = acum;

    ArrayTable(array, size, 8);
    CenterPrint("RESULTADO", 12);
    ArrayTable(addition, 1, 13);
    CenterPrint("Presione cualquier tecla para volver... ", 22);
    getch();
}

void BubbleSort(int array[], int size)
{
    // Use BubbleSort to order the array
    int i, j, aux;

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("ORDENAR ARREGLO - METODO BURBUJA.", 6);
    for (i = 1; i < size; i++)
        for (j = size - 1; j >= i; j--)
            if (array[j - 1] > array[j])
            {
                aux = array[j - 1];
                array[j - 1] = array[j];
                array[j] = aux;
            }
    CenterPrint("Ok, arreglo ordenado.", 8);
    getch();
}

void LinearSort(int array[], int size)
{
    int i, j, aux;

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("ORDENAR ARREGLO - METODO LINEAL.", 6);
    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (array[i] > array[j])
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
    CenterPrint("Ok, arreglo ordenado.", 8);
    getch();
}

void DeleteElement(int array[], int size)
{
    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("ORDENAR ARREGLO - METODO LINEAL.", 6);
}

std::string MenuChoice(int position_y, std::string allow_this)
{
    std::string choice;
    int position_x = center;

    gotoxy(position_x, position_y + 2);
    std::cout << ">> ";
    do
    {
        gotoxy(position_x + 2, position_y + 2);
        std::cout << "                                      ";

        gotoxy(position_x + 3, position_y + 2);
        std::cin.sync();
        std::getline(std::cin, choice);
        CenterPrint("Error. Opcion invalida.", position_y + 4);
    } while (AllowedInput(allow_this, choice));
    CenterPrint("                                          ", position_y + 4);

    return choice;
}

bool CheckValue(std::string input, char type)
{
    // Check if a content is numeric or alphabetic.
    int i;

    for (i = 0; i < input.length(); i++)
        if (type == 'n' && !isdigit(input[i]))
            return false;
        else if (type == 'l' && isdigit(input[i]))
            return false;
    return true;
}

void AskUser(char user_input[], char var_type, int line, int question_len)
{
    // Validate if user's input it's valid
    bool is_valid;

    do
    {
        gotoxy(question_len, line);
        std::cout << "                                       ";

        gotoxy(question_len, line);
        std::cin >> user_input;
        // std::cin.getline(user_input, 30, '\n');
        is_valid = CheckValue(user_input, var_type);
        CenterPrint("Error. valores invalidos.", 11);
    } while (!is_valid);
    CenterPrint("                                       ", 11);
}

bool AllowedInput(std::string allowed, std::string user_input)
{
    int i;
    if (user_input.length() > 1)
        return true;
    for (i = 0; i < allowed.length(); i++)
        if (tolower(user_input[0]) == allowed[i])
            return false;
    return true;
}

void SetWindow(char mode)
{
    // Prepare the window to fit in the user's screeen and get the dimensions from it.
    int ret;

    if (mode == 'f')
    {
        HWND hwnd = GetConsoleWindow();
        if (hwnd != NULL)
            ShowWindow(hwnd, SW_SHOWMAXIMIZED);
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    if (ret)
        width = csbi.dwSize.X;
    // SetConsoleTitle("ARREGLOS");
}

void gotoxy(int x, int y)
{
    // Put the cursor in determinate point of the Window.
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int CenterThis(std::string text)
{
    int text_size = text.length();
    int centered = (width - text_size) / 2;
    return centered;
}

void CenterPrint(std::string text, int position_y)
{
    int position_x = CenterThis(text);
    gotoxy(position_x, position_y);
    std::cout << text;
}

void PrintTitle(std::string title, int height)
{
    center = CenterThis(title) - 2;

    gotoxy(center, height - 1);
    for (int i = 0; i <= title.length() + 3; i++)
        std::cout << char(220);

    gotoxy(center, height);
    std::cout << char(219) << " " << title << " " << char(219);

    gotoxy(center, height + 1);
    for (int i = 0; i <= title.length() + 3; i++)
        std::cout << char(223);
}

void BoxIn(std::string options[], int options_quantity, int height)
{
    int i, longest = LongestWord(options, options_quantity);
    center = ((width - longest) / 2) - 2;

    gotoxy(center, height - 1);
    std::cout << char(218);
    for (i = 0; i <= longest + 1; i++)
        std::cout << char(196);
    std::cout << char(191);

    for (i = 0; i <= options_quantity; i++)
    {
        gotoxy(center, height + i);
        std::cout << char(179) << " ";
        if (i < options_quantity - 1)
            std::cout << options[i];
        else if (i == options_quantity)
            std::cout << options[options_quantity - 1];
        gotoxy(center + longest + 3, height + i);
        std::cout << char(179);
    }

    gotoxy(center, height + options_quantity + 1);
    std::cout << char(192);
    for (i = 0; i <= longest + 1; i++)
        std::cout << char(196);
    std::cout << char(217);
}

int LongestWord(std::string words[], int len)
{
    int max = 0;
    int i;

    for (i = 0; i < len; i++)
        if (words[i].length() > max)
            max = words[i].length();
    return max;
}

void RepeatProgram(int main_function(), int position_y)
{
    int position_x;
    std::string menu_options[] = {"1 - VOLVER AL MENU PRINCIPAL", "2 - SALIR"}, choice;

    system("cls");
    PrintTitle("   ARREGLOS   ", position_y);
    CenterPrint("ESCOJA UNA OPCION.", position_y + 2);
    BoxIn(menu_options, 2, position_y + 5);
    do
    {
        choice = MenuChoice(position_y + 8, "12");
        CenterPrint("                                          ", position_y + 18);
        if (choice == "1")
            main_function();
        system("cls");
        SplashScreen();
        system("color 07");
        exit(0);
    } while (choice != "1" && choice != "2");
}
