/* Second Programming I exam
 * Segundo parcial de Programación I
 * Andrés Felipe Galván
 * XX/10/2020 
 */

#include <iostream>
#include <conio.h>
#include <windows.h>

void SplashScreen();
void Menu();
std::string MenuChoice(int position_y, std::string allow_this);
int ArrayManagement(char process, int size, int array[]);
int BuildArray(int array[]);
void DisplayArray(int array[], int size);
bool CheckValue(std::string input, char type);
void AskUser(char user_input[], char var_type, int line, int question_len);
bool AllowedInput(std::string allowed, std::string user_input);
void SetWindow();
void gotoxy(int x, int y);
int CenterThis(std::string text);
void CenterPrint(std::string text, int position_y);
void PrintTitle(std::string title, int height);
void BoxIn(std::string options[], int options_quantity, int height, bool space);
void BoxInSpace(std::string options[], int options_quantity, int height, int longest);
int LongestWord(std::string words[], int len);
void RepeatProgram(int position_y);

int width, center, ss = 1;

int main()
{
    SetWindow();
    Menu();
    system("cls");
    RepeatProgram(4);
    return 0;
}


void SplashScreen()
{
    Sleep(190);
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t     _                        _           "
"\n\t\t\t\t\t\t\t\t    / \\   _ __ _ __ ___  __ _| | ___  ___ "
"\n\t\t\t\t\t\t\t\t   / _ \\ | '__| '__/ _ \\/ _` | |/ _ \\/ __|"
"\n\t\t\t\t\t\t\t\t  / ___ \\| |  | | |  __/ (_| | | (_) \\__ \\"
"\n\t\t\t\t\t\t\t\t /_/   \\_\\_|  |_|  \\___|\\__, |_|\\___/|___/"
"\n\t\t\t\t\t\t\t\t                        |___/             ");
    Sleep(920);
}


void Menu()
{
    std::string menu_options[] = {"1. ASIGNAR VALORES AL VECTOR", "2. CONSULTAR VALORES DEL VECTOR", "3. ORDENAR VECTOR", "S. SALIR"};
    std::string choice;
    int len = sizeof(menu_options)/sizeof(*menu_options);
    int array[10];
    int h = 9, choice_int, array_len = 0;

    do
    {
        system("color 1F");
        system("cls");
        if (ss)
            SplashScreen();
        system("cls");
        PrintTitle("   ARREGLOS   ", 4);
        CenterPrint("CREAR Y CONSULTAR ARREGLO UNIDIMENSIONAL", 6);
        BoxIn(menu_options, len, h, true);
        do
        {
            choice = MenuChoice(h+len, "123s");
        } while (array_len == 0 && (choice == "2" || choice == "3"));
        ss = 0;

        if (choice != "s")
            array_len = ArrayManagement(choice[0], array_len, array);
    } while (choice != "s");
}


int ArrayManagement(char process, int size, int array[])
{
    switch (process)
    {
    case '1':
        size = BuildArray(array);
        break;
    case '2':
        DisplayArray(array, size);
        break;
    case '3':
        break;
    }
    return size;
}


int BuildArray(int array[10])
{
    char size[10], number[10];
    int len, i;

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("CREAR ARREGLO UNIDIMENSIONAL", 6);

    gotoxy(center*0.9, 8);
    std::cout << "Ingrese el numero de elementos: ";
    AskUser(size, 'n', 8, 32);
    std::cout << "                                ";
    len = atoi(size);

    for (i = 0; i < len; i++)
    {
        gotoxy(center*0.85, 8);
        std::cout << "Ingrese un valor para la posicion " << i <<": ";
        AskUser(number, 'n', 8, 33);
        array[i] = atoi(number);
    }

    return len;
}


void DisplayArray(int array[10], int size)
{
    int i;

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("MOSTRAR ARREGLO UNIDIMENSIONAL", 6);

    gotoxy(15, 8);
    for (i = 0; i < size; i++)
    {
        std::cout << array[i] << "  ";
    }
    getch();
}


std::string MenuChoice(int position_y, std::string allow_this)
{
    std::string choice;
    int position_x = center;

    gotoxy(position_x, position_y+2);
    std::cout << ">> ";
    do
    {
        gotoxy(position_x+2, position_y+2);
        std::cout << "                                      ";

        gotoxy(position_x+3, position_y+2);
        std::getline(std::cin, choice);
        CenterPrint("Error. Opcion invalida.", position_y+4);

    } while (AllowedInput(allow_this, choice));
    // CenterPrint("                                          ", position_y+4);

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
        gotoxy(center*0.9 + question_len, line);
        std::cout << "                                       ";

        gotoxy(center*0.9 + question_len, line);
        std::cin.getline(user_input, 10, '\n');
        is_valid = CheckValue(user_input, var_type);
        CenterPrint("Error. valores invalidos.", 10);
    } while (!is_valid);
    CenterPrint("                                       ", 10);
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


void SetWindow()
{
    // Prepare the window to fit in the user's screeen an get the dimensions from it.
    int ret;
    
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL)
        ShowWindow(hwnd, SW_SHOWMAXIMIZED);

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
    int centered = (width - text_size)/2;
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

    gotoxy(center, height-1);
    for (int i = 0; i <= title.length()+3; i++)
        std::cout << char(220);

    gotoxy(center, height);
    std::cout << char(219) << " " << title << " " << char(219);
    
    gotoxy(center, height+1);
    for (int i = 0; i <= title.length()+3; i++)
        std::cout << char(223);

}


void BoxIn(std::string options[], int options_quantity, int height, bool space)
{
    int i, longest = LongestWord(options, options_quantity);
    center = ((width - longest)/2)-2;

    gotoxy(center, height-1);
    std::cout << char(218);
    for (i = 0; i <= longest+1; i++)
        std::cout << char(196);
    std::cout << char(191);

    if (space)
        BoxInSpace(options, options_quantity, height, longest);
    else
        for (i = 0; i < options_quantity; i++)
        {
            gotoxy(center, height+i);
            std::cout << char(179) << " ";
            std::cout << options[i];
            gotoxy(center+longest+3, height+i);
            std::cout << char(179);
        }
        
    
    gotoxy(center, height+options_quantity+space);
    std::cout << char(192);
    for (i = 0; i <= longest+1; i++)
        std::cout << char(196);
    std::cout << char(217);

}


void BoxInSpace(std::string options[], int options_quantity, int height, int longest)
{
    int i;
    center = ((width - longest)/2)-2;

    for (i = 0; i <= options_quantity; i++)
    {
        gotoxy(center, height+i);
        std::cout << char(179) << " ";
        if (i < options_quantity-1)
            std::cout << options[i];
        else if (i == options_quantity)
            std::cout << options[options_quantity-1];
        gotoxy(center+longest+3, height+i);
        std::cout << char(179);
    }
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


void RepeatProgram(int position_y)
{
    int position_x;
    std::string menu_options[] = {"1. VOLVER AL MENU PRINCIPAL", "2. SALIR"}, choice;

    PrintTitle("   ARREGLOS   ", position_y);
    CenterPrint("ESCOJA UNA OPCION.", position_y+2);
    BoxIn(menu_options, 2, position_y+5, true);
    do
    {
        choice = MenuChoice(position_y+8, "12");
        CenterPrint("                                          ", position_y+18);
        if (choice == "1")
            main();
        else if (choice == "2")
            system("color 07");
            exit(0);
    } while (choice != "1" && choice != "2");
}
