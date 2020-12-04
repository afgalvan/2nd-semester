#include <iostream>
#include <fstream>
#include <windows.h>

using std::ios;
std::fstream file_hand;

void FileAccess(std::string file_path);
std::string SplitPath(std::string folder_path);

int main()
{
    system("cls");
    std::string PATH = "C++_CARPETA\\OTRA_CARPETA\\FICHERO_DE_TEXTO.txt"; // Dirección relativa
    FileAccess(PATH);
    return 0;
}

void FileAccess(std::string file_path)
{
    std::string folder_path;
    std::string mkdir = "mkdir "; // Comando mkdir para crear directorios desde la terminal

    folder_path = SplitPath(file_path.c_str()); // Dividimos las carpetas del fichero de texto
    mkdir += folder_path; // Se agrega la cantidad de carpetas a crear

    file_hand.open(file_path.c_str(), ios::app); // Tratar de abrir el archivo
    if (file_hand.fail()) // Si no existe lo crea
    {
        system(mkdir.c_str()); // Ejecutar comando mkdir para crear las carprtas
        file_hand.open(file_path.c_str(), ios::out); // Crear el fichero de texto en la dirección indicada
        std::cout << "Directorio creado";
    }
    else
    {
        std::cout << "El directorio ya existe.";
    }
    
    file_hand.close();
}

std::string SplitPath(std::string folder_path)
{
    // Dividir una dirección de manera que separemos las carpetas del fichero de texto
    int i;
    std::string file;
    int len = folder_path.length() - 1; // El tamaño del string - 1 es la última posición

    for (i = len; folder_path[i] != '\\'; i--) // Recorrera string de manera inversa hasta
                                               // que encontremos un "\"
        file += folder_path[i]; // Agregar los caracteres que componen el nombre del fichero.

    file = std::string(file.rbegin(), file.rend()); // Invertirlo, ya que al acumularlo,
                                                    // lo recibimos de manera inversa.
    
    folder_path.replace(i, file.length() + 1, ""); // Remover el fichero de texto de la dirección
                                                   // para crear esas carpetas.

    return folder_path;
}
