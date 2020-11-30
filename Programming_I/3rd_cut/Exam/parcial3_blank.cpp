/* Parcial del tercer corte de la matería de Programación I.
   Andrés Felipe Galván.
   09/12/2020 
  
   <Question>
   <More info>
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
/* Librerías exclusivas de Windows OS. */
#include <conio.h>
#include <windows.h>

// Menu's actions
void SplashScreen();
void Menu();
void ChoiceManagement(char process);
void RepeatProgram(int position_y);
// User's actions
void FillData();
void UserForm();
char KeepDoing(int line);
void AskData(char user_input[], char data_type, int line);
// Validations
bool IsValidType(char input[], char type);
bool IsAllowedInput(std::string allowed, char user_input[]);
void MenuChoice(char choice[], int position_y, std::string allow_this);
// Files manipulation
void FileAccess();
std::string SplitPath(std::string folder_path, std::string file);
int IsDatabaseEmpty();
int UpdateTable();
// Show one user at time
void DisplayEachUser(int rows);
void UserInfoCard();
void Pagination(int current, int total, int line);
// Table prompt functions
void TableHeaders();
void DisplayStruct(int rows);
void DataTable(int rows, int position_y);
void PromptTableElement(int row, int column, int lines[]);
void LargestInColumn(int list[], int columns, int rows);
int AlingTable(int all_characters[]);
void DelimiterLines(int r, int columns, int lines[]);
void DownLines(int columns, int lines[]);
int NextTablePage(int center_table, int position_y, int lines[]);
// Search user functions
void AskUserId();
int SearchById(char user_id[], char data_found[][100]);
// Controllers
void SetWindow();
void gotoxy(SHORT x, SHORT y);
int CenterThis(std::string text);
void CenterPrint(std::string text, int position_y);
void Capitalize(char text[]);
void PrintTitle(std::string title, int height);
int LongestWord(std::string words[], int len);
void BoxIn(std::string options[], int options_quantity, int height);

// TODO: Paginations index
// Contexto importante de la ventana de la terminal.
int width, center, s_screen = 1, subsection;
int keys = 4;
char data_table[50][4][100];
std::string results_path = "parcial_galvan\\datos.txt";

std::fstream file_hand;
using std::ios;

struct Data
{
    char id_document[20];
    char name[60];
    char phone_number[20];
    char genre[1];
} Employee;

int main()
{
    SetWindow();
    Menu();
    RepeatProgram(4);
    return 0;
}

/* ============================= Menu's actions ================================ */
void SplashScreen()
{
    /* Falsa pantalla de carga del programa para dar suspenso usando
       la función Sleep de la librería windows.h
    */
    Sleep(190);
    printf("\n\n\n\n\n\n\n"
           "\n\t\t\t\t\t\t\t\t   __  ______  ______   ____  ___  __________  _____"
           "\n\t\t\t\t\t\t\t\t  / / / / __ \\/ ____/  / __ \\/   |/_  __/ __ \\/ ___/"
           "\n\t\t\t\t\t\t\t\t / / / / /_/ / /      / / / / /| | / / / / / /\\__ \\ "
           "\n\t\t\t\t\t\t\t\t/ /_/ / ____/ /___   / /_/ / ___ |/ / / /_/ /___/ / "
           "\n\t\t\t\t\t\t\t\t\\____/_/    \\____/  /_____/_/  |_/_/  \\____//____/  ");
    Sleep(920);
}

void Menu()
{
    /* Mostrar un menú centrado, dentro de un cuadro con por razones
       estéticas que tiene como propósito mejorar la experiencia de uso,
       aplicando algebra básica para calcular la posición más centrada
       posible, para los diferentes tamaños de pantalla en las cuales
       se pueda llegar a ejecutar el programa.
    
     * Se usa una lista para las opciones, para poder agregar más opcio-
       nes(si se desea) de manera sencilla. Se valida que el usuario sólo
       pueda introducir las opciones que se le muestran.
    */

    std::string menu_options[] = {"1 - INGRESAR DATOS", "2 - CONSULTAR REGISTROS",
                                  "3 - CONSULTAR TABLA DE DATOS", "4 - BUSCAR UN DATO",
                                  "5 - EDITAR UN REGISTRO", /*"5 - BORRAR TODOS LOS DATOS",*/ " ", "6 - SALIR"};

    char choice[50];
    int len = sizeof(menu_options) / sizeof(*menu_options); // Obtener el tamaño de un arreglo
    int heigth = 10;

    TableHeaders();
    if (s_screen)       // Mostrar la pantalla de carga sólo cuando
        SplashScreen(); // se inicia el programa por primera vez
    s_screen = 0;
    system("cls");

    do
    {
        // system("color F0");
        system("cls");
        PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
        CenterPrint("M E N U", 6);
        CenterPrint("REGISTRAR Y CONSULTAR EMPLEADOS", 7);
        BoxIn(menu_options, len, heigth);
        do
        {
            MenuChoice(choice, heigth + len, "123456");
            CenterPrint("No existen datos guardados.", 19);
        } while (IsDatabaseEmpty() && IsAllowedInput("2345", choice));
        CenterPrint("                              ", 19);

        ChoiceManagement(choice[0]);
    } while (choice[0] != '6');
}

