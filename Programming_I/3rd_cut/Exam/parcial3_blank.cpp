/* Parcial del tercer corte de la matería de Programación I.
   Andrés Felipe Galván.
   09/12/2020 
  
   <Question>
   <More info>
*/

#include <iostream>
#include <fstream>
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
void UserFinder();
void AskUserId(char user_id[]);
int SearchById(char user_id[]);
// Filter table result by a value
void TableFilter();
// Remove user functions
void DeleteUser();
// Controllers
void SetWindow();
void gotoxy(SHORT x, SHORT y);
int CenterThis(std::string text);
void CenterPrint(std::string text, int position_y);
void Capitalize(char text[]);
void PrintTitle(std::string title, int height);
int LongestWord(std::string words[], int len);
void BoxIn(std::string options[], int options_quantity, int height);
int PageMove(int index);

// TODO: $Delete register function
// TODO: $Filter Table by genre function
// Información importante de la ventana de la terminal.
int width, center, s_screen = 1, subsection;
// Información de la tabla
int keys = 4;                // FIXME 4 -> Desired value
char data_table[50][4][100]; //
// Dirección de nuestro archivo
std::string results_path = "D:\\DATOSBAS\\parcial_galvan\\datos.txt";

std::fstream file_hand;
using std::ios;

struct Data
{
    // FIXME Elements name and quantity
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
    CenterPrint("   __  ______  ______   ____  ___  __________  _____", 8);
    CenterPrint("  / / / / __ \\/ ____/  / __ \\/   |/_  __/ __ \\/ ___/", 9);
    CenterPrint(" / / / / /_/ / /      / / / / /| | / / / / / /\\__ \\ ", 10);
    CenterPrint("/ /_/ / ____/ /___   / /_/ / ___ |/ / / /_/ /___/ / ", 11);
    CenterPrint("\\____/_/    \\____/  /_____/_/  |_/_/  \\____//____/  ", 12);
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
                                  "5 - ELIMINAR UN REGISTRO", " ", "6 - SALIR"};

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
            CenterPrint("No existen datos guardados.", heigth + len + 5);
        } while (IsDatabaseEmpty() && IsAllowedInput("2345", choice));
        CenterPrint("                              ", heigth + len + 5);

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
        UserFinder();
        break;
    case '5':
        DeleteUser();
        break;
    }
}

/* ============================= User's actions ================================ */
void FillData()
{
    /* Preguntarle al usuario los datos requeridos para llenar el
     * registro, y hacer las respectivas validaciones para evitar
     * errores de lectura al mostrar la tabla
    */

    char register_again;

    UserForm();
    AskData(Employee.id_document, 'n', 8);
    AskData(Employee.name, 'a', 10);
    Capitalize(Employee.name);
    gotoxy(subsection + 12, 10);
    std::cout << Employee.name;
    /*FIXME Change users questions quantity*/
    /*==/==/==/==/==*/
    AskData(Employee.phone_number, 'n', 12);

    CenterPrint("F-> Femenino  y  M-> Masculino", 17);
    do
    {
        AskData(Employee.genre, 'a', 14);
    } while (!IsAllowedInput("fm", Employee.genre));
    CenterPrint("                              ", 17);
    Capitalize(Employee.genre);
    gotoxy(subsection + 12, 14);
    std::cout << Employee.genre;
    /*==/==/==/==/==*/

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
    // TODO Document UserForm
    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("REGISTRAR EMPLEADOS", 6);
    subsection = center * 1.1;

    gotoxy(subsection, 8);
    std::cout << "CEDULA    : ";
    gotoxy(subsection, 10);
    std::cout << "NOMBRE    : ";
    gotoxy(subsection, 12);
    /*FIXME Question context quantity*/
    /*==/==/==/==/==*/
    std::cout << "TELEFONO  : ";
    gotoxy(subsection, 14);
    std::cout << "SEXO M/F  : ";
    /*==/==/==/==/==*/
}

char KeepDoing(int line)
{
    // TODO Document KeepDoing
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
        CenterPrint("Error. valores invalidos.", 18);
    } while (!is_valid || !*user_input);
    CenterPrint("                                       ", 18);
}

