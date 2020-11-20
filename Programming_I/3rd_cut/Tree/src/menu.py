from time import sleep
import curses


if __name__ == "__main__":
    print("Ejecutar el archivo main.py")
else:
    from src.curses_actions import *
    from src.exit_menu import exit_menu


def show_menu(stdscr, selected_row_idx, options):
    h, w = stdscr.getmaxyx()
    for idx, row in enumerate(options):
        x = w//2 - len(row)//2
        y = h//2 - len(options)//2 + idx
        if row == "Salir":
            y += 1
        if idx == selected_row_idx:
            stdscr.attron(curses.color_pair(1))
            stdscr.addstr(y, x, row)
            stdscr.attroff(curses.color_pair(1))
        else:
            stdscr.addstr(y, x, row)

    stdscr.refresh()


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
            if current_option == 2:
                exit_menu(stdscr)


def menu(stdscr):
    set_size(stdscr)
    curses.curs_set(0)
    curses.init_pair(1, curses.COLOR_BLACK, curses.COLOR_WHITE)

    main_menu(stdscr)


def main():
    curses.wrapper(menu)