void ChoiceManagement(char process)
{
    int rows = UpdateTable();
    switch (process)
    {
    case '1':
        FillData();
        break;
    case '2':
        DisplayEachUser(rows);
        break;
    case '3':
        DisplayStruct(rows);
        break;
    case '4':
        AskUserId();
        break;
    }
}

/* ============================= User's actions ================================ */
void FillData()
{
    // TODO: Document FillData function
    char register_again;

    UserForm();
    AskData(Employee.id_document, 'n', 8);
    AskData(Employee.name, 'a', 9);
    Capitalize(Employee.name);
    gotoxy(subsection + 12, 9);
    std::cout << Employee.name;
    AskData(Employee.phone_number, 'n', 10);

    CenterPrint("F-> Femenino  y  M-> Masculino", 14);
    do
    {
        AskData(Employee.genre, 'a', 11);
    } while (!IsAllowedInput("fm", Employee.genre));
    CenterPrint("                              ", 14);
    Capitalize(Employee.genre);
    gotoxy(subsection + 12, 11);
    std::cout << Employee.genre;

    FileAccess(); // Verificar que el archivo exista
    file_hand.open(results_path.c_str(), ios::app);
    file_hand.write((char *)&Employee, sizeof(Data));
    file_hand.close();

    register_again = KeepDoing(20);
    if (register_again == 's')
        FillData();
}

void UserForm()
{
    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("REGISTRAR EMPLEADOS", 6);
    subsection = center * 1.1;

    gotoxy(subsection, 8);
    std::cout << "CEDULA    : ";
    gotoxy(subsection, 9);
    std::cout << "NOMBRE    : ";
    gotoxy(subsection, 10);
    std::cout << "TELEFONO  : ";
    gotoxy(subsection, 11);
    std::cout << "SEXO M/F  : ";
}

char KeepDoing(int line)
{
    char user_choice;

    CenterPrint("CONTINUAR? S/N : ", line);
    do
    {
        user_choice = tolower(getche());
    } while (user_choice != 'n' && user_choice != 's');
    return user_choice;
}

void AskData(char user_input[], char data_type, int line)
{
    /* Verificar que lo que el usuario ingresa es del mismo tipo de
       dato que se requiere para poderse procesar posteriormente, y
       seguir preguntándole hasta que un dato válido sea ingresado,
       además de contar con un mensaje de error, si este no cumple
       con la condición.
    */

    bool is_valid;

    do
    {
        gotoxy(subsection + 12, line);
        std::cout << "                                       ";

        gotoxy(subsection + 12, line);
        std::cin.getline(user_input, 50, '\n');
        is_valid = IsValidType(user_input, data_type);
        CenterPrint("Error. valores invalidos.", 15);
    } while (!is_valid || !*user_input);
    CenterPrint("                                       ", 15);
}

/* ============================= Validations ================================ */
bool IsValidType(char input[], char type)
{
    // TODO: IsValidType Documentation
    // Check if a content is numeric or alphabetic.
    int i;

    for (i = 0; i < strlen(input); i++)
        if (type == 'n' && !isdigit(input[i]))
            return false;
        else if (type == 'a' && isdigit(input[i]))
            return false;
    return true;
}

bool IsAllowedInput(std::string allowed, char user_input[])
{
    /* Verificar si un string está en una lista de caracteres */

    int i;
    if (strlen(user_input) > 1)
        return false;
    for (i = 0; i < allowed.length(); i++)
        if (tolower(user_input[0]) == allowed[i])
            return true;
    return false;
}