/* ============================= Validations ================================ */
bool IsValidType(char input[], char type)
{
    /* Verificar que una cadena es compatible para hacer parsing
     * a otro tipo de dato, en este caso, numerico, también validar
     * que las entradas alfabéticas no contengan valores númericos.
    */

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
    /* Pequeño manejador de entradas para controlar el flujo usal de
     * opciones que un usuario realiza, acompañado de un indicador de entrada.
    */

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
    /* Antes de abrir y leer archivos, es necesario que se verifique
     * el estado de el mismo. Esta función checa que un archivo x exista
     * en determinada dirección, si no existe crea las carpetas necesarias
     * (si es que se ingresa una carpeta) y finalmente el archivo.
    */

    std::string file, folder_path;
    std::string mkdir = "mkdir "; // Comando mkdir para crear directorios desde la terminal

    folder_path = SplitPath(results_path, file); // Dividimos las carpetas del fichero de texto
    mkdir += folder_path;                        // Se agrega la cantidad de carpetas a crear

    file_hand.open(results_path.c_str(), ios::app); // Tratar de abrir el archivo
    // Si no existe lo crea
    if (file_hand.fail())
    {
        // Ejecutar comando mkdir para crear las carpetas
        system(mkdir.c_str());

        // Crear el fichero de texto en la dirección indicada
        file_hand.open(results_path.c_str(), ios::out);
    }
    file_hand.close();
}

std::string SplitPath(std::string folder_path, std::string file)
{
    // Dividir una dirección de manera que separemos las carpetas del fichero de texto
    int i;
    int len = folder_path.length() - 1; // El tamaño del string - 1 es la última posición

    /* Recorrera string de manera inversa hasta
     * que encontremos un "\" */
    for (i = len; folder_path[i] != '\\'; i--)
        file += folder_path[i]; // Agregar los caracteres que componen el nombre del fichero.

    file = std::string(file.rbegin(), file.rend()); // Invertirlo, ya que al acumularlo,
                                                    // lo recibimos de manera inversa.

    folder_path.replace(i, file.length() + 1, ""); // Remover el fichero de texto de la dirección
                                                   // para crear esas carpetas.
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
    // TODO: Document UpdateTable
    file_hand.open(results_path.c_str(), ios ::in);

    int rows = 1;
    while (!file_hand.eof())
    {
        file_hand.read((char *)&Employee, sizeof(Data));

        strcpy(data_table[rows][0], Employee.id_document);
        strcpy(data_table[rows][1], Employee.name);
        /*FIXME Table filling quantity */
        /*==/==/==/==/==*/
        strcpy(data_table[rows][2], Employee.phone_number);
        strcpy(data_table[rows][3], Employee.genre);
        /*==/==/==/==/==*/
        rows++;
    }
    file_hand.close();
    return rows - 1;
}

/* ============================= Show one user at time ================================ */
void DisplayEachUser(int rows)
{
    // TODO Document DisplayEachUser
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
        CenterPrint("USUARIOS REGISTRADOS", 6);
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
    // TODO *Document UserInfoCard
    std::string data_context[7];
    int len;

    data_context[0] = "CEDULA   : " + std::string(Employee.id_document);
    data_context[1] = " ";
    data_context[2] = "NOMBRE   : " + std::string(Employee.name);
    /*FIXME Comment for the quantities*/
    /*==/==/==/==/==*/
    data_context[3] = " ";
    data_context[4] = "TELEFONO : " + std::string(Employee.phone_number);
    data_context[5] = " ";
    data_context[6] = "SEXO M/F : " + std::string(Employee.genre);
    /*==/==/==/==/==*/
    len = sizeof(data_context) / sizeof(*data_context);

    BoxIn(data_context, len, 9); // <- 7 to desired value + 3
}

void Pagination(int current, int total, int line)
{
    // TODO Document Pagination
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
    /* Llenar primera fila de cada columna con las cabeceras
     * que indican que dato se está mostrando con relación a
     * lo que se preguntó primeramente.
    */
    strcpy(data_table[0][0], "CEDULA");
    strcpy(data_table[0][1], "NOMBRE");
    strcpy(data_table[0][2], "TELEFONO");
    strcpy(data_table[0][3], "SEXO M/F");
}

void DisplayStruct(int rows)
{
    // TODO: Document DisplayStruct
    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("TABLA DE USUARIOS REGISTRADOS", 6);
    DataTable(rows, 8);
    CenterPrint("                            ", 26);
    CenterPrint("Presione cualquier tecla para volver... ", 25);
    getch();
}

