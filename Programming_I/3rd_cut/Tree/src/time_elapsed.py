from time import time
from subprocess import call
from src.controllers.controllers import *
if OS == "Windows":
    from msvcrt import getche, getch
else:
    from getch import getche, getch


def main():
    clear()
    center_print("CALCULAR EL TIEMPO DE ESCRITURA.", 10)
    center_print("Escribe tu nombre: ", 13)
    print()

    if OS == "Windows":
        first = getche().decode("utf-8")
    else:
        first = getche()

    start = time()
    name = first
    name += input("")
    end = time()
    elapsed = round(end-start, 2)
    
    if elapsed > 20:
        color_time = color.RED
    elif elapsed > 10:
        color_time = color.YELLOW
    elif elapsed > 0:
        color_time = color.GREEN
    center_print(f"{color_time} Tiempo: {elapsed}s", 15)
    print(color.DEFAULT)
    
    getch()
    clear()


if __name__ == "__main__":
    main()