void MenuChoice(char choice[], int position_y, std::string allow_this)
{
    // TODO: Menu choice Documentation
    int position_x = center;

    gotoxy(position_x, position_y + 2);
    std::cout << ">> ";
    do
    {
        gotoxy(position_x + 2, position_y + 2);
        std::cout << "                                      ";

        gotoxy(position_x + 3, position_y + 2);
        std::cin.sync();
        std::cin.getline(choice, 50, '\n');
        CenterPrint("Error. Opcion invalida.", position_y + 4);
    } while (!IsAllowedInput(allow_this, choice));
    CenterPrint("                                          ", position_y + 4);
}

/* ============================= Files manipulations ================================ */
void FileAccess()
{
    // TODO: Document FileAccess
    std::string file, folder_path;
    std::string mkdir = "mkdir ";

    folder_path = SplitPath(results_path, file);
    mkdir += folder_path;

    file_hand.open(results_path.c_str(), ios::app);
    if (file_hand.fail())
    {
        system(mkdir.c_str());
        file_hand.open(results_path.c_str(), ios::out);
    }
    file_hand.close();
}

std::string SplitPath(std::string folder_path, std::string file)
{
    // TODO: Document SplitPath
    int i;
    int len = folder_path.length() - 1;

    for (i = len; folder_path[i] != '\\'; i--)
        file += folder_path[i];

    file = std::string(file.rbegin(), file.rend());
    folder_path.replace(i, file.length() + 1, "");

    return folder_path;
}

int IsDatabaseEmpty()
{
    // TODO: Document IsDatabaseEmpty

    int lines = -1;

    FileAccess();
    file_hand.open(results_path.c_str(), ios::in);
    while (!file_hand.eof())
    {
        file_hand.read((char *)&Employee, sizeof(Data));
        lines++;
    }
    file_hand.close();
    if (lines <= 0)
        return 1;
    return 0;
}

int UpdateTable()
{
    // TODO: Document CountElements
    file_hand.open(results_path.c_str(), ios ::in);

    int rows = 1;
    while (!file_hand.eof())
    {
        file_hand.read((char *)&Employee, sizeof(Data));

        strcpy(data_table[rows][0], Employee.id_document);
        strcpy(data_table[rows][1], Employee.name);
        strcpy(data_table[rows][2], Employee.phone_number);
        strcpy(data_table[rows][3], Employee.genre);
        rows++;
    }
    file_hand.close();
    return rows - 1;
}

/* ============================= Show one user at time ================================ */
void DisplayEachUser(int rows)
{
    char choice;
    int page = 1;

    file_hand.open(results_path.c_str(), ios::in);
    while (!file_hand.eof())
    {
        system("cls");

        file_hand.read((char *)&Employee, sizeof(Data));
        if (file_hand.eof())
            break;
        PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
        CenterPrint("TABLA DE USUARIOS REGISTRADOS", 6);
        Pagination(page, rows - 1, 17);
        UserInfoCard();
        choice = KeepDoing(20);
        if (choice == 'n')
            break;
        page++;
    }
    file_hand.close();
}

void UserInfoCard()
{
    std::string data_context[7];

    data_context[0] = "CEDULA   : " + std::string(Employee.id_document);
    data_context[1] = " ";
    data_context[2] = "NOMBRE   : " + std::string(Employee.name);
    data_context[3] = " ";
    data_context[4] = "TELEFONO : " + std::string(Employee.phone_number);
    data_context[5] = " ";
    data_context[6] = "SEXO M/F : " + std::string(Employee.genre);

    BoxIn(data_context, 7, 9);
}

void Pagination(int current, int total, int line)
{
    char buffer_1[20], buffer_2[20];
    char *temp_1 = itoa(current, buffer_1, 10);
    char *temp_2 = itoa(total, buffer_2, 10);
    std::string current_str = std::string(temp_1);
    std::string total_str = std::string(temp_2);

    CenterPrint(current_str + " / " + total_str, line);
}

/* ============================= Table prompt functions ================================ */
void TableHeaders()
{
    // TODO: Document TableHeaders
    strcpy(data_table[0][0], "CEDULA");
    strcpy(data_table[0][1], "NOMBRE");
    strcpy(data_table[0][2], "TELEFONO");
    strcpy(data_table[0][3], "SEXO M/F");
}

void DisplayStruct(int rows)
{
    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("TABLA DE USUARIOS REGISTRADOS", 6);
    DataTable(rows, 8);
    CenterPrint("Presione cualquier tecla para volver... ", 25);
    getch();
}

