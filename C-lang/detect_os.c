#if defined(_WIN32) || defined(WIN32) || defined(_NT)
    #define clean "cls"
    #define OS "Windows"
#elif linux
    #define clean "clear"
    #define OS "Linux"
#else
    #define clean "clear"
    #define OS "Desconocido"
#endif

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system(clean);
    printf("Sistema operativo: %s\n", OS);
    getchar();
    return 0;
}
