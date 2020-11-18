/* First Programming I test
 * Primer parcial de Programación I
 * Andrés Felipe Galván
 * 08/10/2020 
 * 
 * Realizar un programa en código  C/C++, que permita recibir desde el
 * teclado : El Nombre,  La Edad, El sexo (F-> Femenino  y  M-> Masculino) 
 * y  el Estado Civil (S-> Soltero, C-> Casado, U-> Unión Libre) de
 * cualquier  persona,  e imprimir por pantalla el mensaje  SI CUMPLE
 * o  NO CUMPLE con los siguientes criterios: Hombre que sean casado mayor
 * de 40 años o  mujeres solteras menores de 50 años. Asimismo, se debe calcular
 * e imprimir el número de personas que cumplen con la condición establecida.
*/

#include <iostream> // C++ standard library
#include <string.h> // C library for better string management
//Microsoft libraries
#include <conio.h>
#include <windows.h> // Library for window manipulation

#define WHITE "\e[1;97m"
#define RED "\e[1;91m"
#define BACKGROUND "\e[0;34;107m"

void Menu();
void AskUser(char user_input[], char var_type, int line);
void AskChar(char user_input[], std::string allowed, int line);
void FilterUsers(char genre[], char civil_state[], int age);
void ShowResults();
void SetWindow();
void PaintWindow();
void gotoxy(int x, int y);
int CenterThis(std::string content);
void CenterPrintf(std::string text, int y);
bool CheckValue(std::string input, char type);
void ErrorMsg(std::string error_text, int y);
void KeepAsking(int line);
void RepeatProgram(int main_function(), int static_height);

// Window dimension and text position.
int width, center_position, subsection;
// Users who accomplish the conditions.
int M_accomplish = 0, F_accomplish = 0, people = 0;

int main()
{
    SetWindow();
    Menu();
    KeepAsking(18);
    ShowResults();
    RepeatProgram(main, 18);
    return 0;
}

void Menu()
{
    // Prompt the main menu to the user
    char name[35], age[35], genre[35], civil_state[35];

    PaintWindow();
    CenterPrintf("PARCIAL", 2);
    subsection = center_position * 0.9;

    gotoxy(subsection, 4);
    std::cout << "NOMBRE    : ";
    gotoxy(subsection, 5);
    std::cout << "EDAD      : ";
    gotoxy(subsection, 6);
    std::cout << "SEXO M/F  : ";
    gotoxy(subsection, 7);
    std::cout << "EST. CIVIL: ";

    AskUser(name, 'l', 4);
    AskUser(age, 'n', 5);
    CenterPrintf("F-> Femenino  y  M-> Masculino", 11);
    AskChar(genre, "fm", 6);
    CenterPrintf("                              ", 11);
    CenterPrintf(" S-> Soltero, C-> Casado, U-> Union Libre", 11);
    AskChar(civil_state, "scu", 7);
    CenterPrintf("                                         ", 11);
    people++;

    FilterUsers(genre, civil_state, atoi(age));
}

void FilterUsers(char genre[], char civil_state[], int age)
{
    if (genre[0] == 'm' && civil_state[0] == 'c' && age > 40)
        M_accomplish++;
    if (genre[0] == 'f' && civil_state[0] == 's' && age < 50)
        F_accomplish++;
}

void ShowResults()
{
    int digits = M_accomplish + F_accomplish, center;
    center = CenterThis("");
    while (digits != 0)
    {
        digits /= 10;
        center--;
    }

    PaintWindow();
    CenterPrintf("RESULTADOS", 4);
    CenterPrintf("Total de personas: ", 6);
    std::cout << people;
    CenterPrintf("Hombres casados  mayores de 40: ", 8);
    std::cout << M_accomplish;
    CenterPrintf("Mujeres solteras menores de 50: ", 10);
    std::cout << F_accomplish;
    CenterPrintf("TOTAL:", 12);
    gotoxy(center, 13);
    std::cout << M_accomplish + F_accomplish;
}

void AskUser(char user_input[], char var_type, int line)
{
    // Validate if user's input it's valid
    bool is_valid;

    do
    {
        gotoxy(subsection + 12, line);
        std::cout << "                                       ";

        gotoxy(subsection + 12, line);
        std::cin.getline(user_input, 35, '\n');
        is_valid = CheckValue(user_input, var_type);
        ErrorMsg("Error. valores invalidos.", 10);
    } while (!is_valid);
    CenterPrintf("                                       ", 10);
}

void AskChar(char user_input[], std::string allowed, int line)
{
    int i, input_len;
    bool invalid = true;

    do
    {
        AskUser(user_input, 'l', line);
        input_len = strlen(user_input);
        if (input_len > 1)
            continue;
        for (i = 0; i < allowed.length(); i++)
            if (tolower(user_input[0]) == allowed[i])
                invalid = false;
    } while (invalid);
}

void SetWindow()
{
    // Prepare the window to fit in the user's screeen an get information from it.
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL)
        ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    int ret;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    if (ret)
        width = csbi.dwSize.X;
}

void PaintWindow()
{
    /* Paint window; white background and blue fore color,
    using a combination of cmd color code and ANSI escape code*/
    std::cout << BACKGROUND;
    system("color F1");
    system("cls");
}

void gotoxy(int x, int y)
{
    // Put the cursor in determinate point of the Window.
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int CenterThis(std::string content)
{
    // Use information given from SetWindow function to center text.
    int title_width = content.length();
    center_position = (width - title_width) / 2;
    return center_position;
}

void CenterPrintf(std::string text, int y)
{
    //Automate the process of printing center text.
    int x_position = CenterThis(text);
    gotoxy(x_position, y);
    std::cout << text;
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

void ErrorMsg(std::string error_text, int y)
{
    // Print a red error message to alert the user.
    std::cout << RED;
    CenterPrintf(error_text, y);
    std::cout << WHITE;
    std::cout << BACKGROUND;
}

void KeepAsking(int line)
{
    char choice;
    int x;

    x = (width - 22) / 2;
    gotoxy(x, 18);
    std::cout << char(168) << "Desea continuar? S/N";
    do
    {
        gotoxy(x, 19); std::cout << "> ";
        choice = getche();
        choice = tolower(choice);
    } while (choice != 's' && choice != 'n');
    if (choice == 's')
        main();
}

void RepeatProgram(int main_function(), int static_height)
{
    /* Display a menu to ask if the user wants to continue using the program.
    Repeat it calling the main function.*/
    M_accomplish = 0, F_accomplish = 0, people = 0;
    std::string choice;
    char separator[] = {"-----------------------------"};
    int x, y = static_height;

    x = (width - strlen(separator)) / 2;

    // PaintWindow();
    gotoxy(x - 1, y);
    std::cout << separator;
    y++;
    gotoxy(x, y);
    std::cout << char(168) << "Desea repetir el programa?";
    y++;
    gotoxy(x, y);
    std::cout << "[1] Si.";
    y++;
    gotoxy(x, y);
    std::cout << "[2] No.";
    y += 2;
    do
    {
        gotoxy(x + 1, y);
        // std::cout << "                                  ";
        gotoxy(x, y);
        std::cout << "> ";
        choice = getche();
    } while (choice != "2" && choice != "1");

    if (choice == "1")
        main_function();
}