void DataTable(int rows, int position_y)
{
    // TODO: Document DataTable
    int r, c;
    int current_line, lines[50];
    int center_table, page = 1, total_pages = ((rows - 2) / 6) + 1;
    char choice;

    LargestInColumn(lines, keys, rows);
    center_table = AlingTable(lines);

    for (r = 0, current_line = 0; r < rows; r++, current_line += 2)
    {
        gotoxy(center_table, position_y + current_line);
        DelimiterLines(r, keys, lines);

        gotoxy(center_table, position_y + 1 + current_line);
        std::cout << char(179);
        for (c = 0; c < keys; c++)
            PromptTableElement(r, c, lines);

        gotoxy(center_table, position_y + 2 + current_line);
        DownLines(keys, lines);
        Pagination(page, total_pages, 23);
        if (position_y + current_line >= 20)
        {
            choice = KeepDoing(25);
            if (choice == 'n')
                break;
            current_line = NextTablePage(center_table, position_y, lines);
            page++;
        }
    }
}

void PromptTableElement(int row, int column, int lines[])
{
    int i, blanks;

    std::cout << data_table[row][column];
    blanks = lines[column] - strlen(data_table[row][column]);
    for (i = 0; i < blanks; i++)
        std::cout << " ";
    std::cout << char(179);
}

void LargestInColumn(int list[], int columns, int rows)
{
    // TODO: Document LargestInColumn
    int i, j;
    int max;

    std::cout << "\n\n";
    for (i = 0; i < columns; i++)
    {
        max = 0;
        for (j = 0; j < rows; j++)
            if (strlen(data_table[j][i]) > max)
                max = strlen(data_table[j][i]);
        list[i] = max;
    }
}

int AlingTable(int all_characters[])
{
    // TODO: Document AlingTable
    int table_width, i, total_chars = 0;

    for (i = 0; i < keys; i++)
        total_chars += all_characters[i];

    table_width = total_chars + keys + 1;
    return (width - table_width) / 2;
}

