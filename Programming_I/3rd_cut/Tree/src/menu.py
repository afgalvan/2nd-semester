from time import sleep
import curses


if __name__ == "__main__":
    print("Ejecutar el archivo main.py")
else:
    from src.curses_actions import *
    from src.menu_taller import show_points
    from src.credits import more_info
    from src.exit_menu import exit_menu


def main_menu(stdscr, current_option):
    options = ("Mostrar puntos del taller", "Más información", "Salir")

    current_option = menu_displayer(stdscr, options, "MENU", current_option)
    if current_option == 0:
        show_points(stdscr, 0)
    elif current_option == 1:
        more_info(stdscr, 0)
    else:
        exit_menu(stdscr)
    main_menu(stdscr, current_option)


def menu(stdscr):
    set_size(stdscr)
    curses.curs_set(0)
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_WHITE)

    main_menu(stdscr, 0)


def main():
    curses.wrapper(menu)
