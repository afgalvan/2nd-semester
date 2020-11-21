if __name__ == "__main__":
    print("Ejecutar el archivo main.py")
else:
    from src.curses_actions import *
    from src.time_elapsed import main

def show_points(stdscr, current_option):
    options = ("Calcular el tiempo", "Punto 2", "Punto 3",
               "Punto 4", "Punto 5", "Volver al menú")

    current_option = menu_displayer(stdscr, options, "PUNTOS DEL TALLER", current_option)
    if current_option == 0:
        curses.curs_set(1)
        main()
    elif current_option == len(options)-1:
        stdscr.clear()
        return 0
    show_points(stdscr, current_option)