void DelimiterLines(int r, int columns, int lines[])
{
    // TODO: Document DelimiterLines
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
    // TODO: Document Downlines
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

int NextTablePage(int center_table, int position_y, int lines[])
{
    int c;

    system("cls");
    PrintTitle("   WUNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("TABLA DE USUARIOS REGISTRADOS", 6);
    gotoxy(center_table, position_y);
    DelimiterLines(0, keys, lines);
    gotoxy(center_table, position_y + 1);
    std::cout << char(179);
    for (c = 0; c < keys; c++)
        PromptTableElement(0, c, lines);
    return 0;
}

/* ============================= Search user functions ================================ */
void AskUserId()
{
    char search_id[20], user_info[4][100];

    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("BUSCAR UN USUARIO", 7);

    subsection = center * 1.13;

    gotoxy(subsection, 9);
    std::cout << "CEDULA   : ";
    AskData(search_id, 'n', 9);
    if (SearchById(search_id, user_info))
    {
        PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
        CenterPrint("USUARIO ENCONTRADO", 7);
    }
    else
        CenterPrint("Usuario no encontrado", 12);
    CenterPrint("Presione cualquier tecla para volver... ", 18);
    getch();
}

int SearchById(char user_id[], char data_found[][100])
{
    file_hand.open(results_path.c_str(), ios::in);
    while (!file_hand.eof())
    {
        file_hand.read((char *)&Employee, sizeof(Data));
        if (strcmp(user_id, Employee.id_document) == 0)
        {
            system("cls");
            UserInfoCard();
            file_hand.close();
            return 1;
        }
    }
    file_hand.close();
    return 0;
}

/* ============================= Controllers ================================ */
void SetWindow()
{
    /* Peparar la terminal para que ocupe todo la pantalla del usuario.
       Además recibir su ancho de la función GetConsoleScreenBufferInfo.
    
     * Para el uso de esta función es necesario importar la librería
       "windows.h".
    */

    int ret;

    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL)
        ShowWindow(hwnd, SW_SHOWMAXIMIZED);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ret = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    if (ret)
        width = csbi.dwSize.X;
    // SetConsoleTitle("TITULO DE EJEMPLO");
}

void gotoxy(SHORT x, SHORT y)
{
    /* Clásica función para mejorar la presentación de programas bá-
       sicos que permite ubicar el cursor en cualquier posición deseada,
       como si de un plano cartesiano se tratara. Teniendo en cuenta que
       las pantallas son matrices, y la terminal también es una.
    
     * Para el uso de esta función es necesario importar la librería
       "windows.h".
    */

    // Crear una nueva variable de la struct COORD para asignarle los valores de x & y.
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int CenterThis(std::string text)
{
    /* Dado una oración/palabra de tipo string devolver la posición más
       centrada posible para ser usado al momento de imprimir texto por
       pantalla. Con el ancho de pantalla dada por la función SetWindow()
       y la cantidad de caracteres de la oración, simplemente se aplica
       matemática básica para retornar ese valor.
    */

    int text_size = text.length();
    int centered = (width - text_size) / 2;
    return centered;
}

void CenterPrint(std::string text, int position_y)
{
    /* Imprimir un texto en el centro de la pantalla, dada la altura.
       Para evitar que se tenga que repetir el proceso de imprimir en
       el centro algún texto o línea.
    */

    int position_x = CenterThis(text);
    gotoxy(position_x, position_y);
    std::cout << text;
}

void Capitalize(char text[])
{
    int i;
    std::string to_capitalize = std::string(text);

    to_capitalize[0] = toupper(to_capitalize[0]);
    for (i = 1; i < strlen(text); i++)
    {
        to_capitalize[i] = tolower(to_capitalize[i]);
        if (to_capitalize[i - 1] == ' ')
            to_capitalize[i] = toupper(to_capitalize[i]);
    }
    strcpy(text, to_capitalize.c_str());
}

void PrintTitle(std::string title, int height)
{
    /* Imprimir un texto no sólo en el centro, sino que se reselta
       encapsulándolo en un cuadro para resaltarlo y que sea atractivo
       para la vista del usuario.

     * Para lograrlo, teniendo en cuenta la altura en la que se desea
       mostrar el titulo se recorre tanto por la parte superior como
       la inferior la pantalla y se va imprimiendo el simbolo.
    
     * Para los simbolos que encapsulan nuestro texto, se usa su códi-
       único de ASCII y se hace "Type casting" de tipo int a tipo char
       para que muestre el simbolo.
    */

    // Restar 1 espacio para que quede en el centro horizontalmente el titulo.
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

int LongestWord(std::string words[], int len)
{
    /* Calcular la palabra con más caracteres en un lista dada,
    usando el clasico método de inicializar el número max en 0 y 
    recorer la lista e ir remplazando la variable hasta encontrar
    la palbra más "larga".
    */

    int max = 0;
    int i;

    for (i = 0; i < len; i++)
        if (words[i].length() > max)
            max = words[i].length();
    return max;
}

void BoxIn(std::string options[], int options_quantity, int height)
{
    /* Dada una lista de opciones, mostrarlas adentro de un cuadrado,
       principalmente para dar la ilusión de un menú.

     * Para lograrlo, primero se debe saber cuál es la palabra con más
       caracteres en la lista, para poder establecer que tan ancho
       será el cuadro que encapsulará nuestras opciones. Todo eso se
       logra con la función previamente declarada LongestWord().
       Despues se va imprimiendo elemento por elemento el arreglo con
       las opciones, a la vez que se imprimen las líneas laterales.
    */

    int i, longest = LongestWord(options, options_quantity);
    center = (width - (longest + 4)) / 2;

    gotoxy(center, height - 1);
    std::cout << char(218);
    for (i = 0; i <= longest + 1; i++)
        std::cout << char(196);
    std::cout << char(191);

    for (i = 0; i < options_quantity; i++)
    {
        gotoxy(center, height + i);
        std::cout << char(179) << " ";

        std::cout << options[i];

        gotoxy(center + longest + 3, height + i);
        std::cout << char(179);
    }

    gotoxy(center, height + options_quantity);
    std::cout << char(192);
    for (i = 0; i <= longest + 1; i++)
        std::cout << char(196);
    std::cout << char(217);
}

void RepeatProgram(int position_y)
{
    /* Haciendo uso de la función BoxIn se crea otro menú para que el
       usuario decida si quiere continuar con la ejecución del programa
       o por el contrario salir de él.
    
     * Se valida que el usuario sólo pueda ingresar alguna de las opcio-
       nes dispuestas en este pequeño menú.
    */

    int position_x;
    std::string menu_options[] = {"1 - VOLVER AL MENU PRINCIPAL", " ", "2 - SALIR"};
    char choice[50];

    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", position_y);
    CenterPrint("ESCOJA UNA OPCION.", position_y + 2);
    BoxIn(menu_options, 3, position_y + 5);
    do
    {
        MenuChoice(choice, position_y + 8, "12");
        CenterPrint("                                          ", position_y + 18);
        if (choice[0] == '1')
            main();
        system("cls");
        SplashScreen();
        system("color 07");
        exit(0);
    } while (choice != "1" && choice != "2");
}
