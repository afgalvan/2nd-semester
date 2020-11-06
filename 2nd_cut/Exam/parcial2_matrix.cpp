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
void ArrayManagement(char process, int array[][30], int size[]);
void BuildArray(int array[][30], int size[]);
int DigitsOf(int number);
int AlingArray(int array[][30], int size);
void LargestInColumn(int list[], int array[][30], int rows, int columns);
void DelimiterLines(int r, int columns, int lines[]);
void DownLines(int columns, int lines[]);
void ArrayTable(int array[][30], int rows, int columns);
void DisplayArray(int array[][30], int rows, int columns);
void SumArray(int array[][30], int rows, int columns);
void BubbleSort(int array[][30], int size);
bool CheckValue(std::string input, char type);
void AskUser(char user_input[], char var_type, int line, int question_len);
bool AllowedInput(std::string allowed, std::string user_input);
void SetWindow();
void gotoxy(int x, int y);
int CenterThis(std::string text);
void CenterPrint(std::string text, int position_y);
void PrintTitle(std::string title, int height);
void BoxIn(std::string options[], int options_quantity, int height);
int LongestWord(std::string words[], int len);
void RepeatProgram(int position_y);

int width, center, s_screen = 1;

int main()
{
    SetWindow();
    Menu();
    RepeatProgram(4);
    return 0;
}

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

void Menu()
{
    // Prompt the main menu to the user.
    std::string menu_options[] = {"1 - ASIGNAR VALORES A LA MATRIZ", "2 - CONSULTAR VALORES DE LA MATRIZ", "3 - SUMAR MATRIZ", "5 - SALIR"};
    std::string choice;
    int len = sizeof(menu_options) / sizeof(*menu_options);
    int array[30][30], size[] = {0, 0};
    int h = 9, choice_int;

    do
    {
        system("color 3F");
        system("cls");
        if (s_screen)
            SplashScreen();
        system("cls");
        PrintTitle("   ARREGLOS   ", 4);
        CenterPrint("CREAR Y CONSULTAR ARREGLO BIDIMENSIONAL.", 6);
        BoxIn(menu_options, len, h);
        do
        {
            choice = MenuChoice(h + len, "1235");
            CenterPrint("La matriz aun no existe", 18);
        } while ((size[0] == 0 || size[1] == 0) && (choice == "2" || choice == "3"));
        CenterPrint("                          ", 18);

        s_screen = 0; // Don't show the splash screen anymore

        if (choice != "5")
            ArrayManagement(choice[0], array, size);
    } while (choice != "5");
}

void ArrayManagement(char process, int array[][30], int size[])
{
    switch (process)
    {
    case '1':
        BuildArray(array, size);
        break;
    case '2':
        DisplayArray(array, size[0], size[1]);
        break;
    case '3':
        SumArray(array, size[0], size[1]);
        break;
    }
}

void BuildArray(int array[][30], int size[])
{
    char rows[30], columns[30], number[30];
    int r, c;

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("CREAR ARREGLO BIDIMENSIONAL.", 6);

    gotoxy(center * 0.9, 8);
    std::cout << "Ingrese el numero de filas    : ";
    gotoxy(center * 0.9, 9);
    std::cout << "Ingrese el numero de columnas : ";

    AskUser(rows, 'n', 8, 32);
    std::cout << "                                  ";
    AskUser(columns, 'n', 9, 32);
    std::cout << "                                  ";
    gotoxy(center * 0.9, 9);
    std::cout << "                                           ";

    size[0] = atoi(rows);
    size[1] = atoi(columns);

    for (r = 0; r < size[0]; r++)
    {
        for (c = 0; c < size[1]; c++)
        {
            gotoxy(center * 0.85, 8);
            std::cout << "Ingrese un valor para la posicion [" << r << "][" << c << "]: ";
            AskUser(number, 'n', 8, 38);
            array[r][c] = atoi(number);
        }
    }
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

int AlingArray(int array[][30], int size)
{
    int i, all_digits = 0, table_width;

    for (i = 0; i < size; i++)
        all_digits += DigitsOf(array[0][i]);
    table_width = all_digits + size + 1;

    return (width - table_width) / 2;
}

void LargestInColumn(int list[], int array[][30], int rows, int columns)
{
    int i, j;
    int max;

    for (i = 0; i < columns; i++)
    {
        max = 0;
        for (j = 0; j < rows; j++)
            if (DigitsOf(array[j][i]) > max)
                max = DigitsOf(array[j][i]);
        list[i] = max;
    }
}

void DelimiterLines(int r, int columns, int lines[])
{
    int c;
    int l;

    if (r == 0)
        std::cout << char(218);
    else
        std::cout << char(195);
    for (c = 0; c < columns; c++)
    {
        for (l = 0; l < lines[c]; l++)
            std::cout << char(196);
        if (c + 1 < columns)
            if (r == 0)
                std::cout << char(194);
            else
                std::cout << char(197);
    }

    if (r == 0)
        std::cout << char(191);
    else
        std::cout << char(180);
}

void DownLines(int columns, int lines[])
{
    int c, l;

    std::cout << char(192);
    for (c = 0; c < columns; c++)
    {
        for (l = 0; l < lines[c]; l++)
            std::cout << char(196);
        if (c + 1 < columns)
            std::cout << char(193);
        else
            std::cout << char(217);
    }
}

void ArrayTable(int array[][30], int rows, int columns)
{
    int r, c;
    int a, l, lines[columns];
    int i, blanks;
    int center_table = AlingArray(array, columns);

    LargestInColumn(lines, array, rows, columns);

    for (r = 0, a = 0; r < rows; r++, a += 2)
    {
        gotoxy(center_table, 8 + a);
        DelimiterLines(r, columns, lines);

        gotoxy(center_table, 9 + a);
        std::cout << char(179);
        for (c = 0; c < columns; c++)
        {
            std::cout << array[r][c];
            blanks = lines[c] - DigitsOf(array[r][c]);
            for (i = 0; i < blanks; i++)
                std::cout << " ";
            std::cout << char(179);
        }

        gotoxy(center_table, 10 + a);
        DownLines(columns, lines);
    }
}

void DisplayArray(int array[][30], int rows, int columns)
{
    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("MOSTRAR ARREGLO BIDIMENSIONAL.", 6);
    ArrayTable(array, rows, columns);
    CenterPrint("Presione cualquier tecla para continuar... ", 22);
    getch();
}

void SumArray(int array[][30], int rows, int columns)
{
    // TODO: Print the result in center
    int r, c, acum, addition[1][30];

    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("SUMAR TERMINOS DEL VECTOR", 6);

    for (c = 0; c < columns; c++)
    {
        acum = 0;
        for (r = 0; r < rows; r++)
            acum += array[r][c];
        addition[0][c] = acum;
    }

    ArrayTable(addition, 1, columns);
    CenterPrint("Presione cualquier tecla para continuar... ", 22);
    getch();
}

void BubbleSort(int array[][30], int size)
{
    // TODO: Use BubbleSort to order the array and add the positiblity of use radix sort
    system("cls");
    PrintTitle("   ARREGLOS   ", 4);
    CenterPrint("ORDENAR ARREGLO.", 6);
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
        gotoxy(center * 0.9 + question_len, line);
        std::cout << "                                       ";

        gotoxy(center * 0.9 + question_len, line);
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

void RepeatProgram(int position_y)
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
            main();
        system("cls");
        SplashScreen();
        system("color 07");
        exit(0);
    } while (choice != "1" && choice != "2");
}
