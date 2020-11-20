if __name__ == "__main__":
    print("Ejecutar el archivo main.py")
else:
    from src.curses_actions import *
    from src.time_elapsed import main

def show_points(stdscr, current_option=0):
    h, w = stdscr.getmaxyx()
    stdscr.clear()
    options = ("Calcular el tiempo", "Punto 2", "Punto 3",
               "Punto 4", "Punto 5", "Volver al menú")


    while True:
        center_print(stdscr, "PUNTOS DEL TALLER", h//2 - len(options))
        show_menu(stdscr, current_option, options)
        select, current_option = arrow_moves(stdscr, current_option, options,
                                             curses.KEY_UP, curses.KEY_DOWN)
        show_menu(stdscr, current_option, options)
        if select:
            if current_option == 0:
                curses.curs_set(1)
                main()
            if current_option == len(options)-1:
                stdscr.clear()
                break