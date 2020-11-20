from time import sleep
import curses


if __name__ == "__main__":
    print("Ejecutar el archivo main.py")
else:
    from src.curses_actions import *
    from src.menu_taller import show_points
    from src.credits import more_info
    from src.exit_menu import exit_menu


def main_menu(stdscr, current_option=0):
    h, w = stdscr.getmaxyx()
    stdscr.clear()
    options = ("Mostrar puntos del taller", "Más información", "Salir")


    while True:
        center_print(stdscr, "MENU", h//2 - 3)
        show_menu(stdscr, current_option, options)
        select, current_option = arrow_moves(stdscr, current_option, options,
                                             curses.KEY_UP, curses.KEY_DOWN)
        show_menu(stdscr, current_option, options)
        if select:
            if current_option == 0:
                show_points(stdscr)
            elif current_option == 1:
                more_info(stdscr)
            elif current_option == 2:
                exit_menu(stdscr)


def menu(stdscr):
    set_size(stdscr)
    curses.curs_set(0)
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_WHITE)

    main_menu(stdscr)


def main():
    curses.wrapper(menu)