void DataTable(int rows, int position_y)
{
    // TODO: *Document DataTable
    int r, c;
    int current_line, lines[50];
    int center_table, page = 1, total_pages = ((rows - 2) / 6) + 1;
    int rows_showing, move;

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
        rows_showing++;

        if (position_y + current_line > 19 && r + 1 != rows)
        {
            rows_showing = 0;
            move = PageMove(page);
            if (move == 1)
            {
                current_line = NextTablePage(center_table, position_y, lines);
                page++;
            }
            else if (move == -1)
            {
                page--;
                r -= 12;
                current_line -= 12;
            }
            else if (move == 0)
            {
                page = 1;
                r = 0;
                current_line = 0;
            }
        }
        if (r + 1 == rows && total_pages >= 2)
        {
            move = PageMove(page);
            if (move == -1)
            {
                page--;
                r -= 6 + rows_showing;
                current_line -= (2 * rows_showing);
            }
        }
    }
}

void PromptTableElement(int row, int column, int lines[])
{
    // Mostrar el contenido de cada celda
    int i, blanks;

    std::cout << data_table[row][column];
    blanks = lines[column] - strlen(data_table[row][column]);
    for (i = 0; i < blanks; i++)
        std::cout << " ";
    std::cout << char(179);
}

void LargestInColumn(int list[], int columns, int rows)
{
    /* Revisar cada columna y encontrar la palabra más larga
     * para así llenar una lista con el ancho que deberá tener
     * cada columna de la tabla y tener una tabla uniforme.
    */

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
    /* Tomando la palabra más larga en la columna, esta función
     * devuelve la posición  en el eje x más centrada posible
     * para mostrar la tabla.
    */

    int table_width, i, total_chars = 0;

    for (i = 0; i < keys; i++)
        total_chars += all_characters[i];

    table_width = total_chars + keys + 1;
    return (width - table_width) / 2;
}

void DelimiterLines(int r, int columns, int lines[])
{
    /* Teniendo en cuenta el tamaño de la palabra de mayor carácter
     * esta función imprime las líneas que separarán a cada palabra.
    */

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
    // Esta función muestra en pantalla las líneas inferiores de la tabla

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
    // TODO Document NextTablePage
    int c;

    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
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
void UserFinder()
{
    // TODO Document UserFinder

    char search_again, search_id[20];
    std::string subtitle = "USUARIO ENCONTRADO";

    AskUserId(search_id);
    if (SearchById(search_id))
    {
        system("cls");
        PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
        CenterPrint(subtitle, 7);
        UserInfoCard();

        file_hand.close();
    }
    search_again = KeepDoing(20);
    if (search_again == 's')
        UserFinder();
}

void AskUserId(char search_id[])
{
    // TODO Document AskUserId

    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("BUSCAR UN USUARIO", 7);

    subsection = center * 1.13;

    gotoxy(subsection, 9);
    std::cout << "CEDULA   : ";
    AskData(search_id, 'n', 9);
}

int SearchById(char user_id[])
{
    // TODO Document SearchById

    file_hand.open(results_path.c_str(), ios::in);
    while (!file_hand.eof())
    {
        file_hand.read((char *)&Employee, sizeof(Data));
        if (strcmp(user_id, Employee.id_document) == 0)
            return 1;
    }
    file_hand.close();
    CenterPrint("Usuario no encontrado", 12);
    return 0;
}

/* ============================= Remove user functions ================================ */

void DeleteUser()
{
    char search_id[20];
}

int Deleter()
{
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

// void ArrowMoves(int position_x, int position_y)
// {
//     int key_pressed;

//     while (true)
//     {
//         key_pressed = getch();
//         if (key_pressed == 78)
//             gotoxy(position_x, position_y--);
//         else if (key_pressed == 80)
//             gotoxy(position_x, position_y++);
//     }

// }

int PageMove(int index)
{
    int key_pressed;
    int left_key = 75, right_key = 77, esc_key = 27;

    CenterPrint("Esc para volver al menu principal.", 25);
    CenterPrint("<- Cambiar de pagina ->", 26);
    CenterPrint("", 27);
    while (true)
    {
        key_pressed = getch();
        if (key_pressed == 0)
            key_pressed = getch();

        if (key_pressed == left_key)
        {
            if (index > 1)
                return -1;
            return 0;
        }
        else if (key_pressed == right_key)
            return 1;
        else if (key_pressed == esc_key)
            main();
    }
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
