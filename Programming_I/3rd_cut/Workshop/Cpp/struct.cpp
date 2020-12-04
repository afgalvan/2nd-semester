#include <iostream>
#include <string>
#include <fstream>
/* Librerías exclusivas de Windows OS. */
#include <conio.h>
#include <windows.h>

void FillStruct();
int AlingStruct(int size);
void LargestInColumn(int list[], int columns, int rows);
void DelimiterLines(int r, int columns, int lines[]);
void DownLines(int columns, int lines[]);
void TableHeaders();
int CountElements();
void DataTable(int elements, int position_y);
void DisplayStruct(int elements);
// Controllers
void SetWindow();
void gotoxy(SHORT x, SHORT y);
int CenterThis(std::string text);
void CenterPrint(std::string text, int position_y);
void PrintTitle(std::string title, int height);
int LongestWord(std::string words[], int len);

// Contexto importante de la ventana de la terminal.
int width, center, s_screen = 1, subsection, keys = 4;
char data_table[50][4][100];

std::fstream file_hand;
using std::ios;

struct Data
{
    char id_document[10];
    char name[50];
    char phone_number[11];
    char genre[1];
} Employee;

int main()
{
    TableHeaders();
    SetWindow();
    FillStruct();
    return 0;
}

void FillStruct()
{
    file_hand.open("data\\test\\worked.txt", ios::app);

    CenterPrint("Cedula  : ", 5);
    std::cin >> Employee.id_document;
    CenterPrint("Nombre  : ", 6);
    std::cin >> Employee.name;
    CenterPrint("Telefono: ", 7);
    std::cin >> Employee.phone_number;
    CenterPrint("Nro    : ", 8);
    std::cin >> Employee.genre;

    file_hand.write((char *)&Employee, sizeof(Data));
    file_hand.close();

    DisplayStruct(keys);
}

/* ============================= Table prompt functions ================================ */

int AlingStruct(int size)
{
    int i, all_characters = 0, table_width;

    for (i = 0; i < size; i++)
        all_characters += strlen(data_table[0][i]);
    table_width = all_characters + size + 1;

    return (width - table_width) / 2;
}

void LargestInColumn(int list[], int columns, int rows)
{
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

void TableHeaders()
{
    strcpy(data_table[0][0], "CEDULA");
    strcpy(data_table[0][1], "NOMBRE");
    strcpy(data_table[0][2], "TELEFONO");
    strcpy(data_table[0][3], "SEXO M/F");
}

int CountElements()
{
    file_hand.open("data\\test\\worked.txt", ios ::in);

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
    return rows-1;
}

void DataTable(int elements, int position_y)
{
    int rows = CountElements();
    int r, c;
    int a, l, lines[50];
    int i, blanks;
    int center_table = AlingStruct(keys);
    
    LargestInColumn(lines, keys, rows);

    for (r = 0, a = 0; r < rows; r++, a += 2)
    {
        gotoxy(center_table, position_y + a);
        DelimiterLines(r, keys, lines);

        

        gotoxy(center_table, position_y + 1 + a);
        std::cout << char(179);
        for (c = 0; c < keys; c++)
        {
            std::cout << data_table[r][c];
            blanks = lines[c] - strlen(data_table[r][c]);
            for (i = 0; i < blanks; i++)
                std::cout << " ";
            std::cout << char(179);
        }

        gotoxy(center_table, position_y + 2 + a);
        DownLines(keys, lines);
    }
}

void DisplayStruct(int elements)
{
    system("cls");
    PrintTitle("   UNIVERSIDAD POPULAR DEL CESAR   ", 4);
    CenterPrint("MOSTRA STRUCT EN UNA TABLA", 6);
    DataTable(elements, 8);
    CenterPrint("Presione cualquier tecla para continuar... ", 22);
    getch();
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
    // SetConsoleTitle("UNIVERSIDAD POPULAR DEL CESAR");
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